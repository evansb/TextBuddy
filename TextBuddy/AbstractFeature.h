#pragma once

#include "stdafx.h"
#include "App.h"

/// Template class for a feature.
/// A feature interprets a command (TCommand) and execute the command on
/// a shared state (TState), returning a feedback (TFeedback) in the end.
template<typename TCommand, typename TState, typename TFeedback>
class AbstractFeature {
public:
    /// Default constructor.
    AbstractFeature() = default;

    /// Default destructor.
    virtual ~AbstractFeature() = default;

    /// Parse a command (and possibly modifying some internal state)
    /// The semantics of true and false is given to the programmer.
    ///
    /// \param[command] A command type variable to interpret.
    /// \return Either true or false, which is left to the programmer.
    virtual bool interpret(const TCommand& command) = 0;

    /// Execute the feature on a shared data and return a feedback.
    /// For instance, in REPL context, TFeedback can be a string.
    ///
    /// \param[execute] A shared data to execute the feature upon.
    /// \return A variable of TFeedback type.
    virtual TFeedback execute(TState&) = 0;
};