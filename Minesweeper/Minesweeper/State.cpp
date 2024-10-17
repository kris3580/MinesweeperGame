#include "State.h"

GameState State::gameState(GameState::Ongoing);

State::State() {}

State::State(const GameState& initialState)
{
    gameState = initialState;
}

State::State(const State& other)
{
    gameState = other.gameState;
}

State& State::operator=(const State& other)
{
    if (this != &other)
    {
        gameState = other.gameState;
    }
    return *this;
}


bool State::operator==(const AbstractState& other) const
{
    const State* otherState = dynamic_cast<const State*>(&other);
    return otherState != nullptr && gameState == otherState->gameState;
}

void State::update()
{

}

