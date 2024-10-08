#ifndef VIDEO_H
#define VIDEO_H

#include "Multimedia.h"

class Video : public Multimedia {
private:
    int duration;

public:
    // Default constructor
    Video();

    // Parameterized constructor
    Video(const std::string &name, const std::string &filePath, int duration);

    // Getter
    int getDuration() const;

    // Setter
    void setDuration(int duration);

    // Display method
    void display(std::ostream &os) const override;

    // Play method
    void play() const override;
};

// Implementations
Video::Video() : Multimedia(), duration(0) {}

Video::Video(const std::string &name, const std::string &filePath, int duration)
    : Multimedia(name, filePath), duration(duration) {}

int Video::getDuration() const {
    return duration;
}

void Video::setDuration(int duration) {
    this->duration = duration;
}

void Video::display(std::ostream &os) const {
    Multimedia::display(os);
    os << "Duration: " << duration << " seconds" << std::endl;
}

void Video::play() const {
    std::string command = "open " + getFilePath() + " &";
    system(command.c_str());
}

#endif // VIDEO_H