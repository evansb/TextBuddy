#pragma once
#include "stdafx.h"

#include "App.h"
#include "AbstractFeature.h"
#include "TextList.h"

/*  Display a numbered ordering of each item of the TextList */
class DisplayTextList : public App::Feature {
public:
    const static std::string DISPLAY_KEYWORD;
    bool interpret(const App::Command& command) override;
    App::Feedback execute(App::SharedData& data) override;

    DisplayTextList() = default;
    virtual ~DisplayTextList() = default;
private:
    TextList::ItemType inputCache;
};