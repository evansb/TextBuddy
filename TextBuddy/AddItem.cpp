#include "stdafx.h"

#include "AddItem.h"

const std::string AddItem::ADD_KEYWORD = "add";

/* If the first word of the UserCommand is "add" and there is one or more
   character after the space, return true and store the rest
   of the user command string to inputCache. Otherwise return false.
   */
bool AddItem::interpret(const App::Command& command) {
    auto firstSpacePos = command.find(' ');
    std::string firstWord = command.substr(0, firstSpacePos);
    bool addKeywordFound = (firstWord == ADD_KEYWORD);
    if (addKeywordFound) {
        this->inputCache = command.substr(firstSpacePos + 1, std::string::npos);
        return true;
    } else {
        return false;
    }
}

App::Feedback AddItem::execute(App::SharedData& data) {
    data.textList.addItem(inputCache);
    std::string outputString = "added to " + data.filename + ": \"" + inputCache + "\"\n";
    return outputString;
}