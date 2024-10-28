// File: main.cpp
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
}