#include "Film.h"

Film::Film(const std::string& name, const std::string& path, int duration, const std::vector<int>& chapters)
    : Multimedia(name, path), duration(duration), chapters(chapters) {}

void Film::display(std::ostream& os) const {
    Multimedia::display(os);
    os << "Duration: " << duration << " seconds\nChapters: ";
    for (const auto& chapter : chapters) {
        os << chapter << " ";
    }
    os << std::endl;
}

void Film::play() const {
    std::cout << "Playing film: " << name << std::endl;
    // Play the film using macOS QuickTime Player
    std::string command = "open " + path;
    system(command.c_str());
}

void Film::serialize(std::ofstream& ofs) const {
    ofs << name << std::endl;
    ofs << path << std::endl;
    ofs << duration << std::endl;
    ofs << chapters.size() << std::endl;
    for (const auto& chapter : chapters) {
        ofs << chapter << std::endl;
    }
}

void Film::deserialize(std::ifstream& ifs) {
    std::getline(ifs, name);
    std::getline(ifs, path);
    ifs >> duration;
    size_t chaptersSize;
    ifs >> chaptersSize;
    chapters.resize(chaptersSize);
    for (size_t i = 0; i < chaptersSize; ++i) {
        ifs >> chapters[i];
    }
    ifs.ignore(); // Ignore the newline character after the last chapter
}

std::string Film::getClassName() const {
    return "Film";
}