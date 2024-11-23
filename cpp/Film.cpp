/**
 * @file Film.cpp
 * @brief Implementation of the Film class.
 */
#include "Film.h"

/**
 * @brief Constructs a Film object.
 * @param name The name of the film.
 * @param path The file path of the film.
 * @param duration The duration of the film in seconds.
 * @param chapters The chapters of the film.
 */
Film::Film(const std::string& name, const std::string& path, int duration, const std::vector<int>& chapters)
    : Multimedia(name, path), duration(duration), chapters(chapters) {}

/**
 * @brief Displays film information.
 * @param os The output stream to display the information.
 */
void Film::display(std::ostream& os) const {
    Multimedia::display(os);
    os << "Duration: " << duration << " seconds\nChapters: ";
    for (const auto& chapter : chapters) {
        os << chapter << " ";
    }
    os << std::endl;
}

/**
 * @brief Plays the film.
 */
void Film::play() const {
    std::cout << "Playing film: " << name << std::endl;
    // Play the film using macOS QuickTime Player
    std::string command = "open " + path;
    system(command.c_str());
}

/**
 * @brief Serializes the film to a file.
 * @param ofs The output file stream to write the serialized film.
 */
void Film::serialize(std::ofstream& ofs) const {
    ofs << name << std::endl;
    ofs << path << std::endl;
    ofs << duration << std::endl;
    ofs << chapters.size() << std::endl;
    for (const auto& chapter : chapters) {
        ofs << chapter << std::endl;
    }
}

/**
 * @brief Deserializes the film from a file.
 * @param ifs The input file stream to read the serialized film.
 */
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

/**
 * @brief Gets the class name of the film.
 * @return The class name.
 */
std::string Film::getClassName() const {
    return "Film";
}