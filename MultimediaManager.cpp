#include "MultimediaManager.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include <fstream>
#include <iostream>

void MultimediaManager::createPhoto(const std::string& name, const std::string& path, double latitude, double longitude) {
    multimediaMap[name] = std::make_shared<Photo>(name, path, latitude, longitude);
}

void MultimediaManager::createVideo(const std::string& name, const std::string& path, int duration) {
    multimediaMap[name] = std::make_shared<Video>(name, path, duration);
}

void MultimediaManager::createFilm(const std::string& name, const std::string& path, int duration, const std::vector<int>& chapters) {
    multimediaMap[name] = std::make_shared<Film>(name, path, duration, chapters);
}

void MultimediaManager::createGroup(const std::string& name) {
    groupMap[name] = std::make_shared<Group>(name);
}

void MultimediaManager::displayMultimedia(const std::string& name) const {
    auto it = multimediaMap.find(name);
    if (it != multimediaMap.end()) {
        it->second->display(std::cout);
    } else {
        std::cout << "Multimedia not found: " << name << std::endl;
    }
}

void MultimediaManager::displayGroup(const std::string& name) const {
    auto it = groupMap.find(name);
    if (it != groupMap.end()) {
        it->second->display(std::cout);
    } else {
        std::cout << "Group not found: " << name << std::endl;
    }
}

void MultimediaManager::playMultimedia(const std::string& name) const {
    auto it = multimediaMap.find(name);
    if (it != multimediaMap.end()) {
        it->second->play();
    } else {
        std::cout << "Multimedia not found: " << name << std::endl;
    }
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