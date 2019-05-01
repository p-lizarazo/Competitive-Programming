#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	cin.tie(0);
	int n,m,h; // length width height
	cin >> n >> m >> h;
	
	vector<int> mview(m), nview(n);
	vector< vector<int> > top(n,vector<int>(m));
	for(int i=0;i<m;++i){
		cin >> mview[i];
	}
	for(int j=0;j<n;++j){
		cin >> nview[j];
	}
	
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin >> top[i][j];
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(top[i][j]==1){
				top[i][j] = min(mview[j],nview[i]);
			}
		}
	}
	
	
	for(int i=0;i<n;++i){
		for(int j=0;j<m;j++){
			if(j!=m-1)
				cout << top[i][j] << " ";
			else
				cout << top[i][j] << "\n";
		}
	}
	
	
	return 0;
}
