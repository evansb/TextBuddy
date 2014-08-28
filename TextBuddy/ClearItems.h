#pragma once
#include "stdafx.h"

#include "App.h"
#include "AbstractFeature.h"
#include "TextList.h"

class ClearItems : public App::Feature {
    /*  Clear all items in the TextList */
public:
    const static std::string CLEAR_KEYWORD;
    bool interpret(const App::Command& command) override;
    App::Feedback execute(App::SharedData& data) override;

    ClearItems() = default;
    virtual ~ClearItems() = default;
};