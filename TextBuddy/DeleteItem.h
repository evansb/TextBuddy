#pragma once
#include "stdafx.h"

#include "App.h"
#include "AbstractFeature.h"
#include "TextList.h"

class DeleteItem : public App::Feature {
    /*  Features for deleting an item from the TextList */
public:
    const static std::string DELETE_KEYWORD;
    bool interpret(const App::Command& command) override;
    App::Feedback execute(App::SharedData& data) override;

    DeleteItem() = default;
    virtual ~DeleteItem() = default;
private:
    int indexToDelete;
};