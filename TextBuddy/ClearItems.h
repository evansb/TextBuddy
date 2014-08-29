#pragma once
#include "stdafx.h"

#include "App.h"
#include "AbstractFeature.h"
#include "TextList.h"

// Clear all items in list.
class ClearItems : public App::Feature {
public:
    ClearItems() = default;
    virtual ~ClearItems() = default;

    const static std::string CLEAR_KEYWORD;

    bool interpret(const App::Command& command) override;
    App::Feedback execute(App::SharedData& data) override;
};