#include "stdafx.h"

#include "App.h"
#include "AddItem.h"
#include "DeleteItem.h"
#include "DisplayTextList.h"
#include "ClearItems.h"
#include "SaveAndExit.h"

const std::string App::WELCOME_MESSAGE = "Welcome to TextBuddy. %s is ready for use\n";
const std::string App::COMMAND_PROMPT = "command: ";
std::vector<std::shared_ptr<App::Feature>> App::features;

void App::loadFeatures() {
    App::features.push_back(std::make_shared<AddItem>());
    App::features.push_back(std::make_shared<DeleteItem>());
    App::features.push_back(std::make_shared<DisplayTextList>());
    App::features.push_back(std::make_shared<ClearItems>());
    App::features.push_back(std::make_shared<SaveAndExit>());
}

App::SharedData App::newSharedData(const std::string& filename) {
    App::SharedData sharedData(filename);
    std::ifstream fileIn(filename);
    std::string line;
    while(getline(fileIn, line)) {
        sharedData.textList.addItem(line);
        // Remove trailing '\n' character naturally
        fileIn.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return std::move(sharedData);
}

void App::runWithFile(const std::string& filename) {
    App::loadFeatures();
    SharedData sharedData = App::newSharedData(filename);

    std::string userInput;

    printf(WELCOME_MESSAGE.c_str(), filename.c_str());
    while (sharedData.appIsRunning) {
        printf(COMMAND_PROMPT.c_str());
        std::getline(std::cin, userInput);
        std::for_each(begin(App::features), end(App::features),
            [userInput, &sharedData](std::shared_ptr<Feature> feature) mutable {
            if (feature->interpret(userInput)) {
                std::cout << feature->execute(sharedData);
            }
        });
    }
}