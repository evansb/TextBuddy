#pragma once

#include "stdafx.h"

#include "AbstractFeature.h"
#include "TextList.h"

/// A singleton class that represents a running instance of the TextBuddy application.
/// This class keeps the shared data and a list of features supported in TextBuddy.
/// Whenever possible, I/O to stdin/sdout should in general only be done here.
class App {
    friend class TestAddItem;
    friend class TestClearItems;
    friend class TestDeleteItem;
	friend class TestSortTextList;
	friend class TestSearchTextList;
public:
    // Command that will be interpreted by feature is string.
    typedef const std::string& Command;

    /// Shared data that will be passed to features during execution.
    typedef struct SharedData {
        const std::string& filename;
        TextList textList;
        bool appIsRunning = true;
        SharedData(const std::string& filename) : filename(filename), textList(TextList()) {};
    } SharedData;

    /// Feedback after the execution of each features is a string.
    typedef std::string Feedback;
 
    /// Define the TextBuddy feature.
    typedef AbstractFeature<Command, SharedData, Feedback> Feature;

private:
    /// Message printed when the application starts.
    static const std::string WELCOME_MESSAGE;

    /// Message printed during each beginning of command invocation.
    static const std::string COMMAND_PROMPT;

    /// Message printed when command is invalid.
    static const std::string COMMAND_INVALID;

    /// Contains all features.
    static std::vector<std::shared_ptr<Feature>> features;

private:
    /// Push all the features to feature list.
    static void loadFeatures();

    /// Construct new empty shared data.
    /// \param[filename] The name of the file used by this instance of TextBuddy.
    /// \return A new shared data
    static SharedData newSharedData(const std::string& filename);

    /// Deserialize file to text list.
    static void readFileToList(const std::string& filename, TextList& textList);

    /// Given a user input, find all features that matches and execute it using the
    /// shared data.
    /// Precondition : Has loaded features using loadFeatures().
    /// \param[userInput] One line user input. 
    /// \param[sharedData] Shared data with which the feature will be executed upon.
    /// \return true if there is at least one feature that matches.
    static bool interpretAndExecute(const std::string& userInput, App::SharedData& sharedData);

public:
    /// Run the application with a given filename.
    /// \param[filename] The name of the file used by this instance of TextBuddy.
    static void runWithFile(const std::string& filename);

    /// Singleton, no constructor.
    App() = delete;

    /// Default destructor.
    ~App() = default;
};