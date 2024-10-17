#pragma once
#include <random>

static class Random
{
private:
    static std::random_device rd;

    static std::mt19937 gen;

    int minValue;

    int maxValue;

public:
    Random();

    Random(int a, int b);

    Random(const Random& other);

	static int GetRandomNumber(int a, int b);

    Random& operator=(const Random& other);

    bool operator==(const Random& other) const;
};