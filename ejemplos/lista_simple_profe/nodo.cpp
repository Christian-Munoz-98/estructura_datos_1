#include "nodo.h"

int nodo::getDato(void)
{
	return dato;
}
void nodo::setDato(int e)
{
	dato = e;
}
nodo* nodo::getSig(void)
{
	return sig;
}
void nodo::setSig(nodo* sig)
{
	this->sig=sig;
}
nodo::nodo()
{
	dato=0;
	sig=NULL;
	//ctor
}
