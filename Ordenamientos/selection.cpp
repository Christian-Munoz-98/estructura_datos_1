#include <iostream>
using namespace std;

void swap(int* a, int* b){
    int* aux = a;
    a = b;
    b = aux;
}

void printArray(int arr[], int arrSize){
    for (int i=0; i < arrSize; ++i)
        cout << arr[i] << ", ";
    cout << endl;
}

void SelectionSort(int arr[], int arrSize){
    int minIndex;

    for(int i = 0; i < arrSize - 1; i++)
    {
        minIndex = i;

        for(int j = i + 1; j < arrSize; j++){
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    cout << "Selection Sort" << endl;

    int arr[] = {41,89,84,59,0,2,3,7,30,37,0,23,7,7,66,1,4,28,1,89};
    int arrSize = sizeof(arr)/sizeof(*arr);

    cout << "Initial array: ";
    printArray(arr,arrSize);

    SelectionSort(arr, arrSize);

    cout << "Final array: ";
    printArray(arr,arrSize);

    return 0;
}