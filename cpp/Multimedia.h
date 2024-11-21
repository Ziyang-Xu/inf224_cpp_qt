#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <string>
#include <iostream>
#include <fstream>

class Multimedia {
public:
    Multimedia(const std::string& name, const std::string& path);
    virtual ~Multimedia();
    virtual void display(std::ostream& os) const;
    virtual void play() const = 0;
    std::string getName() const;

    virtual void serialize(std::ofstream& ofs) const = 0;
    virtual void deserialize(std::ifstream& ifs) = 0;
    virtual std::string getClassName() const = 0;

    friend std::ofstream& operator<<(std::ofstream& ofs, const Multimedia& multimedia);
    friend std::ifstream& operator>>(std::ifstream& ifs, Multimedia& multimedia);

protected:
    std::string name;
    std::string path;
};

#endif // MULTIMEDIA_H