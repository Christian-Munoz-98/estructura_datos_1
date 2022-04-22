#include <iostream>
using namespace std;

void printArray(int arr[], int arrSize){
    for (int i=0; i < arrSize; ++i)
        cout << arr[i] << ", ";
    cout << endl;
}

void InsertionSort(int arr[], int arrSize){

    for(int i = 0; i < arrSize; i++){
        int refValue = arr[i];
        int j;

        for(j = i - 1; j >= 0; j--){
            if(arr[j] > refValue){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j + 1] = refValue;

    }
}

int main()
{
    cout << "Insertion Sort" << endl;

    int arr[] = {46,710,35,467,4,6,7,95,22,23,84,67,10,3,5,71,3};
    int arrSize = sizeof(arr)/sizeof(*arr);

    cout << "Initial array: ";
    printArray(arr,arrSize);

    InsertionSort(arr, arrSize);

    printArray(arr,arrSize);

    return 0;
}

