#include "ListaDoble.h"

void opciones(int);
ListaDoble* copiarlista(ListaDoble*);

ListaDoble* lista = new ListaDoble();

int main(){
    int opc;
    do{
        system("cls");
        cout<<"1)Anadir producto"<<endl
        <<"2)Eliminar ultimo producto" <<endl
        <<"3)Vaciar inventario"<<endl
        <<"4)Mostrar Lista"<<endl
        <<"5)Ordenar Lista (Insert Sort)"<<endl
        <<"6)Ordenar Lista (Merge Sort)"<<endl
        <<"7)Ordenar Lista (Selection Sort)"<<endl
        <<"8)Ordenar Lista (Quick Sort)"<<endl
        <<"9)Salir"<<endl
        <<"Elija una opcion >>>>>";
        cin>>opc;
        opciones(opc);
    }while(opc!=9);
    return 0;
}

void opciones(int opc){
    bool confirmation;
    NodoDoble* NodoEncontrado;
    string nombre;
    float precio;
    int id;
    switch (opc){
    case 1:
        system("cls");
        cout << "ANADIR PRODUCTO" << endl << endl;
        cout<<"Indique nombre: ";
        cin>>nombre;
        cout<<"Indique precio: ";
        cin>>precio;
        cout<<"Indique id: ";
        cin>>id;        
        lista->InsertarFinal(nombre,precio,id);
        system("pause");
        break;

    case 2:
        cout << "ELIMINAR PRODUCTO" << endl << endl;
        system("cls");
        if (lista->Cabecera==NULL){
            cout << "La lista esta vacia" << endl;
        }
        else{
            lista->RemoverFinal();
            cout<<"Producto eliminado"<<endl;       
        }
        system("pause");
        break;

    case 3:
        system("cls");
        cout << "VACIAR LA LISTA" << endl << endl;
        if (lista->Cabecera==NULL){
            cout << "La lista esta vacia" << endl;
        }
        else
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
    {
        system("cls");
        ListaDoble* insertlist = copiarlista(lista);
        cout << "ORDENAR LISTA (INSERT SORT)" << endl << endl;
        if (lista->Cabecera==NULL){
            cout << "La lista esta vacia" << endl;
        }
        else{
            insertlist->InsertSort();
            cout<<"Lista ordenada exitosamente..."<<endl;
            insertlist->MostrarLista();
        }
        system("pause");
        break;
    }
    case 6:
    {
        system("cls");
        ListaDoble* mergelist = copiarlista(lista);
        cout << "ORDENAR LISTA (MERGE SORT)" << endl << endl;
        if (lista->Cabecera==NULL){
            cout << "La lista esta vacia" << endl;
        }
        else{
            mergelist->MergeSort(mergelist->Cabecera,mergelist->Cola);
            cout<<"Lista ordenada exitosamente..."<<endl;
            mergelist->MostrarLista();
        }
        system("pause");
        break;
    }
    case 7:
    {
        system("cls");
        ListaDoble* selectionlist = copiarlista(lista);
        cout << "ORDENAR LISTA (SELECTION SORT)" << endl << endl;
        if (lista->Cabecera==NULL){
            cout << "La lista esta vacia" << endl;
        }
        else{
            selectionlist->SelectionSort();
            cout<<"Lista ordenada exitosamente..."<<endl;
            selectionlist->MostrarLista();
        }
        system("pause");
        break;
    }
    case 8:
    {
        system("cls");
        ListaDoble* quicklist = copiarlista(lista);
        cout << "ORDENAR LISTA (SELECTION SORT)" << endl << endl;
        if (lista->Cabecera==NULL){
            cout << "La lista esta vacia" << endl;
        }
        else{
            quicklist->QuickSort(quicklist->Cabecera,quicklist->Cola);
            cout<<"Lista ordenada exitosamente..."<<endl;
            quicklist->MostrarLista();
        }
        system("pause");
        break;
    }
    case 9:
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

ListaDoble* copiarlista(ListaDoble*original){
    ListaDoble* copia = new ListaDoble();

    NodoDoble* ref = original->Cabecera;

    while(ref){
        copia->InsertarFinal(ref->p.nombre,ref->p.precio,ref->p.id);
        ref = ref->Siguiente;
    }

    return copia;
}


