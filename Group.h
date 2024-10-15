#ifndef GROUP_H
#define GROUP_H

#include <list>
#include <string>
#include <iostream>
#include "Multimedia.h"

class Group : public std::list<Multimedia*> {
private:
    std::string name;

public:
    // Constructor
    Group(const std::string& groupName) : name(groupName) {}

    // Accessor for group name
    std::string getName() const {
        return name;
    }

    // Display method
    void display(std::ostream& os) const {
        os << "Group: " << name << std::endl;
        for (const auto& item : *this) {
            item->display(os);
        }
    }
};

#endif // GROUP_H