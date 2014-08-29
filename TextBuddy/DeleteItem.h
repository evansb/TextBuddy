#pragma once
#include "stdafx.h"

#include "App.h"
#include "AbstractFeature.h"
#include "TextList.h"

// Delete an item by index from the TextList.
// Interpret : "delete (.*)" -> true
// Feedback  : The item deleted as string.
// Note : Failed parsing of index are catched only in
// execute.
class DeleteItem : public App::Feature {
public:
    DeleteItem() = default;
    virtual ~DeleteItem() = default;

    const static std::string DELETE_KEYWORD;

    bool interpret(const App::Command& command) override;
    App::Feedback execute(App::SharedData& data) override;
private:
    int indexToDelete;
};