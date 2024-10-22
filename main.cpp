#include <iostream>
#include <vector>
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include "MultimediaManager.h"

int main() {
    MultimediaManager manager;

    // Create multimedia objects and groups
    auto photo = manager.createPhoto("Photo", "../sample_photo.jpg", 37.7749, 122.4194);
    auto video = manager.createVideo("Video", "../sample_video.mp4", 10);
    std::vector<int> chapters = {10, 20, 30};
    auto film = manager.createFilm("Film", "../sample_film.mp4", 60, chapters);

    auto photoGroup = manager.createGroup("Photo Group");
    photoGroup->push_back(photo);

    auto videoGroup = manager.createGroup("Video Group");
    videoGroup->push_back(video);

    auto mixedGroup = manager.createGroup("Mixed Group");
    mixedGroup->push_back(photo);
    mixedGroup->push_back(video);
    mixedGroup->push_back(film);

    // Display groups
    manager.displayGroup("Photo Group");
    manager.displayGroup("Video Group");
    manager.displayGroup("Mixed Group");

    // Show Photo Coordinates
    std::cout << "Photo Coordinates: (" << photo->getLatitude() << ", " << photo->getLongitude() << ")" << std::endl;

    // Show Video Duration
    std::cout << "Video Duration: " << video->getDuration() << " seconds" << std::endl;

    // Show Film Duration and Chapters Durations
    std::cout << "Film Duration: " << film->getDuration() << " seconds" << std::endl;
    std::cout << "Chapters Durations: ";
    const std::vector<int>& filmChapters = film->getChapters();
    for (int chapter : filmChapters) {
        std::cout << chapter << " ";
    }
    std::cout << std::endl;

    return 0;
}