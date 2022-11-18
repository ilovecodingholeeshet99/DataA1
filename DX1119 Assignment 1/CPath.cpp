#include "CPath.h"

CPath::CPath()
{
    head = nullptr; // Set all to null
    tail = nullptr;
    indicator = nullptr;
}

CNode* CPath::GetHead()
{
    return head;
}

CNode* CPath::GetTail()
{
    return tail;
}

void CPath::AddInitNode(char map) // Functions adding nodes to back of LL, a init node function
{
    if (head == nullptr) // If LL is empty 
    {
        head = new CNode; // Head will auto create 'S' character
        head->SetChar(map);
        head->SetPrevNode(nullptr); // Prev pointer of head will always point to NULL 
        tail = head;
        indicator = head; // Indicator point to head (Init)
    }
    else // If LL is not empty
    {
        CNode* newNode = new CNode;
        newNode->SetChar(map);
        tail->SetNextNode(newNode); // Set tail pointer arrow to point to newNode
        newNode->SetPrevNode(tail); // Set prevNode to point to tail before setting tail to point to the last node
        tail = newNode; // Set tail to point to the latest node
    }
}

void CPath::DeleteNode(CNode* NodeToDelete)
{
    CNode* beforeDel = head; // Create a beforeDel pointer to point to start of LL totraverse LL
    CNode* afterDel = head;
    while (beforeDel->GetNextNode() != NodeToDelete && afterDel->GetNextNode() != NodeToDelete->GetNextNode()) // Go to node before node to delete and node after the one we want to del
    {
        beforeDel = beforeDel->GetNextNode(); // Make beforeDel traverse until before node to delete
        afterDel = afterDel->GetNextNode(); // Make afterDel traverse until after node to delete
    }
    beforeDel->SetNextNode(NodeToDelete->GetNextNode()); // Make temp point to node after the node we want to delete
    afterDel->SetPrevNode(beforeDel);
    delete NodeToDelete; // Delete node to delete
}

void CPath::AddPlayerNode(char w) // Need to check if playerPosition has traversed until the indicator
{
    CNode* temp = head; // 2 temps that point to head
    CNode* temp2;
    while (temp != indicator) // Traverse until temp reaches indicator
    {
        temp = temp->GetNextNode();
    }
    temp2 = temp->GetNextNode(); // Now that temp points to the indicator, set Temp2 to point to temp/indicators next node
    CNode* newNode = new CNode; // Node to add
    newNode->SetChar('w');
    temp->SetNextNode(newNode); // Temp/Indicator next node is the newNode created
    newNode->SetPrevNode(temp); // newNode previous pointer points to the temp/indicator
    newNode->SetNextNode(temp2); // Setting the newNode's new node to point to temp2, which points to indicators old next node
    temp2->SetPrevNode(newNode); // Setting indicators old next node's previous node to point to the newNode created
}

void CPath::DeletePlayerNode()
{
    CNode* temp = head; // Temp pointer to point to node before indicator
    CNode* temp2 = head; // Another temp ptr to point to node after indicator
    while (temp->GetNextNode() != indicator) // While temp's next node is not the indicator
    {
        temp = temp->GetNextNode(); 
    }
    temp2 = indicator->GetNextNode();
    // At the node before the indicator
    temp->SetNextNode(temp2);
    temp2->SetPrevNode(temp);
}


void CPath::PrintPath()
{
    int count = 0; // Init count for when to endl
    CNode* temp = head; // Make temp pointer to traverse through LL
    CNode* start = head;
    while (temp != nullptr) // While LL is still present
    {
        if (temp == tail) // Use == because checks if temp is tail and not if temp is pointing to tail
        {
            std::cout << temp->GetInfo(); // If temp is at the tail, print the last node without the '-'
            break; // No break = infinite loop
        }
        else
        {
            std::cout << temp->GetInfo() << "-"; // Adjacent nodes have '-'
            temp = temp->GetNextNode();
        }
        count += 1;
        if (count == 20) // 20 so end of row does not end with '-'
        {
            count = 0;
            std::cout << std::endl;
            PrintIndicator(start);
            start = temp;
            std::cout << std::endl;
        }
    }
    std::cout << std::endl; // Endl to go to next line after end of LL
    PrintIndicator(start);
    std::cout << std::endl; 
}

void CPath::PrintIndicator(CNode* start) // Prints indicator and locates where indicator is
{
    for (int i = 0; i < 20; i++) // For loop to traverse 20 times through the list
    {
        if (start == indicator) // Check whether pointer traversing through the list has hit the indicator
            std::cout << "^ "; // Print ^ if yes
        else
            std::cout << "  "; // Print space 
        if (start->GetNextNode() != nullptr)
        {
            start = start->GetNextNode();
        }
        else
            break;
    }
}

void CPath::UserMovement(int enter)
{
    if (enter == 1) // If direction
    {
        if (indicator->GetPrevNode() == nullptr)
            return; // Stop player from moving out of map
        indicator = indicator->GetPrevNode();
    }
    else if (enter == 2)
    {
        if (indicator->GetNextNode() == nullptr)
            return;
        indicator = indicator->GetNextNode();
    }
    else if (enter == 3)
    {
        AddPlayerNode('w');
    }
    else if (enter == 4)
    {
        DeletePlayerNode();
    }
}
