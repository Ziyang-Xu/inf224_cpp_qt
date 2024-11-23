/**
 * @file Video.cpp
 * @brief Implementation of the Video class.
 */

#include "Video.h"

/**
 * @brief Constructs a Video object.
 * @param name The name of the video.
 * @param path The file path of the video.
 * @param duration The duration of the video in seconds.
 */
Video::Video(const std::string& name, const std::string& path, int duration)
    : Multimedia(name, path), duration(duration) {}

/**
 * @brief Displays video information.
 * @param os The output stream to display the information.
 */
void Video::display(std::ostream& os) const {
    Multimedia::display(os);
    os << "Duration: " << duration << " seconds" << std::endl;
}

/**
 * @brief Plays the video.
 */
void Video::play() const {
    std::cout << "Playing video: " << name << std::endl;
    // Play the video using macOS QuickTime Player
    std::string command = "open " + path;
    system(command.c_str());
}

/**
 * @brief Serializes the video to a file.
 * @param ofs The output file stream to write the serialized video.
 */
void Video::serialize(std::ofstream& ofs) const {
    ofs << name << std::endl;
    ofs << path << std::endl;
    ofs << duration << std::endl;
}

/**
 * @brief Deserializes the video from a file.
 * @param ifs The input file stream to read the serialized video.
 */
void Video::deserialize(std::ifstream& ifs) {
    std::getline(ifs, name);
    std::getline(ifs, path);
    ifs >> duration;
    ifs.ignore(); // Ignore the newline character after duration
}

/**
 * @brief Returns the class name.
 * @return The class name.
 */
std::string Video::getClassName() const {
    return "Video";
}