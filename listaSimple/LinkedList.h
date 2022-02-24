#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

class ListaEnlazada{
private:
    int contador;

public:
    Nodo* Cabecera;

    ListaEnlazada();

    string Buscar(string);

    void InsertarInicio(string);
    void InsertarFinal(string);
    void Insertar(string);

    void RemoverInicio();
    void RemoverFinal();
    void Remover(string);

    // Additional operation
    int Contador();
    void ImprimirLista();
};

ListaEnlazada::ListaEnlazada(){
    contador = 0;
    Cabecera = NULL;
}

string ListaEnlazada::Buscar(string frase){
    int indice=0;
    
    if(Cabecera == NULL)
        return "Lista Vacia";

    Nodo* aux = Cabecera;

    while (frase!=aux->frase){
        aux = aux->Siguiente;
        indice++;
    }

    delete aux;
    return "Frase encontrada en el indice "+to_string(indice);
}

void ListaEnlazada::InsertarInicio(string frase){
    Nodo *nuevoNodo = new Nodo(frase);

    nuevoNodo->Siguiente = Cabecera;

    Cabecera = nuevoNodo;

    contador++;
}

void ListaEnlazada::InsertarFinal(string frase){
    
    if(Cabecera == NULL){
        InsertarInicio(frase);
        return;
    }

    Nodo* nuevoNodo = new Nodo(frase);
    Nodo* aux = Cabecera;

    while (aux->Siguiente!=NULL){
        aux = aux->Siguiente;
    }
    aux->Siguiente = nuevoNodo;
    contador++;
    delete aux;
}

void ListaEnlazada::Insertar(string frase)
{
    int indice=0;
    Nodo* nodoAnterior;
    Nodo* nodoSiguiente;
    Nodo* nuevoNodo = new Nodo(frase);
    bool ban;
    int exit;

    if(Cabecera == NULL){
        InsertarInicio(frase);
    }
    else{ 
        nodoAnterior=Cabecera;
        while (ban){
            cout << "Elemento-> " << nodoAnterior->frase << "En el indice " << indice << endl;
            cout << "Desea insertar el elemento aqui? 1)si 2)no";
            cin>>exit;
            if (exit==1)
            {
                nodoSiguiente = nodoAnterior->Siguiente;
                nuevoNodo->Siguiente = nodoSiguiente;
                nodoAnterior->Siguiente = nuevoNodo;
                contador++;
                delete nodoAnterior;
                delete nodoSiguiente;
                ban = false;
            }
            else{
                nodoAnterior =  nodoAnterior->Siguiente;
                indice++;
            }
        }
    }
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
