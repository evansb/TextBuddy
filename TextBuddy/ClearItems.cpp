#include "stdafx.h"
#include "ClearItems.h"

/// \see interpret
const std::string ClearItems::CLEAR_KEYWORD = "clear";

/// A valid command is the exact string CLEAR_KEYWORD
/// \param[command] command to be interpreted.
/// \return true if match, false otherwise.
bool ClearItems::interpret(const App::Command& command) {
    return command == CLEAR_KEYWORD;
}

/// Clears all the item in the TextList stored in data and return a success message.
/// If the list is already empty, respond using different message.
/// \param [data] Shared data passed to this method.
/// \return The string "all content deleted from {filename}" or "{filename} is empty"
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