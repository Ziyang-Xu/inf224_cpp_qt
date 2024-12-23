/**
 * @file server.cpp
 * @brief Main server application that handles multimedia requests.
 */
#include <iostream>
#include <sstream>
#include <string>
#include <memory>
#include "MultimediaManager.h"
#include "ccsocket.h"
#include "tcpserver.h"

#define PORT 3333

/**
 * @brief Processes a request from the client.
 * @param request The request string from the client.
 * @param manager The multimedia manager to handle the request.
 * @param response The response string to be sent back to the client.
 */
void processRequest(const std::string &request, MultimediaManager &manager, std::string &response) {
  std::istringstream iss(request);
  std::string command;
  iss >> command;

  if (command == "search") {
    std::string type, name;
    iss >> type >> name;
    std::ostringstream oss;
    if (type == "multimedia") {
      manager.displayMultimedia(name);
    } else if (type == "group") {
      manager.displayGroup(name);
    } else {
      oss << "Unknown type: " << type;
    }
    response = oss.str();
  } else if (command == "play") {
    std::string name;
    iss >> name;
    manager.playMultimedia(name);
    response = "Playing multimedia: " + name;
  } else {
    response = "Unknown command: " + command;
  }
}

/**
 * @brief Main function to run the server.
 * @return Exit status.
 */
int main() {
  MultimediaManager manager;
  // Add some multimedia objects and groups to the manager for testing
  manager.createPhoto("photo", "./sample_photo.jpg", 48.858844, 2.294351);
  manager.createVideo("video", "./sample_video.mp4", 120);
  manager.createFilm("film", "./sample_film.mp4", 90, {10, 20, 30});
  manager.createGroup("group1");

  TCPServer server([&manager](std::string const &request, std::string &response) {
      processRequest(request, manager, response);
      return true;
  });

  server.run(PORT);

  return 0;
}