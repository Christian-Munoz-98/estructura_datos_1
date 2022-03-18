#ifndef COLA_H
#define COLA_H

#include "Nodo.cpp"
#pragma once

void EmptyMessage();

class Cola{
public:
    Cola();
    ~Cola();
    void Queue();
    void DeQueue();
    void First();
    void Last();
    bool IsEmpty();
    void Tamanho();
    void Vaciar();
    void MostrarCola();

private:
    int contador;
    Nodo* primero;
    Nodo* ultimo;

};

#endif

void EmptyMessage(){
    cout << "La cola esta vacia..." << endl;
    system("pause"); 
}