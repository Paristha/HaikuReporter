#include <cpr/cpr.h>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <vector>

std::string BEARER_TOKEN = "AAAAAAAAAAAAAAAAAAAAAKNhLAEAAAAAzItOgprPgVhFZIc6JjgD74tIu34%3D4OlxvtQhLZ9p2E5kblp79f6rOOx33L0SZivMJm8prJpTvh5qRC";
std::vector<std::string> RULE_IDS;


bool makeRule(std::string value_text, std::string tag_text = "") 
{
	std::string json_body = R"({ "add": [ {"value": ")";
	json_body += value_text;
	json_body += R"(", "tag": ")";
	json_body += tag_text;
	json_body += R"("} ] })";
	cpr::Response r = cpr::Post(cpr::Url{ "https://api.twitter.com/2/tweets/search/stream/rules" },
		cpr::Payload{ {"dry_run", "false"} },
		cpr::Header{ { "Content-Type", "application/json" },
			{ "Authorization", "Bearer " + BEARER_TOKEN } },
		cpr::Body{ json_body });

	nlohmann::json item = nlohmann::json::parse(r.text);

	if (item.contains("errors") || r.status_code != 201) {
		std::string error = "";

		if (item.contains("errors")) {
			for (const auto& rule : item["errors"]) {
				RULE_IDS.push_back(rule["id"].dump());
			}
			error += "Rule(s) not accepted. Errors: " + item["errors"].dump() + "\n";
		}

		if (r.status_code != 201)
			error += "HTTP Error Code: " + std::to_string(r.status_code);

		std::cerr << error << std::endl;
		return false;
	}

	for (const auto& rule : item["data"]) {
		std::string rule_id = rule["id"].dump();
		std::cout << "Rule successfully created with id " + rule_id << std::endl;
		RULE_IDS.push_back(rule_id);
	}

	return true;
}

bool getRuleIDs() {
	cpr::Response r = cpr::Get(cpr::Url{ "https://api.twitter.com/2/tweets/search/stream/rules" },
		cpr::Header{ { "Authorization", "Bearer " + BEARER_TOKEN } });

	nlohmann::json item = nlohmann::json::parse(r.text);

	if (r.status_code != 200) {
		std::cerr << "HTTP Error Code: " + std::to_string(r.status_code) << std::endl;
		return false;
	}

	std::cout << "Success! Rule IDs: ";
	std::vector<std::string> new_rule_ids;
	for (const auto& rule : item["data"]) {
		std::string rule_id = rule["id"].dump();
		std::cout << rule_id << ", ";
		new_rule_ids.push_back(rule_id);
	}
	std::cout << std::endl;
	RULE_IDS = new_rule_ids;

	return true;
}

bool deleteRules(std::vector<std::string> ids2delete) {
	if (ids2delete.empty())
		return true;
	int num_rules2delete = ids2delete.size();
	std::string json_body = R"({ "delete": { "ids": [)";
	json_body += ids2delete.back();
	ids2delete.pop_back();
	if (!ids2delete.empty()) {
		for (std::vector<std::string>::const_iterator i = ids2delete.begin(); i != ids2delete.end(); ++i) {
			json_body += ", ";
			json_body += *i;
		}
	}
	json_body += "] } }";
	std::cout << json_body << std::endl;
	cpr::Response r = cpr::Post(cpr::Url{ "https://api.twitter.com/2/tweets/search/stream/rules" },
		cpr::Payload{ {"dry_run", "false"} },
		cpr::Header{ { "Content-Type", "application/json" },
			{ "Authorization", "Bearer " + BEARER_TOKEN } },
		cpr::Body{ json_body });

	nlohmann::json item = nlohmann::json::parse(r.text);

	int num_rules_deleted = 0;
	try {
		num_rules_deleted = item["meta"]["summary"]["deleted"];
	}
	catch (nlohmann::json::exception exc) {
		std::cerr << exc.what() << std::endl;
		if (r.status_code != 200)
			std::cerr << "HTTP Error Code: " + std::to_string(r.status_code) << std::endl;
		return false;
	}

	if (num_rules2delete == num_rules_deleted) {
		std::cout << item["meta"]["summary"]["deleted"].dump() + " rules successfully deleted" << std::endl;
		return true;
	}
	else {
		std::cout << num_rules2delete - num_rules_deleted << " rules  not deleted" << std::endl;
		if (r.status_code != 200) 
			std::cerr << "HTTP Error Code: " + std::to_string(r.status_code) << std::endl;
		return false;
	}
}

int main()
{
	try {
		std::string rule = "#breakingnews lang:en -died -death -deaths -kill -killed -killing -killings -shooting -shootings -shot -stabbing -stabbed -fatalities -burned -crash -crashed -rape -raped -sexual -casualties -assault -assaulted -is:retweet";
		std::string tag = "english, non-retweet breaking news without dangerous words";
		makeRule(rule, tag);
		//for (std::vector<std::string>::const_iterator i = RULE_IDS.begin(); i != RULE_IDS.end(); ++i)
		//	std::cout << *i << ' ';
	} catch (std::string error) {
		std::cout << error << std::endl;
		std::cout << "\nError ids: ";
		for (std::vector<std::string>::const_iterator i = RULE_IDS.begin(); i != RULE_IDS.end(); ++i)
			std::cout << *i << ", ";
		std::cout << std::endl;
	}

	try {
		bool func_success = getRuleIDs();
		if (func_success) {
			std::cout << "Success! Rule IDs: ";
			for (std::vector<std::string>::const_iterator i = RULE_IDS.begin(); i != RULE_IDS.end(); ++i)
				std::cout << *i << ", ";
			std::cout << std::endl;
		}
	}
	catch (std::string error) {
		std::cout << error << std::endl;
	}

	try {
		bool func_success = deleteRules(RULE_IDS);
	}
	catch (std::string error) {
		std::cout << error << std::endl;
	}
	//std::cout << "Rules Added:" << r1.text << std::endl;

	//cpr::Response r2 = cpr::Get(cpr::Url{ "https://api.twitter.com/2/tweets/search/stream" },
	//	cpr::Header{ { "Authorization", "Bearer " + BEARER_TOKEN } },
	//	cpr::Timeout{5000});

	//std::ofstream fileEndpoint;
	//fileEndpoint.open("tweets.txt");
	//fileEndpoint << "Tweets Returned:" << r2.text;
	//fileEndpoint.close();

	//std::cout << "Code:" << r2.status_code << std::endl;

	//std::cout << "Tweets:" << r2.text << std::endl;

	//std::cout << "Bytes:" << r2.downloaded_bytes << std::endl;

	//auto future_text = cpr::GetCallback([](cpr::Response r) {
	//	return r.text;
	//	}, cpr::Url{ "https://api.twitter.com/2/tweets/search/stream" },
	//		cpr::Header{ { "Authorization", "Bearer " + BEARER_TOKEN } });
	//// Sometime later
	//if (future_text.wait_for(std::chrono::seconds(1000)) == std::future_status::ready) {
	//	std::cout << future_text.get() << std::endl;
	//};
	



	return 0;
}