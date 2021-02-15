<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Thanks again! Now go create something AMAZING! :D
***
***
***
*** To avoid retyping too much info. Do a search and replace for the following:
*** github_username, repo_name, twitter_handle, email, project_title, project_description
-->



<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]



<!-- PROJECT LOGO -->
<br />
<p align="center">
  <a href="https://github.com/Paristha/HaikuReporter">
    <img src="images/logo.png" alt="Logo" width="80" height="80">
  </a>

  <h3 align="center">project_title</h3>

  <p align="center">
    project_description
    <br />
    <a href="https://github.com/github_username/repo_name"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/github_username/repo_name">View Demo</a>
    ·
    <a href="https://github.com/github_username/repo_name/issues">Report Bug</a>
    ·
    <a href="https://github.com/github_username/repo_name/issues">Request Feature</a>
  </p>
</p>



<!-- TABLE OF CONTENTS -->
## Table of Contents

* [About the Project](#about-the-project)
  * [Built With](#built-with)
* [Getting Started](#getting-started)
  * [Prerequisites](#prerequisites)
  * [Installation](#installation)
* [Usage](#usage)
* [Roadmap](#roadmap)
* [Contributing](#contributing)
* [License](#license)
* [Contact](#contact)
<!-- * [Acknowledgements](#acknowledgements) -->



<!-- ABOUT THE PROJECT -->
## About The Project

<!-- [![Product Name Screen Shot][product-screenshot]](https://example.com) -->

A fun twitter bot reporting all the news fit to Haiku.


### Built With

* [cpr](https://github.com/whoshuu/cpr)
* [nlohmann/json](https://github.com/nlohmann/json)
* -- [CMake target for nlohmann/json](https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent)


<!-- GETTING STARTED -->
## Getting Started

To get a local copy up and running follow these simple steps.

### Prerequisites



### Installation

1. Clone the repo
   ```sh
   git clone https://github.com/Paristha/HaikuReporter.git
   ```
2. CMake
   ```sh

   ```



<!-- USAGE EXAMPLES -->
## Usage

Haiku Reporter makes use of Twitter's Dev APIs to filter a stream of new news tweets, searching for tweets that could be formatted to meet the 5-7-5 syllable requirement of the lines of a 'Haiku' poem.

It is currently under construction! Current functionality includes: using [cpr](https://github.com/whoshuu/cpr) to create and delete rules for Twitter's (filtered stream API)[https://developer.twitter.com/en/docs/twitter-api/tweets/filtered-stream/introduction]. Integration with a python module that makes use of the (nltk API)[https://www.nltk.org/] to recognize haikus.


<!-- ROADMAP -->
## Roadmap

-Complete integration with python HaikuRecognizer module
-Add ability to post recognized Haikus with bot twitter account

Feel free to email me suggestions!

See the [open issues](https://github.com/Paristha/HaikuReporter/issues) for a list of proposed features (and known issues).



<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are **greatly appreciated**.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request



<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE` for more information.



<!-- CONTACT -->
## Contact

Email: raphaelparisdi@gmail.com
Project Link: [https://github.com/github_username/repo_name](https://github.com/Paristha/HaikuReporter)



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/Paristha/HaikuReporter.svg?style=for-the-badge
[contributors-url]: https://github.com/Paristha/HaikuReporter/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/Paristha/HaikuReporter.svg?style=for-the-badge
[forks-url]: https://github.com/Paristha/HaikuReporter/network/members
[stars-shield]: https://img.shields.io/github/stars/Paristha/HaikuReporter.svg?style=for-the-badge
[stars-url]: https://github.com/Paristha/HaikuReporter/stargazers
[issues-shield]: https://img.shields.io/github/issues/Paristha/HaikuReporter.svg?style=for-the-badge
[issues-url]: https://github.com/Paristha/HaikuReporter/issues
[license-shield]: https://img.shields.io/github/license/Paristha/HaikuReporter.svg?style=for-the-badge
[license-url]: https://github.com/Paristha/HaikuReporter/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/thanaParis
<!-- [product-screenshot]: https://github.com/Paristha/HaikuReporter/images/screenshot.png -->
