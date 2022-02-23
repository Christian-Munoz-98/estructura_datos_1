#include "lista.h"
#include <iostream>

using namespace std;

void lista::eliminar(int e)
{
	nodo *aux=h;
	nodo *ant=NULL;
	bool band=true;
	
	if(h!=NULL)
	{
		while(aux and band)
		{
			if(e != aux->getDato())
			{
				ant = aux;
				aux=aux->getSig();
			}
	
			else
			{
				band = false;
			}
		}
		if(aux==NULL)
		{
			cout<<"Dato no existente."<<endl;
		}
		else if(aux==h)
		{
			h=h->getSig();
			delete aux;
		}
		else //if(aux->getSig()==NULL)
		{
			ant->setSig(aux->getSig());
			delete aux;
		}
		
	}
	else
	{
		cout<<"Lista vacia."<<endl;
	}
}

void lista::insertar(int e)
{
	
	nodo *tmp= new nodo(e);
	if(h==NULL)
	{
		h=tmp;
	}
	else
	{
		tmp->setSig(h);
		h=tmp;
	}
}
void lista::mostrar(void)
{
	nodo *aux=h;
	if(aux==NULL)
	{
		cout<<"Lista vacia..."<<endl;
	}
	else
	{
		while(aux)
		{
			cout<<aux->getDato()<<", ";
			aux=aux->getSig();
		}
	}
	cout<<endl;
	
}
lista::lista()
{
	h=NULL;
}
