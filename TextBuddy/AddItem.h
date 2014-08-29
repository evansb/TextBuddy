#pragma once
#include "stdafx.h"

#include "App.h"
#include "AbstractFeature.h"
#include "TextList.h"

// Add an item to the TextList.
// Interpret : "add (.*)" -> true
// Feedback  : A message to inform a successful insertion.
class AddItem : public App::Feature {
public:
    AddItem() = default;
    virtual ~AddItem() = default;

    const static std::string ADD_KEYWORD;

    bool interpret(const App::Command& command) override;
    App::Feedback execute(App::SharedData& data) override;
private:
    TextList::ItemType inputCache;
};