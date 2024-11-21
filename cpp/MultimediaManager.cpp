// File: MultimediaManager.cpp
#include "MultimediaManager.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include "MultimediaException.h"
#include <fstream>
#include <iostream>
#include <regex>

void MultimediaManager::createPhoto(const std::string& name, const std::string& path, double latitude, double longitude) {
    if (multimediaMap.find(name) != multimediaMap.end()) {
        throw DuplicateNameException("Photo with name '" + name + "' already exists.");
    }
    if (!isValidName(name)) {
        throw InvalidNameException("Invalid name: '" + name + "'.");
    }
    multimediaMap[name] = std::make_shared<Photo>(name, path, latitude, longitude);
}

void MultimediaManager::createVideo(const std::string& name, const std::string& path, int duration) {
    if (multimediaMap.find(name) != multimediaMap.end()) {
        throw DuplicateNameException("Video with name '" + name + "' already exists.");
    }
    if (!isValidName(name)) {
        throw InvalidNameException("Invalid name: '" + name + "'.");
    }
    multimediaMap[name] = std::make_shared<Video>(name, path, duration);
}

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

void MultimediaManager::createGroup(const std::string& name) {
    if (groupMap.find(name) != groupMap.end()) {
        throw DuplicateNameException("Group with name '" + name + "' already exists.");
    }
    if (!isValidName(name)) {
        throw InvalidNameException("Invalid name: '" + name + "'.");
    }
    groupMap[name] = std::make_shared<Group>(name);
}

void MultimediaManager::displayMultimedia(const std::string& name) const {
    auto it = multimediaMap.find(name);
    if (it == multimediaMap.end()) {
        throw NotFoundException("Multimedia not found: '" + name + "'.");
    }
    it->second->display(std::cout);
}

void MultimediaManager::displayGroup(const std::string& name) const {
    auto it = groupMap.find(name);
    if (it == groupMap.end()) {
        throw NotFoundException("Group not found: '" + name + "'.");
    }
    it->second->display(std::cout);
}

void MultimediaManager::playMultimedia(const std::string& name) const {
    auto it = multimediaMap.find(name);
    if (it == multimediaMap.end()) {
        throw NotFoundException("Multimedia not found: '" + name + "'.");
    }
    it->second->play();
}

bool MultimediaManager::isValidName(const std::string& name) const {
    std::regex namePattern("^[a-zA-Z0-9_\\-]+$");
    return std::regex_match(name, namePattern);
}
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