#pragma once

#include "stdafx.h"

#include "AbstractFeature.h"
#include "TextList.h"

class App {
    /* A singleton that represents a running instance of the TextBuddy application.
       This class manages a shared TextList object and a list of Features object.
       I/O also should in general only be done here. */
public:
    typedef const std::string& Command;
    typedef struct SharedData {
        const std::string& filename;
        TextList textList;
        bool appIsRunning = true;
        SharedData(const std::string& filename) : filename(filename), textList(TextList()) {};
    } SharedData;
    typedef std::string Feedback;
    typedef AbstractFeature<Command, SharedData, Feedback> Feature;

    static const std::string WELCOME_MESSAGE;
    static const std::string COMMAND_PROMPT;
    static std::vector<std::shared_ptr<Feature>> features;
    static SharedData newSharedData(const std::string& filename);
    static void runWithFile(const std::string& filename);
    static void loadFeatures();

    App() = delete;
    ~App() = delete;
};