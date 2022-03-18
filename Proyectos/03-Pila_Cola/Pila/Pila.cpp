#include "Pila.h"

Pila::Pila(){
    top = nullptr;
    contador = 0;
}

Pila::~Pila(){}

void Pila::Push(){
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->siguiente = top;
    top = nuevoNodo;
    contador++;
}

void Pila::Pop(){
    if(!IsEmpty()){
		Nodo* aux = top;
        top = top->siguiente;
        delete aux;
        cout<<"Eliminacion realizada"<<endl;
        system("pause");
		contador--;
	}
	else{
        EmptyMessage();
	}	
}

void Pila::ShowTop(){
    if(!IsEmpty()){
        system("cls");
        top->a->Mostrar();
        system("pause");
    }
    else{
        EmptyMessage();
    }
}

bool Pila::IsEmpty(){
    return contador == 0;
}

void Pila::Tamanho(){
    cout << "La pila cuenta con " << contador << " elementos" << endl;
    system("pause");
}

void Pila::Vaciar(){
    while (top!=nullptr){
        Nodo* aux = top;
        top = top->siguiente;
        delete aux;
    }
    contador = 0;
    EmptyMessage();
}

void Pila::MostrarPila(){
    if (!IsEmpty()){
        Nodo* aux = top;
        while (aux!=nullptr){
            aux->a->Mostrar();
            aux = aux->siguiente;
        }
        system("pause");    
    }
    else{
        EmptyMessage();
    }  
}