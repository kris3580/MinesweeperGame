#pragma once
#include "GameState.h"
#include "AbstractState.h"

class State : public AbstractState
{
public:
    State();

    State(const GameState& initialState);

    State(const State& other);

    static GameState gameState;

    State& operator=(const State& other);

    void update() override;

    bool operator==(const AbstractState& other) const override;
};
