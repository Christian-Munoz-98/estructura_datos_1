#include <iostream>
class Nodo
{
public:
    int Valor;
    Nodo * Siguiente;

    Nodo(int valor);
};

Nodo::Nodo(int valor){
    Valor = valor;
    Siguiente = NULL;
}
