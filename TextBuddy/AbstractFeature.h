
#pragma once

#include "stdafx.h"

#include "App.h"

template<typename C, typename S, typename F>
class AbstractFeature {
    /* Template class for a feature.
     * A feature interprets a command (C) and execute the command on
     * a shared state (S), returning a feedback (F) in the end.
     */
public:
    /* Parse a command (possibly also modifying some
     * internal state), return true if the command matched
     * or false otherwise.
     */
    virtual bool interpret(const C& command) = 0;

    /* Given a shared data (e.g a to-do list), do something with it.
     * Return a feedback (e.g a log of type string of what has been done) */
    virtual F execute(S&) = 0;

    AbstractFeature() = default;
    virtual ~AbstractFeature() = default;
};