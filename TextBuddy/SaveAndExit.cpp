#include "stdafx.h"
#include "SaveAndExit.h"

const std::string SaveAndExit::EXIT_KEYWORD = "exit";

bool SaveAndExit::interpret(const App::Command& command) {
    return command == EXIT_KEYWORD;
}

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