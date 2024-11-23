/**
 * @file Group.cpp
 * @brief Implementation of the Group class.
 */
#include "Group.h"

/**
 * @brief Constructs a Group object.
 * @param name The name of the group.
 */
Group::Group(const std::string &name) : name(name) {}

/**
 * @brief Destroys a Group object.
 */
Group::~Group() {
    std::cout << "Group " << name << " is being destroyed" << std::endl;
}

/**
 * @brief Adds an item to the group.
 * @param item The item to add.
 */
void Group::push_back(const std::shared_ptr<Multimedia> &item) {
    items.push_back(item);
}

/**
 * @brief Removes an item from the group.
 * @param item The item to remove.
 */
void Group::remove(const std::shared_ptr<Multimedia> &item) {
    items.erase(std::remove(items.begin(), items.end(), item), items.end());
}

/**
 * @brief Displays group information.
 * @param os The output stream to display the information.
 */
void Group::display(std::ostream &os) const {
    os << "Group: " << name << std::endl;
    for (const auto &item : items) {
        item->display(os);
    }
}
