#include "Video.h"

Video::Video(const std::string &name, const std::string &filePath, int duration)
    : Multimedia(name, filePath), duration(duration) {}

Video::~Video() {
    std::cout << "Video " << getName() << " is being destroyed" << std::endl;
}

int Video::getDuration() const {
    return duration;
}

void Video::display(std::ostream &os) const {
    Multimedia::display(os);
    os << "Duration: " << duration << " seconds" << std::endl;
}

void Video::play() const {
    std::cout << "Playing video: " << getName() << std::endl;
}