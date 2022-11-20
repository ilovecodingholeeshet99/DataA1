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

void CPath::AddPlayerNode(char w) // Need to check if playerPosition has traversed until the indicator
{
    CNode* temp = head; // 2 temps that point to head
    CNode* temp2;
    if (indicator == tail) // If player adds when indicator at node 'E'
    {
        CNode* newNode = new CNode; // Allocate memory for newNode
        if (indicator->GetPrevNode() == nullptr)
            indicator->SetChar('S');
        else
            indicator->SetChar('w'); // Set old tail char to be 'o
            newNode->SetChar('E'); // Set char of newNode to be 'E', end of list
            indicator->SetNextNode(newNode); // Indicator next node points to the tail/newNode
            newNode->SetPrevNode(indicator); // prevNode of tail/newNode points to old tail indicator
            newNode->SetNextNode(nullptr);
            tail = newNode; // Set tail to point to the newNode denoting end of LL
    }
    //{
    //  /*  else if (indicator->GetNextNode() == nullptr && indicator->GetPrevNode() == nullptr)
    //    {
    //        if (indicator->GetInfo() == 'S')
    //        {
    //            indicator->SetChar('S');
    //            CNode* newNode = new CNode;
    //            newNode->SetChar('E');
    //            indicator->SetNextNode(newNode);
    //            newNode->SetPrevNode(indicator);
    //            tail = newNode;
    //            head = indicator;
    //        }
    //        else if (indicator->GetInfo() == 'E')
    //        { 
    //            CNode* newNode = new CNode;
    //            newNode->SetChar('E');
    //            indicator->SetNextNode(newNode);
    //            newNode->SetPrevNode(indicator);
    //            tail = newNode;
    //        }
    //    }*/
    //}
    else if (head->GetNextNode() == nullptr)
    {
        AddInitNode('E'); // Init a new 'w' node if there is only one node in LL left
    }
    else 
    {
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
}

void CPath::DeletePlayerNode()
{
    CNode* temp = head; // Temp pointer to point to indicator
    CNode* temp2 = head; // Another temp ptr to point to node before indicator
    CNode* temp3 = head; // Temp pointer to point to node after indicator
    if (head->GetNextNode() == nullptr) // If head's link is nullptr, return 
        return; 
    else if (indicator == head) // If player deletes at the head, check if indicator is at head first
    {
        CNode* todel = indicator;
        indicator = indicator->GetNextNode(); // Point indicator to the node next to it
        delete todel;
        indicator->SetChar('S');
        indicator->SetPrevNode(nullptr); // Set previous node of indicator to nullptr because node next to indicator is now new head
        head = indicator; // Set head to point to indicator as node beside indicator is new start of LL
    }
    else if (indicator == tail) // If player deletes at the end of the list E
    {
        CNode* todel = indicator;
        indicator = indicator->GetPrevNode(); // Set the indicator to point to the node beforehand
        delete todel;
        indicator->SetChar('E');
        indicator->SetNextNode(nullptr); // Previous node of indicator must point to nullptr to denote end of LL
        tail = indicator; // Set tail to point to indicator so that indicator is pointing to the last node of the LL
    }
    else
    {
        while (temp != indicator) 
        {
            temp = temp->GetNextNode(); // Keep traversing until indicator
        }
        temp2 = temp->GetPrevNode(); // Temp2 points to node before indicator
        temp3 = temp->GetNextNode(); // Temp3 points to node after indicator
        temp2->SetNextNode(temp3); // Node before indicator next node points to node after indicator
        temp3->SetPrevNode(temp2); // Prevnode of node after indicator points to node before indicator instead of indicator 
        delete indicator;
        indicator = temp3; // Set indicator to point to node after indicator
    }
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
            count = 0; // Reset count to zero so PrintPath checks all rows to endl
            std::cout << std::endl;
            PrintIndicator(start);
            start = temp;
            std::cout << std::endl;
        }
    }
    std::cout << std::endl; // Endl to go to next line after end of LL
    PrintIndicator(start); // Print Indicator again so that indicator prints on the third row
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
        if (start->GetNextNode() != nullptr) // Traverse the LL
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
        if (head->GetNextNode() == nullptr) // Need to check if player tries to move forward when there is only 1 node in the LL
            return;
        if (indicator->GetNextNode() == nullptr)
        {
            indicator = tail->GetPrevNode(); // Indicator will point to the previous last node IF player moves after the End(E) node
            tail->SetChar('o'); // Set char to 'o' if player moves forward after reaching E
            AddInitNode('E'); // Keep adding E at the back if player keeps moving forward past E
        }
        indicator = indicator->GetNextNode();
    }
    else if (enter == 3) // AddNode option 3
    {
        AddPlayerNode('w'); // Add 'w' if player want to add node
    }
    else if (enter == 4) // DeleteNode option 4
    {   
        DeletePlayerNode();
    }
    else
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
