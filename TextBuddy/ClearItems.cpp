#include "stdafx.h"
#include "ClearItems.h"

const std::string ClearItems::CLEAR_KEYWORD = "clear";

bool ClearItems::interpret(const App::Command& command) {
    return command == CLEAR_KEYWORD;
}

App::Feedback ClearItems::execute(App::SharedData& data) {
    std::stringstream feedback;
    if (data.textList.isEmpty()) {
        feedback << data.filename + " is already empty\n";
    } else {
        data.textList.clearItems();
        feedback << "all content deleted from " << data.filename << "\n";
    }
    return feedback.str();
}