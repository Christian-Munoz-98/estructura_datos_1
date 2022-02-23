#include <iostream>
#include "Node.h"

using namespace std;

class ListaEnlazada
{
private:
    int contador;

public:
    // The first node in the list
    // or null if empty
    Nodo *Cabecera;

    // The last node in the list
    // or null if empty
    Nodo *Cola;

    // Constructor
    ListaEnlazada();

    // Get() operation
    Nodo * Get(int indice);

    // Insert() operation
    void InsertarInicio(int val);
    void InsertarFinal(int val);
    void Insertar(int indice, int val);

    // Search() operation
    int Buscar(int val);

    // Remove() operation
    void RemoverInicio();
    void RemoverFinal();
    void Remover(int indice);

    // Additional operation
    int Contador();
    void ImprimirLista();
};

ListaEnlazada::ListaEnlazada(){
    contador = 0;
    Cabecera = NULL;
    Cola = NULL;
}

Nodo * ListaEnlazada::Get(int indice)
{
    // Check if the index is out of bound
    if(indice < 0 || indice > contador)
        return NULL;

    // Start from the Head
    Nodo * nodo = Cabecera;

    // Iterate through the linked list elements
    // until it finds the selected index
    for(int i = 0; i < indice; i++)
    {
        nodo = nodo->Siguiente;
    }

    // Simply return the node result
    return nodo;
}

void ListaEnlazada::InsertarInicio(int val)
{
    // Create a new Node
    Nodo * nodo = new Nodo(val);

    // The current Head will no longer become a Head
    // so the Next pointer of the new Node will
    // point to the current Head
    nodo->Siguiente = Cabecera;

    // The new Node now become the Head
    Cabecera = nodo;

    // If the linked list is empty
    // The Tail is also the Head
    if(contador == 0)
        Cola = Cabecera;

    // One element is added
    contador++;
}

void ListaEnlazada::InsertarFinal(int val)
{
    // If the linked list is empty,
    // just simply invoke InsertHead()
    if(contador == 0)
    {
        InsertarInicio(val);
        return;
    }

    // Create a new Node
    Nodo * nodo = new Nodo(val);

    // The current Tail will no longer become a Tail
    // so the Next pointer of the current Tail will
    // point to the new node
    Cola->Siguiente = nodo;

    // The new Node now become the Tail
    Cola = nodo;

    // One element is added
    contador++;
}

void ListaEnlazada::Insertar(int indice, int val)
{
    // Check if the index is out of bound
    if(indice < 0 || indice > contador)
        return;

    // If inserting a new Head
    if(indice == 0)
    {
        InsertarInicio(val);
        return;
    }
    // If inserting a new Tail
    else if(indice == contador)
    {
        InsertarFinal(val);
        return;
    }

    // Start to find previous node
    // from the Head
    Nodo * nodoAnterior = Cabecera;

    // Traverse the elements until
    // the selected index is found
    for(int i = 0; i < indice - 1; i++)
    {
        nodoAnterior = nodoAnterior->Siguiente;
    }

    // Create the next node which is
    // the element after previous node
    Nodo * nodoSiguiente = nodoAnterior->Siguiente;

    // Create a new node
    Nodo * node = new Nodo(val);

    // Insert this new node between
    // the previous node and the next node
    node->Siguiente = nodoSiguiente;
    nodoAnterior->Siguiente = node;

    // One element is added
    contador++;
}

int ListaEnlazada::Buscar(int val)
{
    // If LinkedList is empty,
    // just return NOT_FOUND
    if(contador == 0)
        return -1;

    // Need to count the index
    int indice = 0;

    // Traverse from the Head node
    Nodo* nodo = Cabecera;

    // Traverse until the selected value
    // is matched with the value
    // of the current position,
    while(nodo->Valor != val)
    {
        indice++;
        nodo = nodo->Siguiente;

        // This will happen
        // if the selected value
        // is not found
        if(nodo == NULL)
        {
            return -1;
        }
    }

    return indice;
}

void ListaEnlazada::RemoverInicio()
{
    // Do nothing if list is empty
    if(contador == 0)
        return;

    // Save the current Head
    // to a new node
    Nodo * nodo = Cabecera;

    // Point the Head Pointer
    // to the element next to the current Head
    Cabecera = Cabecera->Siguiente;

    // Now it's safe to remove
    // the first element
    delete nodo;

    // One element is removed
    contador--;
}

void ListaEnlazada::RemoverFinal()
{
    // Do nothing if list is empty
    if(contador == 0)
        return;

    // If List element is only one
    // just simply call RemoveHead()
    if(contador == 1)
    {
        RemoverInicio();
        return;
    }

    // Start to find previous node
    // from the Head
    Nodo * nodoAnterior = Cabecera;

    // This is the candidate of
    // removed items which is
    // the element next to the prevNode
    Nodo * nodo = Cabecera->Siguiente;

    // Traverse the elements until
    // the last element
    while(nodo->Siguiente != NULL)
    {
        nodoAnterior = nodoAnterior->Siguiente;
        nodo = nodo->Siguiente;
    }

    // the prevNode now becomes the Tail
    // so the Next pointer of the prevNode
    // point to NULL
    nodoAnterior->Siguiente = NULL;
    Cola = nodoAnterior;

    // Now it's safe to remove
    // the last element
    delete nodo;

    // One element is removed
    contador--;
}

void ListaEnlazada::Remover(int indice)
{
    // Do nothing if list is empty
    if(contador == 0)
        return;

    // Do nothing if index is out of bound
    if(indice < 0 || indice >= contador)
        return;

    // If removing the current Head
    if(indice == 0)
    {
        RemoverInicio();
        return;
    }
    // If removing the current Tail
    else if(indice == contador - 1)
    {
        RemoverFinal();
        return;
    }

    // Start to traverse the list
    // from the Head
    Nodo * nodoAnterior = Cabecera;

    // Find the element before
    // the selected index
    for(int i = 0; i < indice - 1; ++i)
    {
        nodoAnterior = nodoAnterior->Siguiente;
    }

    // The removed element is after
    // the prevNode
    Nodo * node = nodoAnterior->Siguiente;

    // The nextNode will be the neighbor of
    // prevNode if the node is removed
    Nodo * nodoSiguiente = node->Siguiente;

    // Link the prevNode to nextNode
    nodoAnterior->Siguiente = nodoSiguiente;

    // It's now safe to remove
    // the selected index element
    delete node;

    // One element is removed
    contador--;
}

int ListaEnlazada::Contador()
{
    return contador;
}

void ListaEnlazada::ImprimirLista()
{
    Nodo * nodoSiguiente = Cabecera;

    while(nodoSiguiente != NULL)
    {
        cout << nodoSiguiente->Valor << " -> ";
        nodoSiguiente = nodoSiguiente->Siguiente;
    }

    cout << "NULL" <<endl;
}
