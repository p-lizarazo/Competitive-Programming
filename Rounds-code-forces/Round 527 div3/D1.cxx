#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main(){
	int n, v1, v2;
	cin >> n;
	vi values(n);
	vector<vii> adj_list(n);
	vi visited(n,0);
	
	for(int i=0;i<n;++i){
		cin >> values[i];
	}
	
	for(int i=0;i<n-1;++i){
		cin >> v1 >> v2;
		adj_list[v1-1].push_back({v2-1,1});
		adj_list[v2-1].push_back({v1-1,1});
	}
	
	for
	queue<int> levels;
	
	
	
	// make BFS
	
	
	return 0;
}

