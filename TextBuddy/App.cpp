#include "stdafx.h"

#include "AddItem.h"
#include "DeleteItem.h"
#include "DisplayTextList.h"
#include "ClearItems.h"
#include "SaveAndExit.h"

#include "App.h"

/// List of all features.
std::vector<std::shared_ptr<App::Feature>> App::features;

/// Message printed when the application starts.
const std::string App::WELCOME_MESSAGE = "Welcome to TextBuddy. %s is ready for use\n";

/// Message printed during each beginning of command invocation.
const std::string App::COMMAND_PROMPT  = "command: ";

/// Message printed when command is invalid.
const std::string App::COMMAND_INVALID = "Invalid command, please try again\n";

/// Push all the features to feature list.
void App::loadFeatures() {
    App::features.push_back(std::make_shared<AddItem>());
    App::features.push_back(std::make_shared<DeleteItem>());
    App::features.push_back(std::make_shared<DisplayTextList>());
    App::features.push_back(std::make_shared<ClearItems>());
    App::features.push_back(std::make_shared<SaveAndExit>());
}

/// Construct new empty shared data.
/// \param[filename] The name of the file used by this instance of TextBuddy.
/// \return A new shared data
App::SharedData App::newSharedData(const std::string& filename) {
    App::SharedData sharedData(filename);
    return std::move(sharedData);
}

/// Deserialize file to text list.
void App::readFileToList(
        const std::string& filename,
        TextList& textList) {
    std::ifstream fileIn(filename);
    // Read and append to list line by line
    std::string line;
    while(getline(fileIn, line)) {
        textList.addItem(line);
        // Remove trailing '\n' character naturally
        fileIn.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}


/// Given a user input, find all features that matches and execute it using the
/// shared data.
/// Precondition : Has loaded features using loadFeatures().
/// \param[userInput] One line user input. 
/// \param[sharedData] Shared data with which the feature will be executed upon.
/// \return true if there is at least one feature that matches.
bool App::interpretAndExecute(
        const std::string& userInput, 
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

/// Run the application with a given filename.
/// \param[filename] The name of the file used by this instance of TextBuddy.
void App::runWithFile(const std::string& filename) {
    SharedData sharedData = newSharedData(filename);
    loadFeatures();
    readFileToList(filename, sharedData.textList);
    printf(WELCOME_MESSAGE.c_str(), filename.c_str());

    // Get input from user, interpret, execute, repeat
    // Until one feature successfuly mutate appIsRunning to false.
    std::string userInput;
    while (sharedData.appIsRunning) {
        printf(COMMAND_PROMPT.c_str());
        std::getline(std::cin, userInput);
        if (!interpretAndExecute(userInput, sharedData)) {
            printf(COMMAND_INVALID.c_str());
        }
    }
}