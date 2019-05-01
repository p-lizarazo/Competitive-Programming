#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

int main(){
	int n;
	cin >> n;
	vector<ii> in(n);
	vector<int> out(n);
	for(int i=0;i<n;++i){
		cin >> in[i].first;
		in[i].second = i;
	}
	sort(in.begin(),in.end());
	
	int type;
	bool valid=true;
	int outCont = 1;
	for(int i=0;i<n;++i){
		type = n-in[i].first;
		if(type<=0){
			valid=false;
			break;
		}
		for(int j=i;j<type+i;j++){
			if(in[j].first!=in[i].first){
				valid = false;
				break;
			}
			out[in[j].second]=outCont;
		}
		if(!valid){
			break;
		}
		outCont++;
		i+=type-1;
	}
	
	if(!valid){
		cout << "Impossible";
	} else {
		cout << "Possible\n";
		for(int i=0;i<n;++i){
			cout <<  out[i] << " ";
		}
	}
	
	return 0;
}
