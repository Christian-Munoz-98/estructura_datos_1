#include <iostream>

using namespace std;

class NodoDoble{
public:
    int val;
    NodoDoble* Anterior;
    NodoDoble* Siguiente;

    NodoDoble(int);
};

NodoDoble::NodoDoble(int val){ 
    this->val = val;
    Anterior = NULL;
    Siguiente = NULL;
}

class ListaDoble{
public:
    int contador;   
    NodoDoble* Cabecera;
    NodoDoble* Cola;
    
    ListaDoble();

    void Insertar(int);
    void Remover();
    void Vaciar();

    void Ordenar(NodoDoble*,NodoDoble*);//////
    void Fusionar(NodoDoble*,NodoDoble*,NodoDoble*);//////
    void Mostrar();
	void MostrarReversa();
};

ListaDoble::ListaDoble(){
    contador = 0;
    Cabecera = NULL;
    Cola = NULL;
}

void ListaDoble::Insertar(int val){
	NodoDoble* nuevoNodo = new NodoDoble(val);
    if(contador == 0){
    	
		nuevoNodo->Siguiente = Cabecera;

    	if(Cabecera != NULL)
        	Cabecera->Anterior = nuevoNodo;

    	Cabecera = nuevoNodo;

    	if(contador == 0)
        	Cola = Cabecera;

    	contador++;
    }
    else{
        
        Cola->Siguiente = nuevoNodo;
        nuevoNodo->Anterior = Cola;
        Cola = nuevoNodo;
        contador++;
    }
}


void ListaDoble::Remover(){
    if(contador == 0)
        cout<<"Lista Vacia..."<<endl;
    else if(contador == 1){
        NodoDoble* nodo = Cabecera;

        Cabecera = Cabecera->Siguiente;

        delete nodo;

        if(Cabecera != NULL)
            Cabecera->Anterior = NULL;

        contador--;
	}
    else{
        NodoDoble* nodo = Cola;

        Cola = Cola->Anterior;

        Cola->Siguiente = NULL;

        delete nodo;

        contador--;
    }
}

void ListaDoble::Vaciar(){
    int aux = contador;

    for(int i=1;i<=aux;i++){
        NodoDoble* nodo = Cabecera;

        Cabecera = Cabecera->Siguiente;

        delete nodo;

        if(Cabecera != NULL)
            Cabecera->Anterior = NULL;

        contador--;
    }

    cout << "Lista vaciada con exito" << endl;
}

void ListaDoble::Ordenar(NodoDoble* start,NodoDoble* end){////
    if(start!=end){
        int elements = 0;
        NodoDoble* ref = start;
        while (ref!=end){
            ref=ref->Siguiente;
            elements++;
        }

        NodoDoble* middle = start;
        for(int i=2;i<=(elements+1)/2;i++){
            middle=middle->Siguiente;
        }

        Ordenar(start,middle);

        Ordenar(middle->Siguiente,end);

        Fusionar(start, middle, end);
    }

    return;
}

void ListaDoble::Fusionar(NodoDoble* start,NodoDoble* middle,NodoDoble* end){///
    
    ListaDoble* tempList = new ListaDoble();
    NodoDoble* left = start;
    NodoDoble* right = middle->Siguiente;

    while ((left!=middle->Siguiente)&&(right!=end->Siguiente))
    {
        if(left->val <= right->val)
        {
            tempList->Insertar(left->val);

            left=left->Siguiente;
        }
        else{
            tempList->Insertar(right->val);

            right=right->Siguiente;
        }

    }

    while(left!=middle->Siguiente){
        tempList->Insertar(left->val);

        left=left->Siguiente;
    }

    while (right!=end->Siguiente){
        tempList->Insertar(right->val);

        right=right->Siguiente;

    }

    NodoDoble* tempStart = tempList->Cabecera;
    while(start!=end->Siguiente){
        start->val = tempStart->val;
        start = start->Siguiente;
        tempStart = tempStart->Siguiente;
    }

    delete tempList;

}


void ListaDoble::Mostrar(){
    NodoDoble* nodo = Cabecera;

    while(nodo != NULL){
        cout << nodo->val << ",";
        nodo = nodo->Siguiente;
    }

    cout <<"Fin de la lista..." << endl;
}

void ListaDoble::MostrarReversa(){
    NodoDoble* nodo = Cola;

    while(nodo != NULL){
        cout << nodo->val << ",";
        nodo = nodo->Anterior;
    }

    cout <<"Fin de la lista..." << endl;
}

int main(){
	ListaDoble* lista = new ListaDoble();

	lista->Insertar(100);
	lista->Insertar(47);
	lista->Insertar(62);
	lista->Insertar(7123);
	lista->Insertar(990);
	lista->Insertar(1);
	lista->Insertar(256);
	lista->Insertar(32);
	lista->Insertar(578);
	lista->Insertar(81);
	lista->Insertar(42);
	lista->Insertar(103);
	lista->Insertar(231);
	lista->Insertar(78);
	lista->Insertar(90);
	lista->Insertar(10);
	lista->Insertar(26);
	lista->Insertar(2);
	lista->Insertar(67);
	lista->Insertar(234435);
	lista->Insertar(11);
	lista->Insertar(30);
	lista->Insertar(45);
	lista->Insertar(1001);
	lista->Insertar(98);
	lista->Insertar(100);
	lista->Insertar(34);
	lista->Insertar(23);
	lista->Insertar(578);
	lista->Insertar(10000);
	cout<<"Lista Desordenada: ";
	lista->Mostrar();
	lista->Ordenar(lista->Cabecera,lista->Cola);
	cout<<"Lista Ordenada: ";
	lista->Mostrar();
}