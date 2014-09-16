
#include "stdafx.h"
#include "TextList.h"

/// Add an item to the list
/// \param[item] Item to be added.
void TextList::addItem(const ItemType& item) {
    container.push_back(item);
}

/// Remove an item by index
/// \param[index] Index of item to be removed.
void TextList::removeItem(int index) {
    container.erase(container.begin() + index);
}

/// Delete all items in the list.
void TextList::clearItems() {
    container.clear();
}