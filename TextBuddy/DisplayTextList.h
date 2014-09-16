#pragma once
#include "stdafx.h"

#include "App.h"
#include "AbstractFeature.h"
#include "TextList.h"

/// TextBuddy feature to pretty print a numbered ordering of every item in the TextList.
class DisplayTextList : public App::Feature {
public:
    /// Default constructor.
    DisplayTextList() = default;

    /// Default destructor.
    virtual ~DisplayTextList() = default;

    /// A command is match if it is equal to DISPLAY_KEYWORD
    /// \param[command] command to be interpreted.
    bool interpret(const App::Command& command) override;

    /// Construct a string representation of the TextList stored in the
    /// parameter data.
    /// \param [data] Shared data passed to this method.
    /// \return pretty printed text list
    App::Feedback execute(App::SharedData& data) override;

private:
    /// \see interpret
    const static std::string DISPLAY_KEYWORD;
};