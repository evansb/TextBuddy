#include "stdafx.h"

#include "App.h"
#include "AddItem.h"
#include "DeleteItem.h"
#include "DisplayTextList.h"
#include "ClearItems.h"
#include "SaveAndExit.h"

const std::string App::WELCOME_MESSAGE = "Welcome to TextBuddy. %s is ready for use\n";
const std::string App::COMMAND_PROMPT = "command: ";
const std::string App::COMMAND_INVALID = "Invalid command, please try again\n";

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
    return std::move(sharedData);
}

void readFileToList(
        const std::string& filename,
        TextList& textList) {
    std::ifstream fileIn(filename);
    std::string line;
    while(getline(fileIn, line)) {
        textList.addItem(line);
        // Remove trailing '\n' character naturally
        fileIn.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

bool interpretAndExecute(
        std::string& userInput, 
        App::SharedData& sharedData) {
    bool isExecuting = false;
    std::for_each(
        App::features.begin(),
        App::features.end(),
        [&] (std::shared_ptr<App::Feature> feature) {
            if (feature->interpret(userInput)) {
                std::cout << feature->execute(sharedData);
                isExecuting = true;
            }
        }
    );
    return isExecuting;
}
              
void App::runWithFile(const std::string& filename) {
    SharedData sharedData = newSharedData(filename);
    loadFeatures();
    readFileToList(filename, sharedData.textList);
    printf(WELCOME_MESSAGE.c_str(), filename.c_str());

    std::string userInput;
    while (sharedData.appIsRunning) {
        printf(COMMAND_PROMPT.c_str());
        std::getline(std::cin, userInput);
        if (!interpretAndExecute(userInput, sharedData)) {
            printf(COMMAND_INVALID.c_str());
        }
    }
}