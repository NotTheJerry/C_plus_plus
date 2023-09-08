// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//    int a,b,c,d,e,f;
//    string answer;
//    cin >> a >> b >> c >> d >> e >> f ;
//    
//    while (a,b,c,d,e,f >= 0 && a,b,c,d,e,f <= 9){
//    
//    if ( a+b+c == d+e+f ){
//        answer = "Yes";
//        cout << answer;
//        break;
//    }
//    else  {
//        answer = "No";
//        cout<< answer;
//        break;
//        }

//int *p;
//int variable = 10;
//p = &variable;					Imprime el valor que tiene en la memoria la variable "variable"
//cout<<*p;
//
//int *p;
//int variable = 10;				Imprime 10
//p = &variable;
//cout<<p;

// new int;

 
	// int arreglo[10] = {1,2,3,4,5,6,7,8,9,10};
	// int i = 0, j = 9;
	
	
	// // while ( i <= j ) {
    // //     int medio = (i + j) / 2;
	// // 	if (arreglo[medio] == 8){
    // //         cout<<"El numero fue encontrado";
    // //         return 8;
    // //     }

    // //     if (8 < arreglo[medio]){
    // //         j = medio - 1;
    // //     }

    // //     if (8 > arreglo[medio]) {
    // //         i = medio + 1;
    // //     }
	// }


   // }   //Corchete del main

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
    // cout<<*arr;
    cout << "Initial array: ";
    printArray(arr,arrSize);

    InsertionSort(arr, arrSize);

    printArray(arr,arrSize);

    return 0;
}
