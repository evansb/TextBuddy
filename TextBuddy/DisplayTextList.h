#pragma once
#include "stdafx.h"

#include "App.h"
#include "AbstractFeature.h"
#include "TextList.h"

// Display a numbered ordering of every item in the TextList.
// Interpret : "display" -> true
// Feedback : The content of the list as a line numbered strings.
class DisplayTextList : public App::Feature {
public:
    DisplayTextList() = default;
    virtual ~DisplayTextList() = default;

    const static std::string DISPLAY_KEYWORD;

    bool interpret(const App::Command& command) override;
    App::Feedback execute(App::SharedData& data) override;
private:
    TextList::ItemType inputCache;
};