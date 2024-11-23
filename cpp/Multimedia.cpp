/**
 * @file Multimedia.cpp
 * @brief Implementation of the Multimedia class.
 */
#include "Multimedia.h"

/**
 * @brief Constructs a Multimedia object.
 * @param name The name of the multimedia.
 * @param path The file path of the multimedia.
 */
Multimedia::Multimedia(const std::string& name, const std::string& path)
    : name(name), path(path) {}

/**
 * @brief Destroys the Multimedia object.
 */
Multimedia::~Multimedia() {}

/**
 * @brief Displays multimedia information.
 * @param os The output stream to display the information.
 */
void Multimedia::display(std::ostream& os) const {
    os << "Name: " << name << "\nFile Path: " << path << std::endl;
}

/**
 * @brief Returns the name of the multimedia.
 * @return The name of the multimedia.
 */
std::string Multimedia::getName() const {
    return name;
}

/**
 * @brief Serializes the multimedia to a file.
 * @param ofs The output file stream to write the serialized multimedia.
 */
std::ofstream& operator<<(std::ofstream& ofs, const Multimedia& multimedia) {
    ofs << multimedia.getClassName() << std::endl;
    multimedia.serialize(ofs);
    return ofs;
}

/**
 * @brief Deserializes the multimedia from a file.
 * @param ifs The input file stream to read the serialized multimedia.
 */
std::ifstream& operator>>(std::ifstream& ifs, Multimedia& multimedia) {
    multimedia.deserialize(ifs);
    return ifs;
}