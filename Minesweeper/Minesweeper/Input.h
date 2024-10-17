#pragma once
#include "Cell.h"
#include <iostream>

class Input 
{
private:
    int x;

    int y;

public:
    Input();

    Input(int x, int y);

    Input(const Input& other);

    static Cell GetCoordinates();

    Input& operator=(const Input& other);

    bool operator==(const Input& other) const;
};