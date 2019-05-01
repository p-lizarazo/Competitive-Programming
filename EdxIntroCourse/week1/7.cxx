#include <bits/stdc++.h>
#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif


typedef long long ll;
ll h,w;


int dist(char a, char b, std::vector< std::vector<char> > letters){
	int a_i,a_j,b_i,b_j;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(letters[i][j] == a){
				a_i = i;
				a_j = j;
			}
			if(letters[i][j] == b){
				b_i = i;
				b_j = j;
			}
		}
	}
	
	return std::max( abs(b_i - a_i) , abs(b_j-  a_j) );
}

int main(){
	
	
	cin >> w >> h;
	std::vector< std::vector<char> > in(h,std::vector<char>(w) );
	for(int i=0;i<h;++i){
		for(int j=0;j<w;++j){
			cin >> in[i][j];
		}
	}
	
	ll respuesta=1e9;
	std::string reslang;
	for(int i=0;i<3;++i){
		std::string lang,line,parr="",ign;
		cin >> lang;
		cin >> ign;
		while( std::getline(cin,line) && line!= "%TEMPLATE-END%" ){
			parr+=line;
		}
		ll minimo=0;
		
		int j=1;
		
		parr.erase(remove_if(parr.begin(), parr.end(), isspace), parr.end());
		if(parr.length()==0){
			reslang = lang;
			respuesta = 0;
			break;
		}
		char fi=parr[0];
		
		while(j!=(int)parr.length()){
			if( (int)parr[j]!=32 ){
				minimo+=dist(fi,parr[j],in);
				fi=parr[j];
			}
			j++;
		}
		
		if(minimo < respuesta){
			reslang = lang;
			respuesta = minimo;
		}
		
	}
	cout << reslang << "\n" << respuesta;	
	
	return 0;
}
