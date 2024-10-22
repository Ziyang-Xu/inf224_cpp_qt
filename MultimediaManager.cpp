#include "MultimediaManager.h"
#include <iostream>

std::shared_ptr<Photo> MultimediaManager::createPhoto(const std::string &name, const std::string &filePath, double latitude, double longitude) {
    auto photo = std::make_shared<Photo>(name, filePath, latitude, longitude);
    multimediaTable[name] = photo;
    return photo;
}

std::shared_ptr<Video> MultimediaManager::createVideo(const std::string &name, const std::string &filePath, int duration) {
    auto video = std::make_shared<Video>(name, filePath, duration);
    multimediaTable[name] = video;
    return video;
}

std::shared_ptr<Film> MultimediaManager::createFilm(const std::string &name, const std::string &filePath, int duration, const std::vector<int> &chapters) {
    auto film = std::make_shared<Film>(name, filePath, duration, chapters);
    multimediaTable[name] = film;
    return film;
}

std::shared_ptr<Group> MultimediaManager::createGroup(const std::string &name) {
    auto group = std::make_shared<Group>(name);
    groupTable[name] = group;
    return group;
}

void MultimediaManager::displayMultimedia(const std::string &name) const {
    auto it = multimediaTable.find(name);
    if (it != multimediaTable.end()) {
        it->second->display(std::cout);
    } else {
        std::cout << "Multimedia object not found: " << name << std::endl;
    }
}

void MultimediaManager::displayGroup(const std::string &name) const {
    auto it = groupTable.find(name);
    if (it != groupTable.end()) {
        it->second->display(std::cout);
    } else {
        std::cout << "Group not found: " << name << std::endl;
    }
}

void MultimediaManager::playMultimedia(const std::string &name) const {
    auto it = multimediaTable.find(name);
    if (it != multimediaTable.end()) {
        it->second->play();
    } else {
        std::cout << "Multimedia object not found: " << name << std::endl;
    }
}

void MultimediaManager::deleteMultimedia(const std::string &name) {
    auto it = multimediaTable.find(name);
    if (it != multimediaTable.end()) {
        for (auto &groupPair : groupTable) {
            groupPair.second->remove(it->second);
        }
        multimediaTable.erase(it);
    } else {
        std::cout << "Multimedia object not found: " << name << std::endl;
    }
}

void MultimediaManager::deleteGroup(const std::string &name) {
    auto it = groupTable.find(name);
    if (it != groupTable.end()) {
        groupTable.erase(it);
    } else {
        std::cout << "Group not found: " << name << std::endl;
    }
}//
// Created by Chaleur on 22/10/2024.
//
