#include <iostream>
class Node
{
public:
    int Value;
    Node * Next;

    Node(int value);
};

Node::Node(int value){
    Value = value;
    Next = NULL;
}


