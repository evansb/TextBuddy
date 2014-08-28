#pragma once
#include "stdafx.h"

class TextList {
public:
    typedef std::string ItemType;
    typedef std::vector<ItemType> Container;

    void addItem(const ItemType& item);
    void removeItem(int index);
    void clearItems();

    inline unsigned int getSize() { return container.size(); }
    inline bool isEmpty() { return container.empty(); }
    inline Container getItems() { return container; }
    inline Container::iterator begin() { return container.begin(); }
    inline Container::iterator end() { return container.end(); }

    TextList() = default;
    ~TextList() = default;
private:
    Container container;
};
