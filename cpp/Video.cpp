#include "Video.h"

Video::Video(const std::string& name, const std::string& path, int duration)
    : Multimedia(name, path), duration(duration) {}

void Video::display(std::ostream& os) const {
    Multimedia::display(os);
    os << "Duration: " << duration << " seconds" << std::endl;
}

void Video::play() const {
    std::cout << "Playing video: " << name << std::endl;
    // Play the video using macOS QuickTime Player
    std::string command = "open " + path;
    system(command.c_str());
}

void Video::serialize(std::ofstream& ofs) const {
    ofs << name << std::endl;
    ofs << path << std::endl;
    ofs << duration << std::endl;
}

void Video::deserialize(std::ifstream& ifs) {
    std::getline(ifs, name);
    std::getline(ifs, path);
    ifs >> duration;
    ifs.ignore(); // Ignore the newline character after duration
}

std::string Video::getClassName() const {
    return "Video";
}