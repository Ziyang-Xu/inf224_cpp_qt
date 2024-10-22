#ifndef PHOTO_H
#define PHOTO_H

#include "Multimedia.h"
#include <iostream>

class Photo : public Multimedia {
private:
    double latitude;
    double longitude;

public:
    Photo(const std::string &name, const std::string &filePath, double latitude, double longitude);
    ~Photo() override;

    double getLatitude() const;
    double getLongitude() const;

    void display(std::ostream &os) const override;
    void play() const override;
};

using PhotoPtr = std::shared_ptr<Photo>;

#endif // PHOTO_H