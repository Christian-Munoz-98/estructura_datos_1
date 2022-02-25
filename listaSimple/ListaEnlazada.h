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

    void Buscar(string);

    void InsertarInicio(string);
    void InsertarFinal(string);
    void Insertar(int,string);

    void RemoverInicio();
    void RemoverFinal();
    void Remover(string);

    int Tamano();
    void ImprimirLista();
};

ListaEnlazada::ListaEnlazada(){
    contador = 0;
    Cabecera = NULL;
    Cola = NULL;
}

void ListaEnlazada::Buscar(string frase){
    Nodo* aux = Cabecera;
    int indice=0;
    bool ban=false;

    if(contador==0){
        cout<<"Lista Vacia"<<endl;
    }
    else{
        while (aux!=NULL){
            if(frase==aux->frase)
                ban=true;
            else{
                aux = aux->Siguiente;
                indice++;
            }
        }

        if(aux!=NULL){
            cout<< "Frase: " << frase << " encontrada en el indice " << to_string(indice) << endl;
        }
        else{
            cout << "Frase no encontrada" << endl;
        }
    }
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

void ListaEnlazada::Remover(string frase)
{
    if(contador == 0){
        cout<<"Lista vacia..."<<endl;
    }
    else{
        Nodo* nodoAnterior = Cabecera;

        while(nodoAnterior->Siguiente->frase!=frase||nodoAnterior!=NULL){
                nodoAnterior = nodoAnterior->Siguiente;
        }

        Nodo* nodo = nodoAnterior->Siguiente;
        Nodo* nodoSiguiente = nodo->Siguiente;
        
        nodoAnterior->Siguiente = nodoSiguiente;

        delete nodo;

        contador--;
    }
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
