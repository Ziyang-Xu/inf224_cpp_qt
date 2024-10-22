#include "Photo.h"

Photo::Photo(const std::string &name, const std::string &filePath, double latitude, double longitude)
    : Multimedia(name, filePath), latitude(latitude), longitude(longitude) {}

Photo::~Photo() {
    std::cout << "Photo " << getName() << " is being destroyed" << std::endl;
}

double Photo::getLatitude() const {
    return latitude;
}

double Photo::getLongitude() const {
    return longitude;
}

void Photo::display(std::ostream &os) const {
    Multimedia::display(os);
    os << "Latitude: " << latitude << "\nLongitude: " << longitude << std::endl;
}

void Photo::play() const {
    std::cout << "Displaying photo: " << getName() << std::endl;
}//
// Created by Chaleur on 22/10/2024.
//
