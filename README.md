
# MHLoader

Download's and Updates files from Github repo as Loader with use of ImGui.

**Please note that you'll need to set up your development environment, install libraries, and handle error checking and user interface design to create a fully functional application.**


## Features
This repository provides a C++ application that leverages the ImGui library for creating a simple graphical user interface (GUI). The application's main features include:

- Downloading and updating files from a specified GitHub repository.
- Displaying a progress bar to track download progress.
- Showing a description of the download process.
- Offering a button to open a web browser with a provided URL.
This code serves as a basic starting point for creating an application that interacts with GitHub APIs, displays download progress, and opens web browsers. Developers can use and expand upon this code to build more advanced applications with additional features and user interface improvements.

## Note
This repository provides a C++ application that leverages the ImGui library for creating a simple graphical user interface (GUI). The application's main features include:

- The code in this repository uses the ImGui library for GUI development.
- It also utilizes the cURL library for making HTTP requests to GitHub.
- Further customization and error handling are required for a complete, production-ready application.
- It provides a foundation for integrating GitHub interactions, progress tracking, and web browser launching into a C++ project.


## In this code
- It uses the ImGui library for creating a basic GUI.
- The cURL library is utilized for making HTTP requests to your GitHub repository's latest release.
- The `DownloadProgress` struct is used to store the progress information.
- The "`Download Latest Version`" button triggers the cURL request to your GitHub repository and updates the progress and description.
- The "`Open Browser`" button placeholder is left for you to implement opening the web browser with the URL.
  
  *This code provides a starting point. You will need to further develop and customize it according to your specific needs and preferences. Make sure to install and configure the necessary libraries and handle errors, authentication, and actual file downloading as needed for your GitHub repository.*

**Created by Madam-Herta**
