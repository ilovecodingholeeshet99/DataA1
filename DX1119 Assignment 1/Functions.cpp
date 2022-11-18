#include "Functions.h"

void PrintNumbers()
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << i <<  "-";
	}
	for (int i = 0; i < 10; i++)
	{
		if (i == 9)
		{
			std::cout << i;
		}
		else
			std::cout << i << "-";
	}
	std::cout << std::endl;
	for (int i = 0; i <= 39; i++)
	{
		std::cout << "-";
	}
	std::cout << std::endl;
}

void InitNodes(CPath* map)
{
	map->AddInitNode('S'); // Entry map node
	for (int i = 0; i <= 50; i++)
	{
		map->AddInitNode('o');
	}
	map->AddInitNode('E'); // End map node
}

void EnlargeTextSize()
{
	static CONSOLE_FONT_INFOEX  fontex;
	fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFontEx(hOut, 0, &fontex);
	fontex.FontWeight = 700;
	fontex.dwFontSize.X = 24;
	fontex.dwFontSize.Y = 24;
	SetCurrentConsoleFontEx(hOut, NULL, &fontex);
}

int UserInput()
{
	int temp;
	std::cout << "Choice->Bck(1) Fwd(2) AddNode(3) DelNode(4)" << std::endl;
	std::cin >> temp;
	return temp;
}


