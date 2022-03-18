#include "Animal.h"

Animal::Animal(string _id,string _nombre, string _raza){
        id = _id;
    nombre = _nombre;
    raza = _raza;
}

Animal::~Animal(){}

void Animal::Mostrar(){
    cout<<"-------------" << endl
    << "ID: " << id << endl
    <<"Nombre: " << nombre << endl
    << "Raza: "  << raza << endl
    <<"-------------" << endl;
}