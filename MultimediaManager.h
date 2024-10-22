#ifndef MULTIMEDIAMANAGER_H
#define MULTIMEDIAMANAGER_H

#include <map>
#include <memory>
#include <string>
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"

class MultimediaManager {
private:
    std::map<std::string, std::shared_ptr<Multimedia>> multimediaTable;
    std::map<std::string, std::shared_ptr<Group>> groupTable;

public:
    std::shared_ptr<Photo> createPhoto(const std::string &name, const std::string &filePath, double latitude, double longitude);
    std::shared_ptr<Video> createVideo(const std::string &name, const std::string &filePath, int duration);
    std::shared_ptr<Film> createFilm(const std::string &name, const std::string &filePath, int duration, const std::vector<int> &chapters);
    std::shared_ptr<Group> createGroup(const std::string &name);

    void displayMultimedia(const std::string &name) const;
    void displayGroup(const std::string &name) const;
    void playMultimedia(const std::string &name) const;

    void deleteMultimedia(const std::string &name);
    void deleteGroup(const std::string &name);
};

#endif // MULTIMEDIAMANAGER_H