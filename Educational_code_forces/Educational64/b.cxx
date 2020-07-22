#include<bits/stdc++.h>

using ll = long long;
using namespace std;


int main(){
	//cin.tie(0);ios::sync_with_stdio(false);
	int n;
	cin >> n;
	
	while(n--){
		int letters[26];
		memset(letters, 0,sizeof(letters));
		string s;
		cin >> s;
		for(int i=0;i<(int)s.size();++i){
			letters[ s[i]-'a' ]++;
		}
		
		int ant = 0;
		string res = "";
		int empty = true;
		while( true ){
			
			for(int i=0;i<26;++i){
				if(letters[i]!=0){
					empty = false;
				}
			}
			
			if(empty) break;
			
			bool made_stm = false;
			for(int i=0;i<26;++i){
				if(abs(i-ant ) != 1 && letters[i]>0 ){
					cout << i-ant << endl;
					for(int j=0;j<letters[i];j++){
						res+='a'+i;
					}
					letters[i]=0;
					cout << "ant " << ant;
					ant = i;
					made_stm = true;
				}
			}
			if(!made_stm) break;
			
		}
		
		int res_cont = 0;
		for(int i=0;i<26;++i){
			if(letters[i]!=0){
				res_cont++;
			}
		}
		
		if(res_cont == 1){
			string new_str = "";
			for(int i=0;i<26;++i){
				if(letters[i]!=0 && i!=1){
					for(int j=0;j<letters[i];++j){
						new_str+='a'+i;
					}
					break;
				}
			}
			res = new_str + res;
			
			if(res.size()==s.size())
				cout << res;
			else
				cout << "No answer";
			
		} else if(res_cont == 0){
			cout << res;
		} else {
			cout << "No answer";
		}
		cout << "\n";
		
		
		
		
		
		
	}
	
	
	
	return 0;
}
