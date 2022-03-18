#ifndef NODO_H
#define NODO_H

#include "Animal.cpp"

#pragma once

class Nodo{
public:
    Animal* a;
    Nodo* siguiente;
    Nodo();
    ~Nodo();
};

#endif