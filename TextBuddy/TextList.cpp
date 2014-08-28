
#include "stdafx.h"
#include "TextList.h"

void TextList::addItem(const ItemType& item) {
    container.push_back(item);
}

void TextList::removeItem(int index) {
    container.erase(container.begin() + index);
}

void TextList::clearItems() {
    container.clear();
}