#ifndef PHOTO_H
#define PHOTO_H

#include "Multimedia.h"

class Photo : public Multimedia {
public:
    Photo(const std::string& name, const std::string& path, double latitude, double longitude);
    void display(std::ostream& os) const override;
    void play() const override;
    void serialize(std::ofstream& ofs) const override;
    void deserialize(std::ifstream& ifs) override;
    std::string getClassName() const override;

private:
    double latitude;
    double longitude;
};

#endif // PHOTO_H