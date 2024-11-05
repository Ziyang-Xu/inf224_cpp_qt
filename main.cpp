/*// File: main.cpp
#include "MultimediaManager.h"
#include "MultimediaException.h"
#include <iostream>

int main() {
    MultimediaManager manager;
    try {
        manager.createPhoto("photo", "../sample_photo.jpg", 48.858844, 2.294351);
        manager.createPhoto("photo", "../sample_photo.jpg", 48.858844, 2.294351); // Should throw DuplicateNameException
    } catch (const MultimediaException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        manager.createGroup("group1");
        manager.createGroup("group1"); // Should throw DuplicateNameException
    } catch (const MultimediaException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        manager.displayMultimedia("nonexistent"); // Should throw NotFoundException
    } catch (const MultimediaException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}*/
#include "MultimediaManager.h"

int main() {
    MultimediaManager manager;
    manager.createPhoto("photo", "../sample_photo.jpg", 48.858844, 2.294351);
    manager.createVideo("video", "../sample_video.mp4", 120);
    manager.createFilm("film", "../sample_film.mp4", 90, {10, 20, 30});

    manager.save("multimedia.txt");

    MultimediaManager loadedManager;
    loadedManager.load("multimedia.txt");

    loadedManager.displayMultimedia("photo");
    loadedManager.displayMultimedia("video");
    loadedManager.displayMultimedia("film");

    return 0;
}