#include <iostream>
#include "Animal.h"

class NodoDoble{
public:
    Animal a;
    NodoDoble* Anterior;
    NodoDoble* Siguiente;

    NodoDoble(int);
};

NodoDoble::NodoDoble(int historico){ 
    a.setNombre();
    a.setRaza();
    a.id = historico+1;
    Anterior = NULL;
    Siguiente = NULL;
}
