#include "Group.h"

Group::Group(const std::string &name) : name(name) {}

Group::~Group() {
    std::cout << "Group " << name << " is being destroyed" << std::endl;
}

void Group::push_back(const std::shared_ptr<Multimedia> &item) {
    items.push_back(item);
}

void Group::remove(const std::shared_ptr<Multimedia> &item) {
    items.erase(std::remove(items.begin(), items.end(), item), items.end());
}

void Group::display(std::ostream &os) const {
    os << "Group: " << name << std::endl;
    for (const auto &item : items) {
        item->display(os);
    }
}//
// Created by Chaleur on 22/10/2024.
//
