#pragma once
#include <iostream>
class CNode
{
private:
	// Pointer variables for setting character of map
	char* charPointer;
	char playerChar;
	CNode* nextNode;
	CNode* prevNode;
public:
	CNode(); 
	// Getters
	char GetInfo();
	CNode* GetNextNode();
	CNode* GetPrevNode();
	char* GetCharPointer();
	// Setters
	void SetNextNode(CNode* next);
	void SetChar(char newChar);
	void SetPrevNode(CNode* prev);
};

