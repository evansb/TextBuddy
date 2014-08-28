#include "stdafx.h"

#include "DeleteItem.h"

const std::string DeleteItem::DELETE_KEYWORD = "delete";

/*
    Parse "delete", followed by a space and an integer.
    Returns true if the keyword "delete" is found, regardless
    whether the index is valid or not.
    If the integer format is broken, indexToDelete is 0.
    */
bool DeleteItem::interpret(const App::Command& command) {
    auto firstSpacePos = command.find(' ');
    std::string firstWord = command.substr(0, firstSpacePos);
    bool deleteKeywordFound = (firstWord == DELETE_KEYWORD);
    if (deleteKeywordFound) {
        auto indexString = command.substr(firstSpacePos + 1, command.size());
        this->indexToDelete = atoi(indexString.c_str()) - 1;
        return true;
    } else {
        return false;
    }
}

/*
    Delete an item from the list by index
    Success case : The item is deleted
    Failed case  : Invalid index, Index string failed to parse in interpret
    */
App::Feedback DeleteItem::execute(App::SharedData& data) {
    bool indexIsValid = indexToDelete >= 0 && indexToDelete < data.textList.getSize();
    bool integerInvalidToParse = indexToDelete == -1;
    std::stringstream outputString;
    if (integerInvalidToParse) {
        outputString << "invalid index string\n";
    } else if (indexIsValid) {
        auto justDeleted = std::move(data.textList.getItems().at(indexToDelete));
        data.textList.removeItem(indexToDelete);
        outputString << "deleted from " << data.filename << ": \"";
        outputString << justDeleted << "\"\n";
        indexToDelete = -1; // Reset index to invalid again.
    } else {
        outputString << "index " << (indexToDelete + 1) << " is out of range.\n";
    }
    return outputString.str();
}
