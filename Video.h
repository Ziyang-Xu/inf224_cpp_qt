#ifndef VIDEO_H
#define VIDEO_H

#include "Multimedia.h"
#include <iostream>

class Video : public Multimedia {
private:
    int duration;

public:
    Video(const std::string &name, const std::string &filePath, int duration);
    ~Video() override;

    int getDuration() const;

    void display(std::ostream &os) const override;
    void play() const override;
};

using VideoPtr = std::shared_ptr<Video>;

#endif // VIDEO_H