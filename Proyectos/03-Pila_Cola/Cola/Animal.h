#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

using namespace std;

#pragma once

class Animal{
public:
    string id;
    string nombre;
    string raza;

    Animal(string,string,string);
    ~Animal();
    void Mostrar();
};

#endif