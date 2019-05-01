#include <bits/stdc++.h>

using namespace std;


bool ok(const vector<string>& in, string word){
	
	vector<string> out(in.size(),"I");
	for(int i=0;i<(int)in.size();++i){
		for(int j=0;j<(int)in.size();++j){
			if( i!=j && out[i] == "I" && out[j] == "I" ){
				string str = in[i]+in[j];
				
				if(str == word){
					out[i] = "P";
					out[j] = "S";
					for(int k=0;k<(int)in.size();++k){
						if(k!=i && in[k].size() == in[i].size() && out[k]=="P" ){
							out[i] = "S";
						}
						if(k!=j && in[k].size() == in[j].size() && out[k]=="S"){
							out[j] = "P";
						}
					}
					
				}
			}
		}
	}
	
	for(auto c:out){
		if(c == "I"){
			return false;
		}
	}
	
	for(auto c:out){
		cout << c;
	}
	cout << "\n";
	return true;
}

int main(){
	int n;
	cin >> n;
	int tam = (2*n)-2;
	vector<string> in(tam);
	for(int i=0;i<tam;++i){
		cin >> in[i];
	}
	//probar con el primero S y primero P
	for(int i=0;i<tam;++i){
		for(int j=0;j<tam;j++){
			string str = in[i]+in[j];
			if(i!=j && (int)str.size() == n ){
				if( ok(in, str) ) return 0;
			}
		}
	}
	return 0;
}
