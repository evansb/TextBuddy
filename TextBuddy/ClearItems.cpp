#include "stdafx.h"
#include "ClearItems.h"

const std::string ClearItems::CLEAR_KEYWORD = "clear";

/*
 * Command must be exactly "clear" (i.e "clear" with trailing
 * spaces is ignored.
 */
bool ClearItems::interpret(const App::Command& command) {
    return command == CLEAR_KEYWORD;
}

/*
 * Clear the list, if it is already empty says so.
 */
App::Feedback ClearItems::execute(App::SharedData& data) {
    std::stringstream stream;
    if (data.textList.isEmpty()) {
        stream << data.filename + " is already empty\n";
    } else {
        data.textList.clearItems();
        stream << "all content deleted from " << data.filename << "\n";
    }
    return stream.str();
}