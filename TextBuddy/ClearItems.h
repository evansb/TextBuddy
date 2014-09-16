#pragma once
#include "stdafx.h"

#include "App.h"
#include "AbstractFeature.h"
#include "TextList.h"

/// TextBuddy feature to clear all items in list.
class ClearItems : public App::Feature {
public:
    /// Default constructor.
    ClearItems() = default;

    /// Default destructor.
    virtual ~ClearItems() = default;

    /// A valid command is the exact string CLEAR_KEYWORD
    /// \param[command] command to be interpreted.
    /// \return true if match, false otherwise.
    bool interpret(const App::Command& command) override;

    /// Clears all the item in the TextList stored in data and return a success message.
    /// If the list is already empty, respond using different message.
    /// \param [data] Shared data passed to this method.
    /// \return The string "all content deleted from {filename}" or "{filename} is empty"
    App::Feedback execute(App::SharedData& data) override;

private:  
    /// \see interpret
    const static std::string CLEAR_KEYWORD;
};