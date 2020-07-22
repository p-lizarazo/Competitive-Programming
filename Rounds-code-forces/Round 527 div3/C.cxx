#include <bits/stdc++.h>

using namespace std;

bool myfunction(string i,string j){  return (i.length()<j.length()) ;}

int main(){
	int n;
	cin >>n;
	string s;
	vector< string > ss(2*n-2);
	vector< string > out(2*n-2);
	
	vector< bool > check(2*n-2, false);
	
	for(int i=0;i<2*n-2;++i){
		string s;
		cin >> s;
		ss[i] = s;
		out[i] = s;
	}
	
	
	sort(ss.begin(),ss.end(),myfunction);
	
	if(ss[0]+ss[2*n-3] == ss[2*n-4]+ss[1] ){
		s = ss[0]+ss[2*n-3];
	} if(ss[0]+ss[2*n-4] == ss[2*n-3]+ss[1] ){
		s=ss[0]+ss[2*n-4];
	} if(ss[1]+ss[2*n-3] == ss[2*n-4]+ss[0] ){
		s=ss[1]+ss[2*n-3];
	} if(ss[1]+ss[2*n-4] == ss[2*n-3]+ss[0] ){
		s=ss[1]+ss[2*n-4];
	}
	
	
	vector< char> res(2*n-2,'w');
	
	for(int i=0;i<2*n-2;++i){
		for(int j=0;j<2*n-2;++j){
			if(out[i]+out[j] == s &&
				check[i]==false && check[j]==false && i!=j){
					
				check[i]=check[j]=true;
				res[i]='P';
				res[j]='S';
				for(int k=0;k<2*n-2;++k){
					if(out[k].length()==out[i].length() && check[k]==false){
						check[k]=true;
						res[k]='S';
					}
					if(out[k].length()==out[j].length() && check[k]==false){
						check[k]=true;
						res[k]='P';
					}
				}
			}
			else if(out[j]+out[i] == s &&
				check[i]==false && check[j]==false && i!=j){
					
				check[i]=check[j]=true;
				res[i]='S';
				res[j]='P';
				
				for(int k=0;k<2*n-2;++k){
					if(out[k].length()==out[i].length() && check[k]==false){
						check[k]=true;
						res[k]='P';
					}
					if(out[k].length()==out[j].length() && check[k]==false){
						check[k]=true;
						res[k]='S';
					}
				}
			}
		}
	}
	
	for(int i=0;i<2*n-2;++i){
			cout << res[i];
	}
	
	return 0;
}
