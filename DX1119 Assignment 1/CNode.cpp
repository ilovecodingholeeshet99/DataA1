#include "CNode.h"

CNode::CNode()
{
    charPointer = &playerChar;
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
    *charPointer= newChar;
 }

void CNode::SetPrevNode(CNode* prevPointer)
{
    prevNode = prevPointer; // prevNode will point to whatever CNode* we put in
}

char* CNode::GetCharPointer()
{
    return charPointer;
}
