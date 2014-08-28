#pragma once
#include "stdafx.h"

#include "App.h"
#include "AbstractFeature.h"
#include "TextList.h"

class AddItem : public App::Feature {
    /*  Features for adding an item to a TextList */
public:
    const static std::string ADD_KEYWORD;
    bool interpret(const App::Command& command) override;
    App::Feedback execute(App::SharedData& data) override;

    AddItem() = default;
    virtual ~AddItem() = default;
private:
    TextList::ItemType inputCache;
};