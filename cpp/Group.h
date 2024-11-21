#ifndef GROUP_H
#define GROUP_H

#include <vector>
#include <memory>
#include <iostream>
#include "Multimedia.h"

class Group {
private:
    std::string name;
    std::vector<std::shared_ptr<Multimedia>> items;

public:
    Group(const std::string &name);
    ~Group();

    void push_back(const std::shared_ptr<Multimedia> &item);
    void remove(const std::shared_ptr<Multimedia> &item);
    void display(std::ostream &os) const;
};

using GroupPtr = std::shared_ptr<Group>;

#endif // GROUP_H