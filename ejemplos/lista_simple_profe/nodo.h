#ifndef NODO_H
#define NODO_H
#include <iostream>

class nodo
{
private:
	int dato;
	nodo *sig;
public:
	nodo();
	nodo (int e)
	{
		dato = e;
		sig=NULL;
	};
	nodo(int e, nodo *tmp)
	{
		dato = e;
		sig = tmp;
	}
	int getDato(void);
	void setDato(int);
		
	nodo* getSig(void);
	void setSig(nodo*);
};

#endif
