#include <iostream>
#include "ListaDoble.h"


/*
+Operaciones
--anterior
--siguiente
*/

using namespace std;

int main()
{
    ListaDoble* lista = new ListaDoble();

    lista->InsertarInicio();

    lista->InsertarInicio();

    lista->InsertarFinal();

    lista->InsertarFinal();

    cout << "Mostrar:" << endl;
    lista->MostrarLista();
    cout << endl;

    lista->InsertarMedio(4);

    lista->InsertarMedio(3);

    lista->InsertarMedio(0);

    cout << "Mostrar Reversa:" << endl;
    lista->MostrarReversa();
    cout << endl;

    return 0;
}

/*
#include <iostream>

using namespace std;

void opciones(int);

int main(){
    int opc;
    do{
        system("cls");
        cout<<"1)Opcion 1"<<endl
        <<"2)Opcion 2" <<endl
        <<"3)Opcion 3"<<endl
        <<"4)Opcion 4"<<endl
        <<"5)Opcion 5"<<endl
        <<"6)Opcion 6"<<endl
        <<"7)Opcion 7"<<endl
        <<"8)Opcion 8"<<endl
        <<"9)Opcion 9"<<endl
        <<"10)Opcion 10"<<endl
        <<"11)Opcion 11"<<endl
        <<"12)Opcion 12"<<endl
        <<"13)Salir"<<endl
        <<"Elija una opcion >>>>>";
        cin>>opc;
        opciones(opc);
    }while(opc!=13);
    return 0;
}

void opciones(int opc){
    switch (opc){
    case 1:

        system("cls");
        system("pause");
        break;

    case 2:

        system("cls");
        system("pause");
        break;

    case 3:

        system("cls");
        system("pause");
        break;
    
    case 4:

        system("cls");
        system("pause");
        break;

    case 5:

        system("cls");
        system("pause");
        break;
        

    case 6:

        system("cls");
        system("pause");
        break;

    case 7:

        system("cls");
        system("pause");
        break;

    case 8:

        system("cls");
        system("pause");
        break;

    case 9:

        system("cls");
        system("pause");
        break;

    case 10:
    
        system("cls");
        system("pause");
        break;

    case 11:
    
        system("cls");
        system("pause");
        break;

    case 12:
    
        system("cls");
        system("pause");
        break;

    case 13:
    
        system("cls");
        system("pause");
        break;

    case 14:
    
        system("cls");
        system("pause");
        break;

    case 15:
    
        system("cls");
        cout << "Saliendo.." << endl;
        system("pause");
        break;

    default:
        system("cls");
        cout<<"Opcion Invalida..."<<endl;
        system("pause");
        break;
    }
}
*/
