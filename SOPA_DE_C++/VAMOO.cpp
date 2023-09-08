#include <iostream>

using namespace std;

int main(){
int arreglo[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	int i = 0, j = 19;
	
	
	while( i <= j ){
        int medio = (i + j) / 2;
		if (arreglo[medio] == 17){
            cout<<"El numero fue encontrado";
            return 17;
        }

        if (17 < arreglo[medio]){
            j = medio - 1; //16
             cout<<j<<endl;
        }

        else {
            i = medio + 1; //15
            cout<<i<<endl;
        }
	}
}
