#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <string>
#include <iostream>

class Multimedia {
private:
    std::string name;
    std::string filePath;

public:
    // Default constructor
    Multimedia();

    // Parameterized constructor
    Multimedia(const std::string &name, const std::string &filePath);

    // Destructor
    virtual ~Multimedia();

    // Getters
    std::string getName() const;
    std::string getFilePath() const;

    // Setters
    void setName(const std::string &name);
    void setFilePath(const std::string &filePath);

    // Display method
    virtual void display(std::ostream &os) const;
    virtual void play() const = 0; // Pure virtual function
};

#endif // MULTIMEDIA_H