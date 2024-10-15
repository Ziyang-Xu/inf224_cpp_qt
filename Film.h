#ifndef FILM_H
#define FILM_H

#include "Video.h"
#include <iostream>

class Film : public Video {
private:
    int* chapters;
    int numChapters;

    // Helper function to copy chapters array
    void copyChapters(const int* chaptersArray, int size) {
        if (chapters) {
            delete[] chapters;
        }
        if (size > 0) {
            chapters = new int[size];
            for (int i = 0; i < size; ++i) {
                chapters[i] = chaptersArray[i];
            }
        } else {
            chapters = nullptr;
        }
        numChapters = size;
    }

public:
    // Default constructor
    Film() : Video(), chapters(nullptr), numChapters(0) {}

    // Parameterized constructor
    Film(const std::string& name, const std::string& filePath, int duration, const int* chaptersArray = nullptr, int size = 0)
        : Video(name, filePath, duration), chapters(nullptr), numChapters(0) {
        copyChapters(chaptersArray, size);
    }

    // Copy constructor
    Film(const Film& other) : Video(other), chapters(nullptr), numChapters(0) {
        copyChapters(other.chapters, other.numChapters);
    }

    // Copy assignment operator
    Film& operator=(const Film& other) {
        if (this != &other) {
            Video::operator=(other);
            copyChapters(other.chapters, other.numChapters);
        }
        return *this;
    }

    // Destructor
    ~Film() {
        delete[] chapters;
    }

    // Modifier to set chapters
    void setChapters(const int* chaptersArray, int size) {
        copyChapters(chaptersArray, size);
    }

    // Accessor to get chapters
    const int* getChapters() const {
        return chapters;
    }

    // Accessor to get number of chapters
    int getNumChapters() const {
        return numChapters;
    }

    // Display method
    void display(std::ostream& os) const override {
        Video::display(os);
        os << "Chapters durations: ";
        for (int i = 0; i < numChapters; ++i) {
            os << chapters[i] << " ";
        }
        os << std::endl;
    }
};

#endif // FILM_H