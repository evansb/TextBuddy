#include "stdafx.h"
#include "AddItem.h"

/// \see interpret
const std::string AddItem::ADD_KEYWORD = "add";

/// Interpret a command string and stores the added
/// string to inputCache if the command is a valid command.
/// A valid command begins with string "add", followed by
/// arbitrary number of characters, separated by space.
/// \param [command] The command string to be interpreted.
/// \return true if the command string matches, false otherwise.
bool AddItem::interpret(const App::Command& command) {
    auto firstSpacePos = command.find(' ');
    std::string firstWord = command.substr(0, firstSpacePos);
    bool addKeywordFound = (firstWord == ADD_KEYWORD);
    bool existCharAfterKeyword = command.length() > ADD_KEYWORD.length() + 1;
    if (addKeywordFound && existCharAfterKeyword) {
        this->inputCache = command.substr(firstSpacePos + 1, command.length());
        return true;
    } else {
        return false;
    }
}

/// Add the item from inputCache to the textList in the shared data.
/// \param [data] TextBuddy shared data structure.
/// \return A string with format "added to filename: "added content""
App::Feedback AddItem::execute(App::SharedData& data) {
    data.textList.addItem(inputCache);
    std::string outputString = "added to " + data.filename + ": \"" + inputCache + "\"\n";
    return outputString;
}