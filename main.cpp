#include <cpr/cpr.h>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <vector>

std::string BEARER_TOKEN = "AAAAAAAAAAAAAAAAAAAAAKNhLAEAAAAAzItOgprPgVhFZIc6JjgD74tIu34%3D4OlxvtQhLZ9p2E5kblp79f6rOOx33L0SZivMJm8prJpTvh5qRC";
std::vector<int> RULE_IDS;


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

	if (item.contains("errors")) {
		std::string error = "Rule(s) not accepted. Errors: " + item["errors"].dump();
		throw error;
		return false;
	}

	if (r.status_code != 201) {
		std::string error = "HTTP Error Code: " + r.status_code;
		throw error;
		return false;
	}

	std::vector<int> ids_local;
	for (const auto& rule : item["data"]) {
		ids_local.push_back(rule["id"]);
	}

	std::cout << "Rules Added: " << r.text << std::endl;

	return true;
}

int main()
{
	try {
		std::string rule = "#breakingnews lang:en -died -death -deaths -kill -killed -killing -killings -shooting -shootings -shot -stabbing -stabbed -fatalities -burned -crash -crashed -rape -raped -sexual -casualties -assault -assaulted -is:retweet";
		std::string tag = "english, non-retweet breaking news without dangerous words";
		makeRule(rule, tag);
	} catch (std::string error) {
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

	//cpr::Response r3 = cpr::Get(cpr::Url{ "https://api.twitter.com/2/tweets/search/stream/rules" },
	//	cpr::Header{ { "Authorization", "Bearer " + BEARER_TOKEN } });

	//std::cout << "Rules:" << r3.text << std::endl;

	//auto future_text = cpr::GetCallback([](cpr::Response r) {
	//	return r.text;
	//	}, cpr::Url{ "https://api.twitter.com/2/tweets/search/stream" },
	//		cpr::Header{ { "Authorization", "Bearer " + BEARER_TOKEN } });
	//// Sometime later
	//if (future_text.wait_for(std::chrono::seconds(1000)) == std::future_status::ready) {
	//	std::cout << future_text.get() << std::endl;
	//};
	

	//cpr::Response r4 = cpr::Post(cpr::Url{ "https://api.twitter.com/2/tweets/search/stream/rules" },
	//cpr::Payload{ {"dry_run", "false"} },
	//cpr::Header{ { "Content-Type", "application/json" },
	//	{ "Authorization", "Bearer " + BEARER_TOKEN } },
	//cpr::Body{ R"({
	//	"delete": {
	//		"ids": ["1346917846127882241"]
	//		}
	//	})"
	//});

	//std::cout << "Rules Deleted:" << r4.text << std::endl;

	return 0;
}