#include <iostream>
#include <string>
#include <vector>
#include <curl/curl.h>
#include <imgui.h>
#include <imgui-SFML.h>
#include <SFML/Graphics.hpp>


// Made by Madam-Herta: https://github.com/Madam-Herta
// Updates at: https://github.com/Madam-Herta/MHLoader
// UnknownCheats: https://www.unknowncheats.me/forum/members/3964903.html


// Define your GitHub repository URL
const std::string GitHubRepoURL = "https://api.github.com/repos/YourUsername/YourRepo/releases/latest";

// Struct to store download progress
struct DownloadProgress {
    double percentage;
    std::string description;
};

// Callback function for cURL to track download progress
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    DownloadProgress* progress = static_cast<DownloadProgress*>(userp);
    size_t totalSize = size * nmemb;
    // Update progress information here
    return totalSize;
}

int main() {
    // Initialize ImGui and create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "GitHub Downloader");

    ImGui::SFML::Init(window);

    // Initialize cURL
    CURL* curl = curl_easy_init();
    if (!curl) {
        std::cerr << "cURL initialization failed." << std::endl;
        return 1;
    }

    DownloadProgress progress;
    std::vector<char> receivedData;  // Store the downloaded data

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed)
                window.close();
        }

        ImGui::SFML::Update(window, sf::Time());

        ImGui::Begin("GitHub Downloader");

        if (ImGui::Button("Download Latest Version")) {
            // Make a cURL request to your GitHub repository URL
            curl_easy_setopt(curl, CURLOPT_URL, GitHubRepoURL.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &receivedData);

            CURLcode res = curl_easy_perform(curl);

            if (res == CURLE_OK) {
                // Process receivedData (GitHub release information) here
                // Update the progress struct and store downloaded files
                progress.description = "Download Complete!";
            } else {
                progress.description = "Download Failed!";
            }
        }

        ImGui::Text("Progress: %.2f%%", progress.percentage);
        ImGui::Text("Description: %s", progress.description.c_str());

        if (ImGui::Button("Open Browser")) {
            // Implement code to open the default web browser with your desired URL
            // Use platform-specific methods for this
        }

        ImGui::End();

        window.clear();
        ImGui::Render();
        window.display();
    }

    ImGui::SFML::Shutdown();
    curl_easy_cleanup(curl);

    return 0;
}
