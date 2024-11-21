#include "Photo.h"

Photo::Photo(const std::string& name, const std::string& path, double latitude, double longitude)
    : Multimedia(name, path), latitude(latitude), longitude(longitude) {}

void Photo::display(std::ostream& os) const {
    Multimedia::display(os);
    os << "Latitude: " << latitude << "\nLongitude: " << longitude << std::endl;
}

void Photo::play() const {
    std::cout << "Displaying photo: " << name << std::endl;
    // Display the photo using macOS Preview
    std::string command = "open " + path;
    system(command.c_str());
}

void Photo::serialize(std::ofstream& ofs) const {
    ofs << name << std::endl;
    ofs << path << std::endl;
    ofs << latitude << std::endl;
    ofs << longitude << std::endl;
}

void Photo::deserialize(std::ifstream& ifs) {
    std::getline(ifs, name);
    std::getline(ifs, path);
    ifs >> latitude;
    ifs >> longitude;
    ifs.ignore(); // Ignore the newline character after longitude
}

std::string Photo::getClassName() const {
    return "Photo";
}