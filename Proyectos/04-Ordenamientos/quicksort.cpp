#include <iostream>

using namespace std;

class NodoDoble{
public:
    int val;
    NodoDoble* Anterior;
    NodoDoble* Siguiente;

    NodoDoble(int);
};

NodoDoble::NodoDoble(int val){ 
    this->val = val;
    Anterior = NULL;
    Siguiente = NULL;
}

class ListaDoble{
public:
    int contador;   
    NodoDoble* Cabecera;
    NodoDoble* Cola;
    
    ListaDoble();

    void Insertar(int);
    void Remover();
    void Vaciar();

    NodoDoble* Particion(NodoDoble*,NodoDoble*);
    void QuickSort(NodoDoble*,NodoDoble*);
    void Mostrar();
	void MostrarReversa();
};

ListaDoble::ListaDoble(){
    contador = 0;
    Cabecera = NULL;
    Cola = NULL;
}

void ListaDoble::Insertar(int val){
	NodoDoble* nuevoNodo = new NodoDoble(val);
    if(contador == 0){
    	
		nuevoNodo->Siguiente = Cabecera;

    	if(Cabecera != NULL)
        	Cabecera->Anterior = nuevoNodo;

    	Cabecera = nuevoNodo;

    	if(contador == 0)
        	Cola = Cabecera;

    	contador++;
    }
    else{
        
        Cola->Siguiente = nuevoNodo;
        nuevoNodo->Anterior = Cola;
        Cola = nuevoNodo;
        contador++;
    }
}


void ListaDoble::Remover(){
    if(contador == 0)
        cout<<"Lista Vacia..."<<endl;
    else if(contador == 1){
        NodoDoble* nodo = Cabecera;

        Cabecera = Cabecera->Siguiente;

        delete nodo;

        if(Cabecera != NULL)
            Cabecera->Anterior = NULL;

        contador--;
	}
    else{
        NodoDoble* nodo = Cola;

        Cola = Cola->Anterior;

        Cola->Siguiente = NULL;

        delete nodo;

        contador--;
    }
}

void ListaDoble::Vaciar(){
    int aux = contador;

    for(int i=1;i<=aux;i++){
        NodoDoble* nodo = Cabecera;

        Cabecera = Cabecera->Siguiente;

        delete nodo;

        if(Cabecera != NULL)
            Cabecera->Anterior = NULL;

        contador--;
    }

    cout << "Lista vaciada con exito" << endl;
}

NodoDoble* ListaDoble::Particion(NodoDoble* inicio,NodoDoble* final){
    cout<<"No errors in partitions"<<endl;
    NodoDoble* pivote = inicio;
    NodoDoble* enmedio = inicio;
    NodoDoble* ref = inicio->Siguiente;
    int tmp;
    while(ref!=NULL){
        if (ref->val<pivote->val){
            enmedio=enmedio->Siguiente;
            tmp = ref->val;
            ref->val = enmedio->val;
            enmedio->val = tmp;
        }
        ref=ref->Siguiente;
    }
    
    tmp = inicio->val;
    inicio->val = enmedio->val;
    enmedio->val = tmp;

    return enmedio;
    
}

void ListaDoble::QuickSort(NodoDoble* inicio,NodoDoble* final){
    if (inicio!=NULL&&final!=NULL){
        //cout<<"No errors in sorting"<<endl;
        NodoDoble* pivote = Particion(inicio,final);
        QuickSort(inicio,pivote->Anterior);
        QuickSort(pivote->Siguiente,final);
    }
}

void ListaDoble::Mostrar(){
    NodoDoble* nodo = Cabecera;

    while(nodo != NULL){
        cout << nodo->val << ",";
        nodo = nodo->Siguiente;
    }

    cout <<"Fin de la lista..." << endl;
}

int main()
{
	ListaDoble* lista = new ListaDoble();

	lista->Insertar(100);
	lista->Insertar(47);
	lista->Insertar(62);
	lista->Insertar(7123);
	lista->Insertar(990);
	lista->Insertar(1);
	lista->Insertar(256);
	lista->Insertar(32);
	lista->Insertar(578);
	lista->Insertar(81);
	lista->Insertar(42);
	lista->Insertar(103);
	lista->Insertar(231);
	lista->Insertar(78);
	lista->Insertar(90);
	lista->Insertar(10);
	lista->Insertar(26);
	lista->Insertar(2);
	lista->Insertar(67);
	lista->Insertar(234435);
	lista->Insertar(11);
	lista->Insertar(30);
	lista->Insertar(45);
	lista->Insertar(1001);
	lista->Insertar(98);
	lista->Insertar(100);
	lista->Insertar(34);
	lista->Insertar(23);
	lista->Insertar(578);
	lista->Insertar(10000);
	cout<<"Lista Desordenada: ";
	lista->Mostrar();
	lista->QuickSort(lista->Cabecera,lista->Cola);
	cout<<"Lista Ordenada: ";
	lista->Mostrar();
}


/*
#include <iostream>

using namespace std;

int Partition(int arr[],int startIndex,int endIndex)//recibe nodo de inicio y nodo final
{
    int pivot = arr[startIndex]; //pivote empieza en el primer nodo


    int middleIndex = startIndex; //medio empieza en el primer nodo

    for (int i = startIndex + 1; i <= endIndex; ++i)//itera desde el nodo siguiente al inicio hasta el final
    {
        if (arr[i] < pivot)
        {

            ++middleIndex; //si el nodo actual es menor al pivote recorremos el nodo de en medio al siguiente

            swap(arr[i], arr[middleIndex]); //intercambiamos el nodo actual y el de en medio
        }
    }

    swap(arr[startIndex], arr[middleIndex]); //intercambiamos el nodo de inicio y el de en medio 

    return middleIndex; //regresamos el nodo de en medio
}

void QuickSort(int arr[],int startIndex,int endIndex)//recibe nodo de inicio y final
{

    if (startIndex < endIndex) // que ninguno sea NULL
    {

        int pivotIndex = Partition(arr, startIndex, endIndex); //nodo pivote definido por particion 


        QuickSort(arr, startIndex, pivotIndex - 1); // el inicio y el anterior del pivote


        QuickSort(arr, pivotIndex + 1, endIndex); // siguiente del pivote y el final
    }
}

int main()
{
    cout << "Quick Sort" << endl;

    // Initialize a new array
    int arr[] = {25, 21, 12, 40, 37, 43, 14, 28};
    int arrSize = sizeof(arr)/sizeof(*arr);

    // Display the initial array
    cout << "Initial array: ";
    for (int i=0; i < arrSize; ++i)
        cout << arr[i] << " ";
    cout << endl;

    // Sort the array with QuickSort algorithm
    QuickSort(arr, 0, arrSize - 1);

    // Display the sorted array
    cout << "Sorted array : ";
    for (int i=0; i < arrSize; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
*/