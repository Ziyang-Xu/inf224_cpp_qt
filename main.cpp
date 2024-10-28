#include "MultimediaManager.h"

int main() {
    MultimediaManager manager;
    manager.createPhoto("photo", "../sample_photo.jpg", 48.858844, 2.294351);
    manager.createVideo("video", "../sample_video.mp4", 120);
    manager.createFilm("film", "../sample_film.mp4", 90, {10, 20, 30});

    manager.save("multimedia.txt");

    MultimediaManager loadedManager;
    loadedManager.load("multimedia.txt");

    loadedManager.displayMultimedia("photo");
    loadedManager.displayMultimedia("video");
    loadedManager.displayMultimedia("film");

    return 0;
}