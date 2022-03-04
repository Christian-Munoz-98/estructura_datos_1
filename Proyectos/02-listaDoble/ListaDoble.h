#include <iostream>
#include "NodoDoble.h"

using namespace std;

class ListaDoble{
public:
    int contador;   
    int historico;
    NodoDoble* Cabecera;
    NodoDoble* Cola;
    
    ListaDoble();

    void InsertarInicio();
    void InsertarFinal();
    void InsertarMedio(int);

    void RemoverInicio();
    void RemoverFinal();
    bool RemoverMedio(int);
    void VaciarLista();

    NodoDoble* Buscar(int);
    int BuscarIndice(string);
    NodoDoble* Primero();
    NodoDoble* Ultimo();

    int Tamanho();
    void MostrarLista();
    void MostrarReversa();
};

ListaDoble::ListaDoble(){
    contador = 0;
    historico = 0;
    Cabecera = NULL;
    Cola = NULL;
}

void ListaDoble::InsertarInicio(){
    NodoDoble* nuevoNodo = new NodoDoble(historico);

    nuevoNodo->Siguiente = Cabecera;

    if(Cabecera != NULL)
        Cabecera->Anterior = nuevoNodo;

    Cabecera = nuevoNodo;

    if(contador == 0)
        Cola = Cabecera;

    contador++;
    historico++;
}

void ListaDoble::InsertarFinal(){
    if(contador == 0){
        InsertarInicio();
    }
    else{
        NodoDoble* nuevoNodo = new NodoDoble(historico);
        Cola->Siguiente = nuevoNodo;
        nuevoNodo->Anterior = Cola;
        Cola = nuevoNodo;
        contador++;
        historico++;
    }
}

void ListaDoble::InsertarMedio(int indice){
    if(indice < 0 || indice > contador){
        cout<<"Indice fuera de rango"<<endl;
        system("pause");
    }
    else if(indice == 0)
        InsertarInicio();
    else if(indice == contador)
        InsertarFinal();
    else{
        NodoDoble* nodoAnterior = Cabecera;

        for(int i = 0; i < indice-1; i++){
            nodoAnterior = nodoAnterior->Siguiente;
        }

        NodoDoble* nodoSiguiente = nodoAnterior->Siguiente;

        NodoDoble* nuevoNodo = new NodoDoble(historico);

        nuevoNodo->Siguiente = nodoSiguiente;
        nuevoNodo->Anterior = nodoAnterior;
        nodoAnterior->Siguiente = nuevoNodo;
        nodoSiguiente->Anterior = nuevoNodo;

        contador++;
        historico++;
    }
}

void ListaDoble::RemoverInicio(){
    if(contador == 0)
        cout<<"Lista vacia..."<<endl;
    else{
        NodoDoble* nodo = Cabecera;

        Cabecera = Cabecera->Siguiente;

        delete nodo;

        if(Cabecera != NULL)
            Cabecera->Anterior = NULL;

        contador--;
    }
}

void ListaDoble::RemoverFinal(){
    if(contador == 0)
        cout<<"Lista Vacia..."<<endl;
    if(contador == 1)
        RemoverInicio();
    else{
        NodoDoble* nodo = Cola;

        Cola = Cola->Anterior;

        Cola->Siguiente = NULL;

        delete nodo;

        contador--;
    }
}

bool ListaDoble::RemoverMedio(int indice){
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
    
    NodoDoble* nodoAnterior = Cabecera;

    for(int i = 0; i < indice-1; i++){
        nodoAnterior = nodoAnterior->Siguiente;
    }

    NodoDoble* nodo = nodoAnterior->Siguiente;

    NodoDoble* nodoSiguiente = nodo->Siguiente;

    nodoAnterior->Siguiente = nodoSiguiente;
    nodoSiguiente->Anterior = nodoAnterior;

    delete nodo;

    contador--;
    return true;
}

void ListaDoble::VaciarLista(){
    int aux = contador;

    for(int i=1;i<=aux;i++){
        RemoverInicio();
    }

    cout << "Lista vaciada con exito" << endl;
}

NodoDoble* ListaDoble::Buscar(int indice){
    if(indice < 0 || indice > contador)
        return NULL;

    NodoDoble* nodo = Cabecera;

    for(int i=0;i < indice;i++){
        nodo = nodo->Siguiente;
    }

    return nodo;
}

int ListaDoble::BuscarIndice(string nombre){
    if(contador == 0)
        return -1;

    int indice = 0;

    NodoDoble* nodo = Cabecera;

    while(nodo->a.nombre != nombre)
    {
        indice++;
        nodo = nodo->Siguiente;

        if(nodo == NULL){
            return -1;
        }
    }

    return indice;
}

NodoDoble* ListaDoble::Primero(){
    return Cabecera;
}

NodoDoble* ListaDoble::Ultimo(){
    return Cola;
}

int ListaDoble::Tamanho(){
    return contador;
}

void ListaDoble::MostrarLista(){
    NodoDoble* nodo = Cabecera;

    while(nodo != NULL){
        nodo->a.mostrar();
        nodo = nodo->Siguiente;
    }

    cout << endl <<"Fin de la lista..." << endl;
}

void ListaDoble::MostrarReversa(){
    NodoDoble* nodo = Cola;

    while(nodo != NULL){
        nodo->a.mostrar();
        nodo = nodo->Anterior;
    }

    cout << endl <<"Fin de la lista..." << endl;
}