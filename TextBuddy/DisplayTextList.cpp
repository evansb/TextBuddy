#include "stdafx.h"
#include "DisplayTextList.h"

const std::string DisplayTextList::DISPLAY_KEYWORD = "display";

bool DisplayTextList::interpret(const App::Command& command) {
    return command == DISPLAY_KEYWORD;
}

App::Feedback DisplayTextList::execute(App::SharedData& data) {
    std::stringstream feedback;
    if (data.textList.isEmpty()) {
        feedback << data.filename + " is empty\n";
    } else {
        int counter = 1;
        std::for_each(
            data.textList.begin(),
            data.textList.end(),
            [&] (TextList::ItemType& item) {
                feedback << counter << ". " << item << "\n";
                ++counter;
            }
        );
    }
    return feedback.str();
}