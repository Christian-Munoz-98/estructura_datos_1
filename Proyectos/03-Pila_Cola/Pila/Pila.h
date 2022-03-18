#ifndef PILA_H
#define PILA_H

#include "Nodo.cpp"

#pragma once

void EmptyMessage();

class Pila{
public:
    Pila();
    ~Pila();
    void Push();
    void Pop();
    void ShowTop();
	bool IsEmpty();
    void Tamanho();
    void Vaciar();
	void MostrarPila();

private:
    int contador;
    Nodo* top;
};

#endif


void EmptyMessage(){
    cout << "La pila esta vacia..." << endl;
    system("pause"); 
}