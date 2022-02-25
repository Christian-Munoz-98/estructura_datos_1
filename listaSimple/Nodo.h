#include <iostream>
#include <string>

using namespace std;

class Nodo{
public:
    string frase;
    Nodo * Siguiente;

    Nodo(string frase){
        this->frase = frase;
        Siguiente = NULL;
    }
};


