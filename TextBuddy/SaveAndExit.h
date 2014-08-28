#pragma once
#include "stdafx.h"

#include "App.h"
#include "AbstractFeature.h"
#include "TextList.h"

/*  Display a numbered ordering of each item of the TextList */
class SaveAndExit : public App::Feature {
public:
    const static std::string EXIT_KEYWORD;
    bool interpret(const App::Command& command) override;
    App::Feedback execute(App::SharedData& data) override;

    SaveAndExit() = default;
    virtual ~SaveAndExit() = default;
};