#include <iostream>
#include "lista.h"
#include "nodo.h"
using namespace std;

int main() 
{
	lista *lis= new lista;
	
	lis->insertar(9);
	lis->insertar(5);
	lis->insertar(89);
	lis->insertar(55);
	
	lis->mostrar();
	
	lis->eliminar(91);
	lis->mostrar();
	
	lis->eliminar(5);
	lis->mostrar();
	
	lis->eliminar(51);
	lis->mostrar();
	
	lis->eliminar(9);
	lis->mostrar();

	return 0;
}
