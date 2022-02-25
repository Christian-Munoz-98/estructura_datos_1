#include <iostream>
#include "ListaEnlazada.h"

using namespace std;
void menu();
void opciones(int);
ListaEnlazada* lista = new ListaEnlazada();

int main(){
    menu();
    return 0;
}

void menu(){
    int opc;
    do{
        system("cls");
        cout<<"1)Insertar elemento"<<endl
        <<"2)Eliminar elemento" <<endl
        <<"3)Vaciar lista"<<endl
        <<"4)Buscar elemento"<<endl
        <<"5)Mostrar lista"<<endl
        <<"6)Mostrar primer elemento"<<endl
        <<"7)Mostrar ultimo elemento"<<endl
        <<"8)Mostrar tamano de la lista"<<endl
        <<"9)Salir"<<endl
        <<"Elija una opcion >>>>>";
        cin>>opc;
        opciones(opc);
    }while(opc!=9);
}

void opciones(int opc){
    string frase;
    char insert;
    int index;
    bool confirmation;
    switch (opc)
    {
    case 1:
        system("cls");
        cout << "INSERTAR ELEMENTO" << endl << endl;
        cout << "Ingrese una frase>>>";
        cin >> frase;
        cout << "a)Insertar al inicio" << endl
        << "b)Insertar al final" << endl
        << "c)Insertar en indice intermedio" << endl
        << "Elija una opcion>>>";
        cin>>insert;
        switch (insert){
            case 'a':
                lista->InsertarInicio(frase);
                break;
            case 'b':
                lista->InsertarFinal(frase);
                break;
            case 'c':
                cout<<"ELija un indice>>";
                cin>>index;
                lista->Insertar(index,frase);
                break;
            default:
                cout<<"Opcion invalida"<<endl;
                break;
        }
        system("pause");
        break;

    case 2:
        system("cls");
        cout << "Eliminar elemento" << endl << endl;
        cout << "Ingrese la frase a eliminar>>>";
        cin >> frase;
        confirmation = lista->Remover(lista->Buscar(frase));
        if(confirmation)
            cout << "Elemento removido con exito" << endl;
        else
            cout << "No fue posible remover el elemento debido a que no existe en la lista" << endl;
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
        cout << "BUSCAR ELEMENTO" << endl << endl;
        cout << "Inngrese la frase a buscar>>>";
        cin >> frase;
        index = lista->Buscar(frase);
        if (index==-1){
            cout<<"Frase No encontrada en la lista..." << endl;
        }
        else{
            cout << frase << ": Encontrada en el indice --> " << index << endl;
        }
        system("pause");
        break;

    case 5:

        system("cls");
        cout << "MOSTRAR LISTA" << endl << endl;
        if (lista->Cabecera==NULL){
            cout << "La lista esta vacia" << endl;
        }
        else{
            lista->ImprimirLista();
        }
        system("pause");
        break;
        

    case 6:
        system("cls");
        cout << "MOSTRAR EL PRIMER ELEMENTO" << endl << endl;
        if(lista->Cabecera==NULL){
            cout << "La lista esta vacia" << endl;
        }
        else{
            cout<< "El primer elemento de la lista es: " << lista->Primero()->frase << endl;
        }
        system("pause");
        break;

    case 7:
        system("cls");
        cout << "MOSTRAR EL ULTIMO ELEMENTO" << endl << endl;
        if(lista->Cabecera==NULL){
            cout << "La lista esta vacia" << endl;
        }
        else{
            cout<< "El ultimo elemento de la lista es: " << lista->Ultimo()->frase << endl;
        }
        system("pause");
        break;

    case 8:
        system("cls");
        cout << "MOSTRAR TAMANO DE LA LISTA" << endl << endl;
        cout << "La lista tiene " << lista->Tamano() << " elementos" << endl;
        system("pause");
        break;

    case 9:
        system("cls");
        cout << "SALIENDO..." << endl;
        system("pause");
        break;

    default:
        system("cls");
        cout<<"Opcion Invalida..."<<endl;
        system("pause");
        break;
    }
}
