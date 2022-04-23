#include <iostream>
using namespace std;

class Producto{
public:
    string nombre;
    float precio;
    int id;

    void setNombre();
    void setPrecio();
    void mostrar();
};

void Producto::setNombre(){
    string nombre;
    cout << "Ingrese el nombre del producto>>";
    cin >> nombre;
    this->nombre = nombre;
}

void Producto::setPrecio(){
    float precio;
    cout << "Ingrese el precio del producto>>";
    cin >> precio;

    this->precio = precio;
}

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

    NodoDoble(int);
};

NodoDoble::NodoDoble(int historico){ 
    p.setNombre();
    p.setPrecio();
    p.id = historico+1;
    Anterior = NULL;
    Siguiente = NULL;
}

class ListaDoble{
public:
    int contador;   
    int historico;
    NodoDoble* Cabecera;
    NodoDoble* Cola;
    
    ListaDoble();

    void InsertarInicio();
    void InsertarFinal();

    void RemoverInicio();
    void RemoverFinal();
    void VaciarLista();

    void OrdenarLista();
    void MostrarLista();
};

ListaDoble::ListaDoble(){
    contador = 0;
    historico = 0;
    Cabecera = NULL;
    Cola = NULL;
}

void ListaDoble::InsertarInicio(){
    NodoDoble* nuevoNodo = new NodoDoble(historico);

    nuevoNodo->Siguiente = Cabecera;

    if(Cabecera != NULL)
        Cabecera->Anterior = nuevoNodo;

    Cabecera = nuevoNodo;

    if(contador == 0)
        Cola = Cabecera;

    contador++;
    historico++;
}

void ListaDoble::InsertarFinal(){
    if(contador == 0){
        InsertarInicio();
    }
    else{
        NodoDoble* nuevoNodo = new NodoDoble(historico);
        Cola->Siguiente = nuevoNodo;
        nuevoNodo->Anterior = Cola;
        Cola = nuevoNodo;
        contador++;
        historico++;
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

void ListaDoble::OrdenarLista(){
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

void ListaDoble::MostrarLista(){
    NodoDoble* nodo = Cabecera;

    while(nodo != NULL){
        nodo->p.mostrar();
        nodo = nodo->Siguiente;
    }

    cout <<"Fin de la lista..." << endl;
}

void opciones(int);
ListaDoble* lista = new ListaDoble();

int main(){
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
            lista->OrdenarLista();
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
}



