#include <iostream>
#include "Functions.h"
#include "CNode.h"
#include "CPath.h"
int main()
{
	CPath playerMap; // Creation of Map
	InitNodes(&playerMap); // Inits all nodes // Passes by address
	while (true)
	{
		EnlargeTextSize(); // Sets console size text
		PrintNumbers(); // UI
		playerMap.PrintPath();
		playerMap.UserMovement(UserInput());
		system("CLS");
	}
};