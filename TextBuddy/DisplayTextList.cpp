#include "stdafx.h"
#include "DisplayTextList.h"

const std::string DisplayTextList::DISPLAY_KEYWORD = "display";

/* Command must be exactly "display" (i.e "display" with trailing
   spaces is ignored.
   */
bool DisplayTextList::interpret(const App::Command& command) {
    return command == DISPLAY_KEYWORD;
}

App::Feedback DisplayTextList::execute(App::SharedData& data) {
    std::stringstream stream;
    if (data.textList.isEmpty()) {
        stream << data.filename + " is empty\n";
    } else {
        int counter = 1;
        std::for_each(data.textList.begin(), data.textList.end(),
            [&counter, &stream](TextList::ItemType& item) mutable {
                stream << counter << ". " << item << "\n";
                ++counter;
        });
    }
    return stream.str();
}