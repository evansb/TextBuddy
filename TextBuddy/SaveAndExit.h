#pragma once
#include "stdafx.h"

#include "App.h"
#include "AbstractFeature.h"
#include "TextList.h"

/// TextBuddy feature to write the list to a text file and exit the program
class SaveAndExit : public App::Feature {
public:
    /// Default constructor.
    SaveAndExit() = default;

    /// Default destructor.
    virtual ~SaveAndExit() = default;
    
    /// A command is match if it is equal to EXIT_KEYWORD
    /// \param[command] command to be interpreted.
    bool interpret(const App::Command& command) override;

    /// Write the text list stored in paramter data to the file.
    /// and exit the TextBuddy application by modifying the field
    /// appIsRunning in the shared data.
    /// \param[command]
    /// \return Empty string.
    App::Feedback execute(App::SharedData& data) override;

private:
    /// \see interpret.
    const static std::string EXIT_KEYWORD;
};