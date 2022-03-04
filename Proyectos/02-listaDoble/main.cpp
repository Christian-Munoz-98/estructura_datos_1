#include <iostream>
#include "ListaDoble.h"


/*
+Operaciones
--anterior
--siguiente
*/

using namespace std;
void opciones(int);
ListaDoble* lista = new ListaDoble();

int main(){
    int opc;
    do{
        system("cls");
        cout<<"1)Insertar"<<endl
        <<"2)Eliminar" <<endl
        <<"3)Buscar"<<endl
        <<"4)Primero"<<endl
        <<"5)Ultimo"<<endl
        <<"6)Tamanho"<<endl
        <<"7)Vaciar"<<endl
        <<"8)Mostrar Lista"<<endl
        <<"9)Salir"<<endl
        <<"Elija una opcion >>>>>";
        cin>>opc;
        opciones(opc);
    }while(opc!=9);
    return 0;
}

void opciones(int opc){
    char insert;
    int index;
    //bool confirmation;
    string animal;
    NodoDoble* NodoEncontrado;
    switch (opc){
    case 1:
        system("cls");
        cout << "INSERTAR ELEMENTO" << endl << endl;
        cout <<"a)Insertar al inicio"<< endl
        <<"b)Insertar al final"<< endl
        <<"c)Insertar en indice intermedio"<< endl
        <<"Elija una opcion>>>";
        cin>>insert;
        switch (insert){
            case 'a':
                lista->InsertarInicio();
                break;
            case 'b':
                lista->InsertarFinal();
                break;
            case 'c':
                cout<<"ELija un indice>>";
                cin>>index;
                lista->InsertarMedio(index);
                break;
            default:
                cout<<"Opcion invalida"<<endl;
                break;
        }
        break;

    case 2:
        system("cls");
        cout << "ELIMINAR ELEMENTO" << endl << endl;
        cout << "Ingrese el nombre del animal a eliminar>>>";
        cin >> animal;
        lista->RemoverMedio(lista->BuscarIndice(animal));
        cout << "Elemento removido con exito" << endl;
        system("pause");
        break;

    case 3:
        system("cls");
        cout << "BUSCAR ELEMENTO" << endl << endl;
        cout << "Inngrese el animal a buscar>>>";
        cin >> animal;
        NodoEncontrado = lista->Buscar(lista->BuscarIndice(animal));
        NodoEncontrado->a.mostrar();
        system("pause");
        break;
    
    case 4:
        system("cls");
        cout << "MOSTRAR EL PRIMER ELEMENTO" << endl << endl;
        if(lista->Cabecera==NULL){
            cout << "La lista esta vacia" << endl;
        }
        else{
            lista->Primero()->a.mostrar();
        }
        system("pause");
        break;

    case 5:
        system("cls");
        cout << "MOSTRAR EL PRIMER ELEMENTO" << endl << endl;
        if(lista->Cabecera==NULL){
            cout << "La lista esta vacia" << endl;
        }
        else{
            lista->Ultimo()->a.mostrar();
        }
        system("pause");
        break;
        

    case 6:
        system("cls");
        cout << "MOSTRAR TAMANO DE LA LISTA" << endl << endl;
        cout << "La lista tiene " << lista->Tamanho() << " elementos" << endl;
        system("pause");
        break;

    case 7:
        system("cls");
        cout << "VACIAR LA LISTA" << endl << endl;
        lista->VaciarLista();
        system("pause");
        break;

    case 8:
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
