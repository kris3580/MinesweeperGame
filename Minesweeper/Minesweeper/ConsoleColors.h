#pragma once
#include <windows.h>

static class ConsoleColors
{

private:
    int backgroundColor;

    int textColor;

public:
	static void SetColors(int backgroundColor, int textColor);

	static void ResetColors();

    ConsoleColors();

    ConsoleColors(int bgColor, int txtColor);
    
    ConsoleColors(const ConsoleColors& other);

    ConsoleColors& operator=(const ConsoleColors& other);

    bool operator==(const ConsoleColors& other) const;
};
