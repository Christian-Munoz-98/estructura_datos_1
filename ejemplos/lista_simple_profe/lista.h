#ifndef LISTA_H
#define LISTA_H
#include "nodo.h"

class lista
{
	public:
		lista();
		void insertar(int); ///class,double...
		void mostrar(void);
		void eliminar(int);
		
		nodo* getH(void)
		{
			return h;
		}
		void setH(nodo* tmp)
		{
			h=tmp;
		}
	private:
		nodo *h;
};

#endif
