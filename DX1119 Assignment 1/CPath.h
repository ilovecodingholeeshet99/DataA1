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
	// ------------ Getters ----------- 
	CNode* GetHead();
	CNode* GetTail();
	// ---------- Data manipulation --------
	void AddInitNode(char map);
	void DeleteNode(CNode* playerPosition);
	void AddPlayerNode(char w); // AddPlayerNode function handles adding nodes whenever user presses 3
	void DeletePlayerNode(); // DeletePlayerNode function deletes the node whereever the player's indicator is
	// ------------- Printing -----------
	void PrintPath();
	void PrintIndicator(CNode* start);
	// ------------- Movement -----------
	void UserMovement(int direction);
};

