#include <iostream>
#include "ListaEnlazada.h"

using namespace std;

int main()
{
    ListaEnlazada *linkedList = new ListaEnlazada();
    int index;
    bool confirmation;

    /*cout << "Buscar: " << endl;
    index = linkedList->Buscar("ADIOS");
    if(index==-1)
        cout << "Elemento no encontrado..." << endl;
    else
        cout << "ADIOS: Encontrado en el indice " << index << endl;
    cout << endl << endl;
    */

    linkedList->InsertarInicio("HOLA");
    linkedList->InsertarInicio("MUNDO");
    linkedList->InsertarFinal(" CRUEL");
    linkedList->InsertarFinal("ADIOS");
    linkedList->Insertar(4, "JAJAJAJA");
    linkedList->Insertar(3, "JJEJEJE");
    linkedList->Insertar(0, "JIJIJI");

    linkedList->ImprimirLista();
    /*cout << "Buscar: " << endl;
    index = linkedList->Buscar("SDFDGFSD");
    if(index==-1)
        cout << "Elemento no encontrado..." << endl;
    else
        cout << "ADIOS: Encontrado en el indice " << index << endl;
    cout << endl << endl;
    */
    
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
    confirmation = linkedList->Remover(linkedList->Buscar("ADIOS"));
    if(!confirmation)
        cout << "Elemento no encontrado..." << endl;
    else
        cout << "Elemento eliminado con exito"<< endl;
    cout << endl << endl;
    // 76->43->15->48->100->NULL
    linkedList->ImprimirLista();
    cout << endl;

    // Nothing happen
    // 76->43->15->48->100->NULL
    linkedList->ImprimirLista();
    cout << endl;

    cout<<"Tamano de lista: " << linkedList->Tamano() << endl;
    cout<<"Primer elemento: " << linkedList->Primero()->frase << endl;
    cout<<"Ultimo elemento: " << linkedList->Ultimo()->frase << endl;
    linkedList->InsertarInicio("HOLA");
    linkedList->InsertarInicio("MUNDO");
    linkedList->InsertarFinal(" CRUEL");
    linkedList->InsertarFinal("ADIOS");
    linkedList->Insertar(4, "JAJAJAJA");
    linkedList->Insertar(3, "JJEJEJE");
    linkedList->Insertar(0, "JIJIJI");
    linkedList->ImprimirLista();
    linkedList->VaciarLista();
    linkedList->ImprimirLista();
    return 0;
}
