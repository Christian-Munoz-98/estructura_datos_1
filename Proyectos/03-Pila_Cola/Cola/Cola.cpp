#include "Cola.h"

Cola::Cola(){
    contador = 0;
    primero = nullptr;
    ultimo = nullptr;
}

Cola::~Cola(){}

void Cola::Queue(){
    Nodo* nuevo = new Nodo();
    if (contador==0){
        primero = nuevo;
        ultimo = primero;
    }
    else{
        ultimo->siguiente=nuevo;
        ultimo = nuevo;
    }
    contador++; 
}

void Cola::DeQueue(){
    if (!IsEmpty()){
        Nodo* aux = primero;
        primero = primero->siguiente;
        delete aux;
        contador--;
        cout<<"Eliminacion realizada"<<endl;
        system("pause");
    }
    else{
        EmptyMessage();
    }
    
}

void Cola::First(){
    if (!IsEmpty()){
        primero->a->Mostrar();
        system("pause");
    }
    else{
        EmptyMessage();
    }
}

void Cola::Last(){
    if (!IsEmpty()){
        ultimo->a->Mostrar();
        system("pause");
    }
    else{
        EmptyMessage();
    }
}

bool Cola::IsEmpty(){
    return contador == 0;
}

void Cola::Tamanho(){
    cout<<"La cola cuenta con " << contador << " elementos"<<endl;
    system("pause");
}

void Cola::Vaciar(){
    while (primero!=nullptr){
        Nodo* aux = primero;
        primero = primero->siguiente;
        delete aux;
        contador--;
    }
    EmptyMessage();  
}

void Cola::MostrarCola(){
    if(!IsEmpty()){
        Nodo* aux = primero;
        while(aux!=nullptr){
            aux->a->Mostrar();
            aux = aux->siguiente;
        }
        system("pause");    
    }
    else{
        EmptyMessage();
    }
}