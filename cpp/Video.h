#ifndef VIDEO_H
#define VIDEO_H

#include "Multimedia.h"

class Video : public Multimedia {
public:
    Video(const std::string& name, const std::string& path, int duration);
    void display(std::ostream& os) const override;
    void play() const override;
    void serialize(std::ofstream& ofs) const override;
    void deserialize(std::ifstream& ifs) override;
    std::string getClassName() const override;

private:
    int duration;
};

#endif // VIDEO_H