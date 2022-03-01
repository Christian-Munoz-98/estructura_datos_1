#include <iostream>

class DoublyNode{
public:
    int value;
    DoublyNode* Previous;
    DoublyNode* Next;

    DoublyNode(int value);
};

DoublyNode::DoublyNode(int value){
    this->value = value;
    Previous = NULL;
    Next = NULL;
}
