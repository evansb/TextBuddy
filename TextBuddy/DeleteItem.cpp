#include "stdafx.h"

#include "DeleteItem.h"

const std::string DeleteItem::DELETE_KEYWORD = "delete";

//    Parse "delete", followed by a space and an integer.
//    Returns true if the keyword "delete" is found, regardless
//    whether the index is valid or not.
//    If the integer format is invalid, indexToDelete is 0.
bool DeleteItem::interpret(const App::Command& command) {
    int firstSpacePos = command.find(' ');
    std::string firstWord = command.substr(0, firstSpacePos);
    bool deleteKeywordFound = (firstWord == DELETE_KEYWORD);
    if (deleteKeywordFound) {
        std::string indexString = command.substr(firstSpacePos + 1, command.size());
        int indexInt = atoi(indexString.c_str());
        this->indexToDelete = indexInt - 1;
        return true;
    } else {
        return false;
    }
}

//  Delete an item from the list by index
//    Success case : The item is deleted
//    Failed case  : Invalid index, Index string failed to parse in interpret
App::Feedback DeleteItem::execute(App::SharedData& data) {
    bool indexIsValid = indexToDelete >= 0 && indexToDelete < data.textList.getSize();
    bool integerInvalidToParse = (indexToDelete == -1);
    auto deletedItem = std::move(data.textList.getAt(indexToDelete));

    if (indexIsValid) {
        data.textList.removeItem(indexToDelete);
        indexToDelete = -1; // Reset index to invalid again.
    }

    std::stringstream feedback;
    if (integerInvalidToParse) {
        feedback << "invalid index string\n";
    } else if (indexIsValid) {
        feedback << "deleted from " << data.filename << ": \"";
        feedback << deletedItem << "\"\n";
    } else {
        feedback << "index " << (indexToDelete + 1);
        feedback << " is out of range.\n";
    }
    return feedback.str();
}
