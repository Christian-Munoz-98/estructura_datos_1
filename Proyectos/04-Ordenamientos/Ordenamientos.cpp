#include <iostream>
using namespace std;

class Producto{
public:
    string nombre;
    float precio;
    int id;

    void mostrar();
};

void Producto::mostrar(){
    cout<<"-------------" << endl
    << "ID: " << id << endl
    <<"Nombre: " << nombre << endl
    << "Precio: "  << precio << endl
    <<"-------------" << endl;
}


class NodoDoble{
public:
    Producto p;
    NodoDoble* Anterior;
    NodoDoble* Siguiente;

    NodoDoble(string,float,int);
};

NodoDoble::NodoDoble(string nombre,float precio,int id){
    p.nombre = nombre;
    p.precio = precio;
    p.id = id;
    Anterior = NULL;
    Siguiente = NULL;
}

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

void ListaDoble::MostrarLista(){
    NodoDoble* nodo = Cabecera;

    while(nodo != NULL){
        nodo->p.mostrar();
        nodo = nodo->Siguiente;
    }

    cout <<"Fin de la lista..." << endl;
}

void opciones(int);

int main(){
    ListaDoble* lista = new ListaDoble();

    lista->InsertarFinal("Cocacola",20.5,1);
    lista->InsertarFinal("Rocaleta",13.6,2);
    lista->InsertarFinal("Pinwinos",25.4,3);
    lista->InsertarFinal("Manzanas",30,4);
    lista->InsertarFinal("Chocolate",7.67,5);
    lista->InsertarFinal("Papel",67.65,6);
    lista->InsertarFinal("Pollo",12.54,7);
    lista->InsertarFinal("Carne",105.32,8);
    lista->InsertarFinal("Cheetos",10.5,9);
    lista->InsertarFinal("Sabritas",17,10);
    cout<<" Lista Antes de ordenar: " << endl <<endl;
    lista->MostrarLista();
    lista->SelectionSort();
    cout<< endl << " Lista Despues de ordenar: " << endl << endl;
    lista->MostrarLista();
    
    return 0;
}
/*    
    int opc;
    do{
        system("cls");
        cout<<"1)Anadir producto"<<endl
        <<"2)Eliminar producto" <<endl
        <<"3)Vaciar inventario"<<endl
        <<"4)Mostrar Lista"<<endl
        <<"5)Ordenar Lista"<<endl
        <<"6)Salir"<<endl
        <<"Elija una opcion >>>>>";
        cin>>opc;
        opciones(opc);
    }while(opc!=6);
    return 0;
}

void opciones(int opc){
    bool confirmation;
    NodoDoble* NodoEncontrado;
    switch (opc){
    case 1:
        system("cls");
        cout << "ANADIR PRODUCTO" << endl << endl;
        lista->InsertarFinal();
        system("pause");
        break;

    case 2:
        system("cls");
        cout << "ELIMINAR PRODUCTO" << endl << endl;
        lista->RemoverFinal();
        cout<<"Producto eliminado"<<endl;
        system("pause");
        break;

    case 3:
        system("cls");
        cout << "VACIAR LA LISTA" << endl << endl;
        lista->VaciarLista();
        system("pause");
        break;

    case 4:
        system("cls");
        cout << "MOSTRAR LISTA" << endl << endl;
        if (lista->Cabecera==NULL){
            cout << "La lista esta vacia" << endl;
        }
        else{
            lista->MostrarLista();
        }
        system("pause");
        break;

    case 5:
        system("cls");
        cout << "ORDENAR LISTA" << endl << endl;
        if (lista->Cabecera==NULL){
            cout << "La lista esta vacia" << endl;
        }
        else{
            lista->InsertSort();
            cout<<"Lista ordenada exitosamente..."<<endl;
        }
        system("pause");
        break;

    case 6:
        system("cls");
        cout<<"Saliendo..."<<endl;
        system("pause");
        break;

    default:
        system("cls");
        cout<<"Opcion Invalida..."<<endl;
        system("pause");
        break;
    }
*/



