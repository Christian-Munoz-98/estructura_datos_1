#include <iostream>
#include "DoublyNode.h"

using namespace std;

class DoublyLinkedList{
private:
    int m_count;

public:
    DoublyNode* Head;
    DoublyNode* Tail;
    
    DoublyLinkedList();

    DoublyNode* Get(int);

    void InsertHead(int);
    void InsertTail(int);
    void Insert(int,int);

    int Search(int);

    void RemoveHead();
    void RemoveTail();
    void Remove(int);

    int Count();
    void PrintList();
    void PrintListBackward();
};

DoublyLinkedList::DoublyLinkedList(){
    m_count = 0;
    Head = NULL;
    Tail = NULL;
}

DoublyNode* DoublyLinkedList::Get(int index){
    // Check if the index is out of bound
    if(index < 0 || index > m_count)
        return NULL;

    // Start from the Head
    DoublyNode* node = Head;

    // Iterate through the linked list elements
    // until it finds the selected index
    for(int i = 0; i < index; ++i){
        node = node->Next;
    }

    // Simply return the node result
    return node;
}

void DoublyLinkedList::InsertHead(int val){
    // Create a new Node
    DoublyNode* node = new DoublyNode(val);

    // The current Head will no longer become a Head
    // so the Next pointer of the new Node will
    // point to the current Head
    node->Next = Head;

    // If the current Head is exist,
    // the previous pointer of the current Head
    // should point to the node
    if(Head != NULL)
        Head->Previous = node;

    // The new Node now become the Head
    Head = node;

    // If the linked list is empty
    // The Tail is also the Head
    if(m_count == 0)
        Tail = Head;

    // One element is added
    m_count++;
}

void DoublyLinkedList::InsertTail(int val){
    // If the linked list is empty,
    // just simply invoke InsertHead()
    if(m_count == 0){
        InsertHead(val);
        return;
    }

    // Create a new Node
    DoublyNode* node = new DoublyNode(val);

    // The current Tail will no longer become a Tail
    // so the Next pointer of the current Tail will
    // point to the new node
    Tail->Next = node;

    // Also, the previous pointer of the new node
    // should point to the current Tail
    node->Previous = Tail;

    // The new Node now become the Tail
    Tail = node;

    // One element is added
    m_count++;
}

void DoublyLinkedList::Insert(int index, int val){
    // Check if the index is out of bound
    if(index < 0 || index > m_count)
        return;

    // If inserting a new Head
    if(index == 0){
        InsertHead(val);
        return;
    }
    // If inserting a new Tail
    else if(index == m_count){
        InsertTail(val);
        return;
    }

    // Start to find previous node
    // from the Head
    DoublyNode* prevNode = Head;

    // Traverse the elements until
    // the selected index is found
    for(int i = 0; i < index - 1; ++i){
        prevNode = prevNode->Next;
    }

    // Create the next node which is
    // the element after previous node
    DoublyNode* nextNode = prevNode->Next;

    // Create a new node
    DoublyNode* node = new DoublyNode(val);

    // Insert this new node between
    // the previous node and the next node
    node->Next = nextNode;
    node->Previous = prevNode;
    prevNode->Next = node;
    nextNode->Previous = node;

    // One element is added
    m_count++;
}

int DoublyLinkedList::Search(int val){
    // If LinkedList is empty,
    // just return NOT_FOUND
    if(m_count == 0)
        return -1;

    // Need to count the index
    int index = 0;

    // Traverse from the Head node
    DoublyNode* node = Head;

    // Traverse until the selected value
    // is matched with the value
    // of the current position,
    while(node->value != val)
    {
        index++;
        node = node->Next;

        // This will happen
        // if the selected value
        // is not found
        if(node == NULL){
            return -1;
        }
    }

    return index;
}

void DoublyLinkedList::RemoveHead(){
    // Do nothing if list is empty
    if(m_count == 0)
        return;

    // Save the current Head
    // to a new node
    DoublyNode* node = Head;

    // Point the Head Pointer
    // to the element next to the current Head
    Head = Head->Next;

    // Now it's safe to remove
    // the first element
    delete node;

    // If there's still any element in the list,
    // the previous pointer of the Head
    // should point to NULL
    if(Head != NULL)
        Head->Previous = NULL;

    // One element is removed
    m_count--;
}

void DoublyLinkedList::RemoveTail(){
    // Do nothing if list is empty
    if(m_count == 0)
        return;

    // If List element is only one
    // just simply call RemoveHead()
    if(m_count == 1){
        RemoveHead();
        return;
    }

    // Save the current Tail
    // to a new node
    DoublyNode* node = Tail;

    // Point the Tail Pointer
    // to the element before the current Tail
    Tail = Tail->Previous;

    // Set the new Next pointer of the new Tail
    // to NULL since we are going to delete
    // the last element
    Tail->Next = NULL;

    // Now it's safe to remove
    // the last element
    delete node;

    // One element is removed
    m_count--;
}

void DoublyLinkedList::Remove(int index){
    // Do nothing if list is empty
    if(m_count == 0)
        return;

    // Do nothing if index is out of bound
    if(index < 0 || index >= m_count)
        return;

    // If removing the current Head
    if(index == 0){
        RemoveHead();
        return;
    }
    // If removing the current Tail
    else if(index == m_count - 1){
        RemoveTail();
        return;
    }

    // Start to traverse the list
    // from the Head
    DoublyNode* prevNode = Head;

    // Find the element before
    // the selected index
    for(int i = 0; i < index - 1; ++i){
        prevNode = prevNode->Next;
    }

    // The removed element is after
    // the prevNode
    DoublyNode* node = prevNode->Next;

    // The nextNode will be the neighbor of
    // prevNode if the node is removed
    DoublyNode* nextNode = node->Next;

    // Link the prevNode to nextNode
    prevNode->Next = nextNode;
    nextNode->Previous = prevNode;

    // It's now safe to remove
    // the selected index element
    delete node;

    // One element is removed
    m_count--;
}

int DoublyLinkedList::Count(){
    return m_count;
}

void DoublyLinkedList::PrintList(){
    DoublyNode* node = Head;

    while(node != NULL){
        cout << node->value << " -> ";
        node = node->Next;
    }

    cout << "NULL" << endl;
}

void DoublyLinkedList::PrintListBackward(){
    DoublyNode* node = Tail;

    while(node != NULL){
        cout << node->value << " -> ";
        node = node->Previous;
    }

    cout << "NULL" << std::endl;
}