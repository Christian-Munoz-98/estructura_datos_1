#include <iostream>

class DoublyNode
{
    public:
        int Value;
        DoublyNode* Previous;
        DoublyNode* Next;

        DoublyNode(int value);
};

DoublyNode::DoublyNode(int value)
{
    Value = value;
    Previous = NULL; 
    Next=NULL; 
};