#include "Pila.cpp"

int main(){
	Pila* p = new Pila();
	int opcion;

	do{    
		system("cls");
		cout<<
		"\n\n[1].Insertar Top"<<endl
		<<"[2].Eliminar Top"<<endl
		<<"[3].Mostrar Top"<<endl
		<<"[4].Mostrar Tamano"<<endl
		<<"[5].Vaciar Pila"<<endl
		<<"[6].Mostrar Pila"<<endl
		<<"[0].Salir"<<endl
		<<"Ingrese una opcion>>> ";
		cin>>opcion;
		switch(opcion){
			case 1:
				p->Push();
				break;
			case 2:  
				p->Pop();
				break;
			case 3:  
				p->ShowTop();
				break;
			case 4:
				p->Tamanho();
				break;
			case 5:
				p->Vaciar();
				break;
			case 6:
				p->MostrarPila();
				break;
			case 0:
				cout<<"Finalizando..."<<endl;
				system("pause");
				break;
			default:
				cout<<"Opcion invalida..."<<endl;	  	        
				system("pause");
		}
	}while(opcion!=0);
	return 0;
}