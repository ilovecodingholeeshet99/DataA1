#pragma once
#include <iostream>
#include "CNode.h"
class CPath // Linked List
{
private:
	CNode* head;
	CNode* tail;
	CNode* indicator;
public:
	CPath();
	// Getters 
	CNode* GetHead();
	CNode* GetTail();
	// Data manipulation
	void AddNode(char map);
	void DeleteNode(CNode* playerPosition);
	// Printing
	void PrintPath();
	void PrintIndicator(CNode* start);
	//Movement
	void MoveIndicator(int direction);
};

