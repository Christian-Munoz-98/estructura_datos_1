#include "Nodo.h"

class ListaDoble{
public:
    int contador;
    NodoDoble* Cabecera;
    NodoDoble* Cola;
    
    ListaDoble();

    void InsertarInicio(string,float,int);
    void InsertarFinal(string,float,int);

    void RemoverInicio();
    void RemoverFinal();
    void VaciarLista();

    void InsertSort();
    void MergeSort(NodoDoble*,NodoDoble*);
    void Fusionar(NodoDoble*,NodoDoble*,NodoDoble*);
    void SelectionSort();
    NodoDoble* Particion(NodoDoble*,NodoDoble*);
    void QuickSort(NodoDoble*,NodoDoble*);
    void MostrarLista();
};

ListaDoble::ListaDoble(){
    contador = 0;
    Cabecera = NULL;
    Cola = NULL;
}

void ListaDoble::InsertarInicio(string nombre,float precio,int id){
    NodoDoble* nuevoNodo = new NodoDoble(nombre,precio,id);

    nuevoNodo->Siguiente = Cabecera;

    if(Cabecera != NULL)
        Cabecera->Anterior = nuevoNodo;

    Cabecera = nuevoNodo;

    if(contador == 0)
        Cola = Cabecera;

    contador++;
}

void ListaDoble::InsertarFinal(string nombre,float precio,int id){
    if(contador == 0){
        InsertarInicio(nombre,precio,id);
    }
    else{
        NodoDoble* nuevoNodo = new NodoDoble(nombre,precio,id);
        Cola->Siguiente = nuevoNodo;
        nuevoNodo->Anterior = Cola;
        Cola = nuevoNodo;
        contador++;
    }
}

void ListaDoble::RemoverInicio(){
    if(contador == 0)
        cout<<"Lista vacia..."<<endl;
    else{
        NodoDoble* nodo = Cabecera;

        Cabecera = Cabecera->Siguiente;

        delete nodo;

        if(Cabecera != NULL)
            Cabecera->Anterior = NULL;

        contador--;
    }
}

void ListaDoble::RemoverFinal(){
    if(contador == 0)
        cout<<"Lista Vacia..."<<endl;
    if(contador == 1)
        RemoverInicio();
    else{
        NodoDoble* nodo = Cola;

        Cola = Cola->Anterior;

        Cola->Siguiente = NULL;

        delete nodo;

        contador--;
    }
}

void ListaDoble::VaciarLista(){
    int aux = contador;

    for(int i=1;i<=aux;i++){
        RemoverInicio();
    }

    cout << "Lista vaciada con exito" << endl;
}

void ListaDoble::InsertSort(){
	NodoDoble* refNode = Cabecera->Siguiente;
	bool ban;
    while(refNode!=NULL){
		ban = true;
        Producto refProduct = refNode->p;
		int refPrice= refProduct.precio;
		NodoDoble* refNodePrev = refNode->Anterior;
        
        while(refNodePrev!=NULL&&ban){
            if(refNodePrev->p.precio > refPrice){            
                refNodePrev->Siguiente->p = refNodePrev->p;
				refNodePrev->p = refProduct;
            }
            else{
                ban=false;
            }
			refNodePrev = refNodePrev->Anterior;
        }
		refNode = refNode->Siguiente;
    }
}

void ListaDoble::MergeSort(NodoDoble* start,NodoDoble* end){////
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

        MergeSort(start,middle);

        MergeSort(middle->Siguiente,end);

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
        if(left->p.precio <= right->p.precio)
        {
            tempList->InsertarFinal(left->p.nombre,left->p.precio,left->p.id);

            left=left->Siguiente;
        }
        else{
            tempList->InsertarFinal(right->p.nombre,right->p.precio,right->p.id);

            right=right->Siguiente;
        }

    }

    while(left!=middle->Siguiente){
        tempList->InsertarFinal(left->p.nombre,left->p.precio,left->p.id);

        left=left->Siguiente;
    }

    while (right!=end->Siguiente){
        tempList->InsertarFinal(right->p.nombre,right->p.precio,right->p.id);

        right=right->Siguiente;

    }

    NodoDoble* tempStart = tempList->Cabecera;
    while(start!=end->Siguiente){
        start->p = tempStart->p;
        start = start->Siguiente;
        tempStart = tempStart->Siguiente;
    }

    delete tempList;

}

void ListaDoble::SelectionSort(){
    NodoDoble* minimo;
    NodoDoble* ref = Cabecera;
    NodoDoble* refNext;
    bool swap;
    while (ref!=Cola){
        swap = false;
        refNext = ref->Siguiente;
        minimo = ref;
        while (refNext!=NULL){
            if (refNext->p.precio<minimo->p.precio){
                minimo=refNext;
                swap = true;
            }
            refNext = refNext->Siguiente;
        }

        if (swap){
            Producto tmp = ref->p;
            ref->p = minimo->p;
            minimo->p =tmp;            
        }
        ref=ref->Siguiente;
    }
    
}

NodoDoble* ListaDoble::Particion(NodoDoble* inicio,NodoDoble* final){
    NodoDoble* pivote = inicio;
    NodoDoble* enmedio = inicio;
    NodoDoble* ref = inicio->Siguiente;
    Producto tmp;
    while(ref!=NULL){
        if (ref->p.precio<pivote->p.precio){
            enmedio=enmedio->Siguiente;
            tmp = ref->p;
            ref->p = enmedio->p;
            enmedio->p = tmp;
        }
        ref=ref->Siguiente;
    }
    
    tmp = inicio->p;
    inicio->p = enmedio->p;
    enmedio->p = tmp;

    return enmedio;
    
}

void ListaDoble::QuickSort(NodoDoble* inicio,NodoDoble* final){
    if (final != NULL && inicio != final && inicio != final->Siguiente){
        NodoDoble* pivote = Particion(inicio,final);
        QuickSort(inicio,pivote->Anterior);
        QuickSort(pivote->Siguiente,final);
    }
}

void ListaDoble::MostrarLista(){
    NodoDoble* nodo = Cabecera;

    while(nodo != NULL){
        nodo->p.mostrar();
        nodo = nodo->Siguiente;
    }

    cout <<"Fin de la lista..." << endl;
}