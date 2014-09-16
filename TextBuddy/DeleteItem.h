#pragma once
#include "stdafx.h"

#include "App.h"
#include "AbstractFeature.h"
#include "TextList.h"

/// TextBuddy feature to delete an item by index from the TextList.
class DeleteItem : public App::Feature {
public:
    /// Default constructor.
    DeleteItem() = default;

    /// Default destructor.
    virtual ~DeleteItem() = default;

    /// A valid command begins with DELETE_KEYWORD, followed by an integer
    /// as the index of the item to delete, separated by single space.
    /// Stores the index internally in indexToDelete.
    /// \param[command] command to be interpreted.
    /// \return true if a valid command, false otherwise
    bool interpret(const App::Command& command) override;

    /// Precondition : Has interpreted and stored the index in indexToDelete.
    /// Checks if indexToDelte is a valid index, if not return an error message.
    /// Otherwise delete the item from the text list stored in data.
    /// \param[data] Shared data passed to this method.
    /// \return A message telling that delete is un/successful.
    App::Feedback execute(App::SharedData& data) override;

private:
    /// \see interpret
    const static std::string DELETE_KEYWORD;

    /// \see interpret
    int indexToDelete;
};