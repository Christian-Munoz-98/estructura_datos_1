#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    // NULL
    ListaEnlazada *linkedList = new ListaEnlazada();

    // 43->NULL
    linkedList->InsertarInicio(43);

    // 76->43->NULL
    linkedList->InsertarInicio(76);

    // 76->43->15->NULL
    linkedList->InsertarFinal(15);

    // 76->43->15->44->NULL
    linkedList->InsertarFinal(44);

    // Print the list element
    cout << "First Printed:" << endl;
    linkedList->ImprimirLista();
    cout << endl;

    // 76->43->15->44->100->NULL
    linkedList->Insertar(4, 100);

    // 76->43->15->48->44->100->NULL
    linkedList->Insertar(3, 48);

    // 22->76->43->15->48->44->100->NULL
    linkedList->Insertar(0, 22);

    // Print the list element
    cout << "Second Printed:" << endl;
    linkedList->ImprimirLista();
    cout << endl;

    // Get value of the second index
    // It should be 43
    cout << "Get value of the second index:" << endl;
    Nodo * get = linkedList->Get(2);
    if(get != NULL)
        cout << get->Valor;
    else
        cout << "not found";
    cout << endl << endl;

    // Find the position of value 15
    // It must be 3
    cout << "The position of value 15:" << endl;
    int srch = linkedList->Buscar(15);
    cout << srch << endl << endl;

    // Remove first element
    cout << "Remove the first element:" << endl;
    linkedList->Remover(0);
    // 76->43->15->48->44->100->NULL
    linkedList->ImprimirLista();
    cout << endl;

    // Remove fifth element
    cout << "Remove the fifth element:" << endl;
    linkedList->Remover(4);
    // 76->43->15->48->100->NULL
    linkedList->ImprimirLista();
    cout << endl;

    // Remove tenth element
    cout << "Remove the tenth element:" << endl;
    linkedList->Remover(9);
    // Nothing happen
    // 76->43->15->48->100->NULL
    linkedList->ImprimirLista();
    cout << endl;

    return 0;
}
