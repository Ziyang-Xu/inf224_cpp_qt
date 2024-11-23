/**
 * @file Photo.cpp
 * @brief Implementation of the Photo class.
 */
#include "Photo.h"

/**
 * @brief Constructs a Photo object.
 * @param name The name of the photo.
 * @param path The file path of the photo.
 * @param latitude The latitude where the photo was taken.
 * @param longitude The longitude where the photo was taken.
 */
Photo::Photo(const std::string& name, const std::string& path, double latitude, double longitude)
    : Multimedia(name, path), latitude(latitude), longitude(longitude) {}

/**
 * @brief Displays photo information.
 * @param os The output stream to display the information.
 */
void Photo::display(std::ostream& os) const {
    Multimedia::display(os);
    os << "Latitude: " << latitude << "\nLongitude: " << longitude << std::endl;
}

/**
 * @brief Plays the photo.
 */
void Photo::play() const {
    std::cout << "Displaying photo: " << name << std::endl;
    // Display the photo using macOS Preview
    std::string command = "open " + path;
    system(command.c_str());
}

/**
 * @brief Serializes the photo to a file.
 * @param ofs The output file stream to write the serialized photo.
 */
void Photo::serialize(std::ofstream& ofs) const {
    ofs << name << std::endl;
    ofs << path << std::endl;
    ofs << latitude << std::endl;
    ofs << longitude << std::endl;
}

/**
 * @brief Deserializes the photo from a file.
 * @param ifs The input file stream to read the serialized photo.
 */
void Photo::deserialize(std::ifstream& ifs) {
    std::getline(ifs, name);
    std::getline(ifs, path);
    ifs >> latitude;
    ifs >> longitude;
    ifs.ignore(); // Ignore the newline character after longitude
}

/**
 * @brief Returns the class name.
 * @return The class name.
 */
std::string Photo::getClassName() const {
    return "Photo";
}