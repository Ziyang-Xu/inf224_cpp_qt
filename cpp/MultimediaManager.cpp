/**
 * @file MultimediaManager.cpp
 * @brief Implementation of the MultimediaManager class.
 */
#include "MultimediaManager.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include "MultimediaException.h"
#include <fstream>
#include <iostream>
#include <regex>

/**
 * @brief Creates a photo and adds it to the manager.
 * @param name The name of the photo.
 * @param path The file path of the photo.
 * @param latitude The latitude where the photo was taken.
 * @param longitude The longitude where the photo was taken.
 */
void MultimediaManager::createPhoto(const std::string& name, const std::string& path, double latitude, double longitude) {
    if (multimediaMap.find(name) != multimediaMap.end()) {
        throw DuplicateNameException("Photo with name '" + name + "' already exists.");
    }
    if (!isValidName(name)) {
        throw InvalidNameException("Invalid name: '" + name + "'.");
    }
    multimediaMap[name] = std::make_shared<Photo>(name, path, latitude, longitude);
}

/**
 * @brief Creates a video and adds it to the manager.
 * @param name The name of the video.
 * @param path The file path of the video.
 * @param duration The duration of the video in seconds.
 */
void MultimediaManager::createVideo(const std::string& name, const std::string& path, int duration) {
    if (multimediaMap.find(name) != multimediaMap.end()) {
        throw DuplicateNameException("Video with name '" + name + "' already exists.");
    }
    if (!isValidName(name)) {
        throw InvalidNameException("Invalid name: '" + name + "'.");
    }
    multimediaMap[name] = std::make_shared<Video>(name, path, duration);
}

/**
 * @brief Creates a film and adds it to the manager.
 * @param name The name of the film.
 * @param path The file path of the film.
 * @param duration The duration of the film in seconds.
 * @param chapters The chapters of the film.
 */
void MultimediaManager::createFilm(const std::string& name, const std::string& path, int duration, const std::vector<int>& chapters) {
    if (multimediaMap.find(name) != multimediaMap.end()) {
        throw DuplicateNameException("Film with name '" + name + "' already exists.");
    }
    if (!isValidName(name)) {
        throw InvalidNameException("Invalid name: '" + name + "'.");
    }
    if (chapters.empty()) {
        throw InvalidDurationException("Film must have at least one chapter.");
    }
    multimediaMap[name] = std::make_shared<Film>(name, path, duration, chapters);
}

/**
 * @brief Creates a group and adds it to the manager.
 * @param name The name of the group.
 */
void MultimediaManager::createGroup(const std::string& name) {
    if (groupMap.find(name) != groupMap.end()) {
        throw DuplicateNameException("Group with name '" + name + "' already exists.");
    }
    if (!isValidName(name)) {
        throw InvalidNameException("Invalid name: '" + name + "'.");
    }
    groupMap[name] = std::make_shared<Group>(name);
}

/**
 * @brief Displays multimedia information.
 * @param name The name of the multimedia.
 */
void MultimediaManager::displayMultimedia(const std::string& name) const {
    auto it = multimediaMap.find(name);
    if (it == multimediaMap.end()) {
        throw NotFoundException("Multimedia not found: '" + name + "'.");
    }
    it->second->display(std::cout);
}

/**
 * @brief Displays group information.
 * @param name The name of the group.
 */
void MultimediaManager::displayGroup(const std::string& name) const {
    auto it = groupMap.find(name);
    if (it == groupMap.end()) {
        throw NotFoundException("Group not found: '" + name + "'.");
    }
    it->second->display(std::cout);
}

/**
 * @brief Plays multimedia.
 * @param name The name of the multimedia.
 */
void MultimediaManager::playMultimedia(const std::string& name) const {
    auto it = multimediaMap.find(name);
    if (it == multimediaMap.end()) {
        throw NotFoundException("Multimedia not found: '" + name + "'.");
    }
    it->second->play();
}

/**
 * @brief Checks if a name is valid.
 * @param name The name to check.
 * @return True if the name is valid, false otherwise.
 */
bool MultimediaManager::isValidName(const std::string& name) const {
    std::regex namePattern("^[a-zA-Z0-9_\\-]+$");
    return std::regex_match(name, namePattern);
}

/**
 * @brief Loads multimedia objects from a file.
 * @param filename The name of the file to load from.
 */
void MultimediaManager::load(const std::string& filename) {
    std::ifstream ifs(filename);
    if (!ifs) {
        std::cerr << "Could not open file for reading: " << filename << std::endl;
        return;
    }
    std::string className;
    while (std::getline(ifs, className)) {
        std::shared_ptr<Multimedia> multimedia;
        if (className == "Photo") {
            multimedia = std::make_shared<Photo>("", "", 0.0, 0.0);
        } else if (className == "Video") {
            multimedia = std::make_shared<Video>("", "", 0);
        } else if (className == "Film") {
            multimedia = std::make_shared<Film>("", "", 0, std::vector<int>());
        }
        if (multimedia) {
            ifs >> *multimedia;
            multimediaMap[multimedia->getName()] = multimedia;
        }
    }
    ifs.close();
}

/**
 * @brief Saves multimedia objects to a file.
 * @param filename The name of the file to save to.
 */
void MultimediaManager::save(const std::string& filename) const {
    std::ofstream ofs(filename);
    if (!ofs) {
        std::cerr << "Could not open file for writing: " << filename << std::endl;
        return;
    }
    for (const auto& pair : multimediaMap) {
        ofs << *pair.second;
    }
    ofs.close();
}