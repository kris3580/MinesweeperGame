#pragma once
#include <windows.h>

static class ConsoleColors
{
public:
	static void SetColors(int backgroundColor, int textColor);

	static void ResetColors();
};
