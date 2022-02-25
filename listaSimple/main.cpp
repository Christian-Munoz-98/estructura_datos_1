#include <iostream>
#include "ListaEnlazada.h"

using namespace std;

int main()
{
    ListaEnlazada *linkedList = new ListaEnlazada();

    // 43->NULL
    linkedList->InsertarInicio(" MUNDO");

    // 76->43->NULL
    linkedList->InsertarInicio(" HOLA");

    // 76->43->15->NULL
    linkedList->InsertarFinal(" CRUEL");

    // 76->43->15->44->NULL
    linkedList->InsertarFinal(" ADIOS");

    // Print the list element
    cout << "First Printed:" << endl;
    linkedList->ImprimirLista();
    cout << endl;

    // 76->43->15->44->100->NULL
    linkedList->Insertar(4, "JAJAJAJA");

    // 76->43->15->48->44->100->NULL
    linkedList->Insertar(3, "JJEJEJE");

    // 22->76->43->15->48->44->100->NULL
    linkedList->Insertar(0, "JIJIJI");

    // Print the list element
    cout << "Second Printed:" << endl;
    linkedList->ImprimirLista();
    cout << endl;

    // Get value of the second index
    // It should be 43
    cout << "Buscar: " << endl;
    //linkedList->Buscar(" HOLA");
    cout << endl << endl;

    // Remove first element
    cout << "Remover incio:" << endl;
    linkedList->RemoverInicio();
    // 76->43->15->48->44->100->NULL
    cout << "Remover final:" << endl;
    linkedList->RemoverFinal();
    linkedList->ImprimirLista();
    cout << endl;

    // Remove fifth element
    cout << "Remover por busqueda:" << endl;
    //linkedList->Remover("JIJIJI");
    // 76->43->15->48->100->NULL
    linkedList->ImprimirLista();
    cout << endl;

    // Nothing happen
    // 76->43->15->48->100->NULL
    linkedList->ImprimirLista();
    cout << endl;

    cout<<"Tamano de lista: " << linkedList->Tamano();

    return 0;
}
