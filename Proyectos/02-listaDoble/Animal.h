#include <iostream>

using namespace std;

class Animal{
public:
    string nombre;
    string raza;
    int id;

    void setNombre();
    void setRaza();
    void mostrar();
};

void Animal::setNombre(){
    string nombre;
    cout << "Ingrese el nombre del animal>>";
    cin >> nombre;
    this->nombre = nombre;
}

void Animal::setRaza(){
    string raza;
    cout << "Ingrese la raza del animal>>";
    cin >> raza;

    this->raza = raza;
}

void Animal::mostrar(){
    cout<<"-------------" << endl
    << "ID: " << id << endl
    <<"Nombre: " << nombre << endl
    << "Raza: "  << raza << endl
    <<"-------------" << endl;
}

