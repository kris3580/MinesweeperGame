#include "Random.h"

int Random::GetRandomNumber(int a, int b) 
{
    static std::random_device rd;  
    static std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> distr(a, b); 

    return distr(gen); 
}