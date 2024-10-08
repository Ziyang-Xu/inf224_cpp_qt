#include "Multimedia.h"

// Default constructor
Multimedia::Multimedia() : name(""), filePath("") {}

// Parameterized constructor
Multimedia::Multimedia(const std::string &name, const std::string &filePath) : name(name), filePath(filePath) {}

// Destructor
Multimedia::~Multimedia() {}

// Getters
std::string Multimedia::getName() const {
    return name;
}

std::string Multimedia::getFilePath() const {
    return filePath;
}

// Setters
void Multimedia::setName(const std::string &name) {
    this->name = name;
}

void Multimedia::setFilePath(const std::string &filePath) {
    this->filePath = filePath;
}

// Display method
void Multimedia::display(std::ostream &os) const {
    os << "Name: " << name << "\nFile Path: " << filePath << std::endl;
}