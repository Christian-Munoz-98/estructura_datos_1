#include <iostream>
#include <string>
#include "Nodo.h"

using namespace std;

class ListaEnlazada{
private:
    int contador;

public:
    Nodo* Cabecera;
    Nodo* Cola;

    ListaEnlazada();

    int Buscar(string);

    void InsertarInicio(string);
    void InsertarFinal(string);
    void Insertar(int,string);

    void RemoverInicio();
    void RemoverFinal();
    bool Remover(int);
    void VaciarLista();

    int Tamano();
    void ImprimirLista();

    Nodo* Primero();
    Nodo* Ultimo();
};

ListaEnlazada::ListaEnlazada(){
    contador = 0;
    Cabecera = NULL;
    Cola = NULL;
}

int ListaEnlazada::Buscar(string frase){
    if(contador == 0)
        return -1;

    int indice = 0;

    Nodo* nodo = Cabecera;

    while(nodo->frase != frase)
    {
        indice++;
        nodo = nodo->Siguiente;

        if(nodo == NULL)
        {
            return -1;
        }
    }

    return indice;
}

void ListaEnlazada::InsertarInicio(string frase){
    Nodo* nuevoNodo = new Nodo(frase);

    nuevoNodo->Siguiente = Cabecera;

    Cabecera = nuevoNodo;

    if(contador == 0)
        Cola = Cabecera;
    
    contador++;
}

void ListaEnlazada::InsertarFinal(string frase){
    
    Nodo* nuevoNodo = new Nodo(frase);    
    
    if(contador == 0){
        InsertarInicio(frase);
    }
    else{
        Cola->Siguiente = nuevoNodo;
        Cola = nuevoNodo;
        contador++;
    }
}

void ListaEnlazada::Insertar(int indice,string frase)
{
    if(indice < 0 || indice > contador){
        cout << "Fuera de rango..." << endl;
    }
    else if(indice == 0){
        InsertarInicio(frase);
    }
    else if(indice == contador)
    {
        InsertarFinal(frase);
    }
    else{
        Nodo* nodoAnterior = Cabecera;

        for(int i = 0; i < indice - 1; i++){
            nodoAnterior = nodoAnterior->Siguiente;
        }

        Nodo* nodoSiguiente = nodoAnterior->Siguiente;
        Nodo* nuevoNodo = new Nodo(frase);

        nuevoNodo->Siguiente = nodoSiguiente;
        nodoAnterior->Siguiente = nuevoNodo;

        contador++;
    }
}

void ListaEnlazada::RemoverInicio(){

    if(contador == 0)
        cout << "Lista vacia" << endl;
    else{
        Nodo* nodo = Cabecera;

        Cabecera = Cabecera->Siguiente;

        delete nodo;
        contador--;
    }
}

void ListaEnlazada::RemoverFinal(){

    if(contador == 0){
        cout << "Lista vacia" << endl;
    }
    else if(contador == 1){
        RemoverInicio();
    }
    else{
        Nodo* nodoAnterior = Cabecera;
        Nodo* nodo = Cabecera->Siguiente;

        while(nodo->Siguiente != NULL)
        {
            nodoAnterior = nodoAnterior->Siguiente;
            nodo = nodo->Siguiente;
        }

        nodoAnterior->Siguiente = NULL;
        Cola = nodoAnterior;
        delete nodo;

        contador--;
    }
}

bool ListaEnlazada::Remover(int indice){

    if(contador == 0)
        return false;

    if(indice < 0 || indice >= contador)
        return false;

    if(indice == 0){
        RemoverInicio();
        return true;
    }
    else if(indice == contador - 1){
        RemoverFinal();
        return true;
    }
    
    Nodo * nodoAnterior = Cabecera;

    for(int i = 0; i < indice - 1; ++i)
    {
        nodoAnterior = nodoAnterior->Siguiente;
    }

    Nodo * node = nodoAnterior->Siguiente;

    Nodo * nodoSiguiente = node->Siguiente;

    nodoAnterior->Siguiente = nodoSiguiente;

    delete node;

    contador--;
    return true;
}

int ListaEnlazada::Tamano(){
    return contador;
}

void ListaEnlazada::ImprimirLista(){
    Nodo * nodoSiguiente = Cabecera;

    while(nodoSiguiente != NULL)
    {
        cout << nodoSiguiente->frase << " -----> ";
        nodoSiguiente = nodoSiguiente->Siguiente;
    }

    cout << "FIN" <<endl;
}

Nodo* ListaEnlazada::Primero(){
    return this->Cabecera;
}

Nodo* ListaEnlazada::Ultimo(){
    return this->Cola;
}

void ListaEnlazada::VaciarLista(){
    int aux = contador;

    for(int i=1;i<=aux;i++){
        RemoverInicio();
    }
    cout << "Lista vaciada con exito" << endl;
}