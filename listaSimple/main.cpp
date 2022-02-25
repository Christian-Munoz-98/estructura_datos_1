#include <iostream>
#include "ListaEnlazada.h"

using namespace std;

/*
int main()
{
    ListaEnlazada *linkedList = new ListaEnlazada();
    int index;
    bool confirmation;

    /*cout << "Buscar: " << endl;
    index = linkedList->Buscar("ADIOS");
    if(index==-1)
        cout << "Elemento no encontrado..." << endl;
    else
        cout << "ADIOS: Encontrado en el indice " << index << endl;
    cout << endl << endl;

    linkedList->InsertarInicio("HOLA");
    linkedList->InsertarInicio("MUNDO");
    linkedList->InsertarFinal(" CRUEL");
    linkedList->InsertarFinal("ADIOS");
    linkedList->Insertar(4, "JAJAJAJA");
    linkedList->Insertar(3, "JJEJEJE");
    linkedList->Insertar(0, "JIJIJI");

    linkedList->ImprimirLista();
    /*cout << "Buscar: " << endl;
    index = linkedList->Buscar("SDFDGFSD");
    if(index==-1)
        cout << "Elemento no encontrado..." << endl;
    else
        cout << "ADIOS: Encontrado en el indice " << index << endl;
    cout << endl << endl;

    
    // Remove first element
    cout << "Remover incio:" << endl;
    linkedList->RemoverInicio();
    // 76->43->15->48->44->100->NULL
    cout << "Remover final:" << endl;
    linkedList->RemoverFinal();
    linkedList->ImprimirLista();
    cout << endl;

    // Remove fifth element
    cout << "Remover por busqueda:" << endl;
    confirmation = linkedList->Remover(linkedList->Buscar("ADIOS"));
    if(!confirmation)
        cout << "Elemento no encontrado..." << endl;
    else
        cout << "Elemento eliminado con exito"<< endl;
    cout << endl << endl;
    // 76->43->15->48->100->NULL
    linkedList->ImprimirLista();
    cout << endl;

    // Nothing happen
    // 76->43->15->48->100->NULL
    linkedList->ImprimirLista();
    cout << endl;

    cout<<"Tamano de lista: " << linkedList->Tamano() << endl;
    cout<<"Primer elemento: " << linkedList->Primero()->frase << endl;
    cout<<"Ultimo elemento: " << linkedList->Ultimo()->frase << endl;
    linkedList->InsertarInicio("HOLA");
    linkedList->InsertarInicio("MUNDO");
    linkedList->InsertarFinal(" CRUEL");
    linkedList->InsertarFinal("ADIOS");
    linkedList->Insertar(4, "JAJAJAJA");
    linkedList->Insertar(3, "JJEJEJE");
    linkedList->Insertar(0, "JIJIJI");
    linkedList->ImprimirLista();
    linkedList->VaciarLista();
    linkedList->ImprimirLista();
    return 0;
}
*/

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
