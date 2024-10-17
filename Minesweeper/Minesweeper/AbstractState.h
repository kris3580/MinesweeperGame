#pragma once
#include "GameState.h"

class AbstractState
{
public:
    virtual ~AbstractState() = default;

    virtual void update() = 0;

    virtual bool operator==(const AbstractState& other) const = 0;
};
