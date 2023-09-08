#include <bits/stdc++.h>
using namespace std;


int main () {
//	int n;
//	string stones;
//	int contador = 0;
//	
//	cin>>n;
//	cin>>stones;
//	
//	
//	for (int i=0; i<stones.length(); i++) {
//		
//		if (stones[i] == stones[i+1]){
//				contador++;
//		}	
//		
//	}
//	cout<<contador;
//	return 0;
	int n;
	double ingresa, contador, final;
	cin>>n;
	vector<int> vasos;
	
	
	for (int i=0; i < n; i++){
		cin>>ingresa;
		vasos.push_back(ingresa);
	}
	
	for (int i=0; i < n; i++){
		contador += vasos[i];
	}
	
	final = contador / n;
	cout<<final;
}
