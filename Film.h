#ifndef FILM_H
#define FILM_H

#include "Video.h"
#include <vector>

class Film : public Video {
private:
    std::vector<int> chapters;

public:
    Film(const std::string &name, const std::string &filePath, int duration, const std::vector<int> &chapters);
    ~Film() override;

    const std::vector<int>& getChapters() const;
    int getNumChapters() const;
    void setChapters(const std::vector<int> &chapters);
};

using FilmPtr = std::shared_ptr<Film>;

#endif // FILM_H