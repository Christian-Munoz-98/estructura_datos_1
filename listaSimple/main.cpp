#include <iostream>
#include "ListaEnlazada.h"

using namespace std;

int main()
{
    ListaEnlazada *linkedList = new ListaEnlazada();
    linkedList->InsertarInicio("HOLA");
    linkedList->InsertarInicio("MUNDO");
    linkedList->InsertarFinal(" CRUEL");
    linkedList->InsertarFinal("ADIOS");
    linkedList->Insertar(4, "JAJAJAJA");
    linkedList->Insertar(3, "JJEJEJE");
    linkedList->Insertar(0, "JIJIJI");

    linkedList->ImprimirLista();
    cout << "Buscar: " << endl;
    linkedList->Buscar("ADIOS");
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
    linkedList->Remover("ADIOS");
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
