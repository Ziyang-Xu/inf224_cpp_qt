#ifndef MULTIMEDIAMANAGER_H
#define MULTIMEDIAMANAGER_H

#include <string>
#include <vector>
#include <memory>
#include <map>
#include "Multimedia.h"
#include "Group.h"

class MultimediaManager {
public:
    void createPhoto(const std::string& name, const std::string& path, double latitude, double longitude);
    void createVideo(const std::string& name, const std::string& path, int duration);
    void createFilm(const std::string& name, const std::string& path, int duration, const std::vector<int>& chapters);
    void createGroup(const std::string& name);
    void displayMultimedia(const std::string& name) const;
    void displayGroup(const std::string& name) const;
    void playMultimedia(const std::string& name) const;
    void save(const std::string& filename) const;
    void load(const std::string& filename);

private:
    std::map<std::string, std::shared_ptr<Multimedia>> multimediaMap;
    std::map<std::string, std::shared_ptr<Group>> groupMap;
};

#endif // MULTIMEDIAMANAGER_H