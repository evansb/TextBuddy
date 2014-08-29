#pragma once

#include "stdafx.h"
#include "App.h"

// Template class for a feature.
// A feature interprets a command (TCommand) and execute the command on
// a shared state (TState), returning a feedback (TFeedback) in the end.
template<typename TCommand, typename TState, typename TFeedback>
class AbstractFeature {
public:
    AbstractFeature() = default;
    virtual ~AbstractFeature() = default;

    // Parse a command (possibly also modifying some
    // internal state), return true if the command matched
    // or false otherwise.
    virtual bool interpret(const TCommand& command) = 0;

    // Given a shared data (e.g a to-do list), do something with it.
    // Return a feedback (e.g a log of type string of what has been done)
    virtual TFeedback execute(TState&) = 0;
};