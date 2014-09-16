#include "stdafx.h"

#include "DeleteItem.h"

/// \see interpret
const std::string DeleteItem::DELETE_KEYWORD = "delete";

/// A valid command begins with DELETE_KEYWORD, followed by an integer
/// as the index of the item to delete, separated by single space.
/// Stores the index internally in indexToDelete.
/// \param[command] command to be interpreted.
/// \return true if a valid command, false otherwise
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

/// Precondition : Has interpreted and stored the index in indexToDelete.
/// Checks if indexToDelte is a valid index, if not return an error message.
/// Otherwise delete the item from the text list stored in data.
/// \param[data] Shared data passed to this method.
/// \return A message telling that delete is un/successful.
App::Feedback DeleteItem::execute(App::SharedData& data) {
    auto deletedItem = std::move(data.textList.getAt(indexToDelete));
    
    // Check index validity.
    bool indexIsValid = indexToDelete >= 0 && indexToDelete < data.textList.getSize();
    bool integerInvalidToParse = (indexToDelete == -1);

    // Delete the item.
    if (indexIsValid) {
        data.textList.removeItem(indexToDelete);
        indexToDelete = -1; // Reset index to invalid again.
    }

    // Build the feedback string.
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
