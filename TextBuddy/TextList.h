#pragma once
#include "stdafx.h"

// Stores and provides access and basic functionality 
// of the list of items.
class TextList {
public:
    typedef std::string ItemType;
    typedef std::vector<ItemType> Container;

    TextList() = default;
    ~TextList() = default;

    inline unsigned int getSize() { return container.size(); }
    inline bool isEmpty() { return container.empty(); }
    inline ItemType getAt(int index) { return container.at(index); }
    inline Container::iterator begin() { return container.begin(); }
    inline Container::iterator end() { return container.end(); }

    void addItem(const ItemType& item);
    void removeItem(int index);
    void clearItems();
private:
    Container container;
};
