#include "Random.h"

Random::Random() : minValue(0), maxValue(100) {}

Random::Random(int a, int b) : minValue(a), maxValue(b) {}

Random::Random(const Random& other)
    : minValue(other.minValue), maxValue(other.maxValue)
{}


int Random::GetRandomNumber(int a, int b) 
{
    static std::random_device rd;  
    static std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> distr(a, b); 

    return distr(gen); 
}

Random& Random::operator=(const Random& other)
{
    if (this != &other)
    {
        minValue = other.minValue;
        maxValue = other.maxValue;
    }
    return *this;
}

bool Random::operator==(const Random& other) const
{
    return minValue == other.minValue && maxValue == other.maxValue;
}
