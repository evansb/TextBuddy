#include "stdafx.h"
#include "SaveAndExit.h"

const std::string SaveAndExit::EXIT_KEYWORD = "exit";

/// A command is match if it is equal to EXIT_KEYWORD
/// \param[command] command to be interpreted.
bool SaveAndExit::interpret(const App::Command& command) {
    return command == EXIT_KEYWORD;
}

/// Write the text list stored in paramter data to the file.
/// and exit the TextBuddy application by modifying the field
/// appIsRunning in the shared data.
/// \param[command]
/// \return Empty string.
App::Feedback SaveAndExit::execute(App::SharedData& data) {
    std::ofstream fileOut(data.filename);
    std::for_each(
        data.textList.begin(),
        data.textList.end(),
        [&fileOut] (TextList::ItemType& item) mutable {
            fileOut << item << "\n";
        }
    );
    data.appIsRunning = false;
    return "";
}