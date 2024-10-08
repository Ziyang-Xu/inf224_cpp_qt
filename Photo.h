#ifndef PHOTO_H
#define PHOTO_H

#include "Multimedia.h"

class Photo : public Multimedia {
private:
    double latitude;
    double longitude;

public:
    // Default constructor
    Photo();

    // Parameterized constructor
    Photo(const std::string &name, const std::string &filePath, double latitude, double longitude);

    // Getters
    double getLatitude() const;
    double getLongitude() const;

    // Setters
    void setLatitude(double latitude);
    void setLongitude(double longitude);

    // Display method
    void display(std::ostream &os) const override;

    // Play method
    void play() const override;
};

// Implementations
Photo::Photo() : Multimedia(), latitude(0.0), longitude(0.0) {}

Photo::Photo(const std::string &name, const std::string &filePath, double latitude, double longitude)
    : Multimedia(name, filePath), latitude(latitude), longitude(longitude) {}

double Photo::getLatitude() const {
    return latitude;
}

double Photo::getLongitude() const {
    return longitude;
}

void Photo::setLatitude(double latitude) {
    this->latitude = latitude;
}

void Photo::setLongitude(double longitude) {
    this->longitude = longitude;
}

void Photo::display(std::ostream &os) const {
    Multimedia::display(os);
    os << "Latitude: " << latitude << "\nLongitude: " << longitude << std::endl;
}

void Photo::play() const {
    std::string command = "open " + getFilePath() + " &";
    system(command.c_str());
}

#endif // PHOTO_H