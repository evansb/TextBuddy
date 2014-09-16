#pragma once
#include "stdafx.h"

#include "App.h"
#include "AbstractFeature.h"
#include "TextList.h"

/// TextBuddy feature to add item to the list. 
class AddItem : public App::Feature {
    friend class TestAddItem;
public:
    /// Default constructor
    AddItem() = default;

    /// Default destructor.
    virtual ~AddItem() = default;

    /// Any sentence beginning with this keyword indicates a match.
    const static std::string ADD_KEYWORD;

    /// Interpret a command string and stores the added
    /// string to inputCache if the command is a valid command.
    /// A valid command begins with string "add", followed by
    /// arbitrary number of characters, separated by space.
    ///
    /// \param [command] The command string to be interpreted.
    /// \return true if the command string matches, false otherwise.
    bool interpret(const App::Command& command) override;

    /// Add the item from inputCache to the textList in the shared
    /// data struct.
    /// \param [data] TextBuddy shared data structure.
    /// \return A string with format "added to filename: "added content""
    App::Feedback execute(App::SharedData& data) override;

private:
    /// Store the added item parsed during interpret
    TextList::ItemType inputCache;
};