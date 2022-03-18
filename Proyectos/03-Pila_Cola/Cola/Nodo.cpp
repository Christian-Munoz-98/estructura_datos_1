#include "Nodo.h"

Nodo::Nodo(){
    string _id;
    string _animal;
    string _raza;
    cout<<"Ingrese ID >> "; cin>> _id;
    cout<<"Ingrese Animal >> "; cin>> _animal;
    cout << "Ingrese Raza >> "; cin>> _raza;
    a = new Animal(_id,_animal,_raza);
    siguiente = nullptr;
}

Nodo::~Nodo(){}