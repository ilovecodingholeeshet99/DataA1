#include "CNode.h"

CNode::CNode()
{
    playerChar = 'S';
    charPointer = &playerChar; // Temp playerChar to init charPointer
    *charPointer = 'S';
    nextNode = nullptr;
    prevNode = nullptr;
}

char CNode::GetInfo()
{
    return *charPointer;
}

CNode* CNode::GetNextNode()
{
    return nextNode;
}

CNode* CNode::GetPrevNode()
{
    return prevNode;
}

void CNode::SetNextNode(CNode* next)
{
    nextNode = next; // CNode nextNode will point to CNode pointer in parameter
}

void CNode::SetChar(char newChar)
{
    *charPointer= newChar; // Set value of charPtr to whatever character we put in
}

void CNode::SetPrevNode(CNode* prevPointer)
{
    prevNode = prevPointer; // prevNode will point to whatever CNode* we put in
}

char* CNode::GetCharPointer()
{
    return charPointer;
}
