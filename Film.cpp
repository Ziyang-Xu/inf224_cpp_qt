#include "Film.h"
#include <iostream>

Film::Film(const std::string &name, const std::string &filePath, int duration, const std::vector<int> &chapters)
    : Video(name, filePath, duration), chapters(chapters) {}

Film::~Film() {
    std::cout << "Film " << getName() << " is being destroyed" << std::endl;
}

const std::vector<int>& Film::getChapters() const {
    return chapters;
}

int Film::getNumChapters() const {
    return chapters.size();
}

void Film::setChapters(const std::vector<int> &chapters) {
    this->chapters = chapters;
}