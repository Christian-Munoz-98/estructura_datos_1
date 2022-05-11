#include <iostream>
using namespace std;

class Producto{
public:
    string nombre;
    float precio;
    int id;

    void mostrar();
};

void Producto::mostrar(){
    cout<<"-------------" << endl
    << "ID: " << id << endl
    <<"Nombre: " << nombre << endl
    << "Precio: "  << precio << endl
    <<"-------------" << endl;
}


class NodoDoble{
public:
    Producto p;
    NodoDoble* Anterior;
    NodoDoble* Siguiente;

    NodoDoble(string,float,int);
};

NodoDoble::NodoDoble(string nombre,float precio,int id){
    p.nombre = nombre;
    p.precio = precio;
    p.id = id;
    Anterior = NULL;
    Siguiente = NULL;
}