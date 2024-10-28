#ifndef FILM_H
#define FILM_H

#include "Multimedia.h"
#include <vector>

class Film : public Multimedia {
public:
    Film(const std::string& name, const std::string& path, int duration, const std::vector<int>& chapters);
    void display(std::ostream& os) const override;
    void play() const override;
    void serialize(std::ofstream& ofs) const override;
    void deserialize(std::ifstream& ifs) override;
    std::string getClassName() const override;

private:
    int duration;
    std::vector<int> chapters;
};

#endif // FILM_H