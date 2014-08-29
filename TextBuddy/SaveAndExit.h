#pragma once
#include "stdafx.h"

#include "App.h"
#include "AbstractFeature.h"
#include "TextList.h"

// Write the list to a text file and exit the program
class SaveAndExit : public App::Feature {
public:
    SaveAndExit() = default;
    virtual ~SaveAndExit() = default;

    const static std::string EXIT_KEYWORD;

    bool interpret(const App::Command& command) override;
    App::Feedback execute(App::SharedData& data) override;
};