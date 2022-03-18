#include "Cola.cpp"

int main(){
    int opcion;
   	Cola* c = new Cola();

    do{
        system("cls");
        cout<<"[1]Insertar"<<endl;
        cout<<"[2]Eliminar"<<endl;
        cout<<"[3]Mostrar primero"<<endl;
        cout<<"[4]Mostrar ultimo"<<endl;
        cout<<"[5]Mostrar tamano"<<endl;
        cout<<"[6]Vaciar cola"<<endl;
        cout<<"[7]Mostrar cola"<<endl;
        cout<<"[0]Salir"<<endl;
        cout<<"ingrese opcion >> ";
        cin>>opcion;
        switch(opcion){
            case 1: 
                c->Queue();
                break;
            case 2: 
                c->DeQueue();
                break;     
            case 3: 
                c->First();
                break;	    
            case 4: 
                c->Last();   
                break;
            case 5: 
                c->Tamanho();
                break;
            case 6: 
                c->Vaciar();
                break;     
            case 7: 
                c->MostrarCola();
                break;	    
            case 0: 
                cout<<"Finalizando..."<<endl;
                system("pause"); 
                break;
            default:
                cout<<"Opcion Invalida..."<<endl;
                system("pause");                
        }
    }while(opcion!=0);
}