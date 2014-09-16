#pragma once
#include "stdafx.h"

/// Provides abstraction of the text list used in the
/// TextBuddy application.
class TextList {
public:
    /// Type of the list item is string.
    typedef std::string ItemType;

    /// Container used is vector.
    typedef std::vector<ItemType> Container;
public:
    /// Default destructor.
    ~TextList() = default;

    /// Default constructor.
    TextList() = default;

public:
    /// Get total number of times.
    inline unsigned int getSize() { return container.size(); }

    /// Check if list is empty
    inline bool isEmpty() { return container.empty(); }

    /// Get item at a particular index
    inline ItemType getAt(int index) { return container.at(index); }

    /// Mutable iterators.
    inline Container::iterator begin() { return container.begin(); }
    inline Container::iterator end() { return container.end(); }

    /// Constant iterators.
    inline Container::const_iterator cbegin() { return container.cbegin(); }
    inline Container::const_iterator cend() { return container.cend(); }

    /// Add an item to the list
    /// \param[item] Item to be added.
    void addItem(const ItemType& item);

    /// Remove an item by index
    /// \param[index] Index of item to be removed.
    void removeItem(int index);

    /// Delete all items in the list.
    void clearItems();
private:
    Container container;
};
