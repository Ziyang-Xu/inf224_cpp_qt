#include "Multimedia.h"

Multimedia::Multimedia(const std::string& name, const std::string& path)
    : name(name), path(path) {}

Multimedia::~Multimedia() {}

void Multimedia::display(std::ostream& os) const {
    os << "Name: " << name << "\nFile Path: " << path << std::endl;
}

std::string Multimedia::getName() const {
    return name;
}

std::ofstream& operator<<(std::ofstream& ofs, const Multimedia& multimedia) {
    ofs << multimedia.getClassName() << std::endl;
    multimedia.serialize(ofs);
    return ofs;
}

std::ifstream& operator>>(std::ifstream& ifs, Multimedia& multimedia) {
    multimedia.deserialize(ifs);
    return ifs;
}