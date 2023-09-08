
#include <bits/stdc++.h>
using namespace std;


int main () {
	string str;
	getline(cin,str);
	int contador = 0;
	sort(str.begin(),str.end());
	
	for (int i=0; i<str.length(); i++){
		if (str[i] != str[i+1]){
			contador += 1;
		}
	}
	
	
	if (contador % 2 == 0) cout<<"CHAT WITH HER!";
	else cout<<"IGNORE HIM!"; 
	
	return 0;
}
