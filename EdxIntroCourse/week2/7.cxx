#include <bits/stdc++.h>
#define foi(i,k,n) for(int i = (int)k; i < (int)n; ++i)

using namespace std;
typedef long long ll;

int main(){
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    map<int,int> m;
    
    int n;
    cin >> n;
    foi(i,0,n){
		int read;
		cin >> read;
		if(i==0 || read!=0){
			m[1]++;
		} else {
			auto begin = m.begin();
			m[begin->first+1]++;
			if(begin->second == 1){
				m.erase(begin);
			} else {
				begin->second--;
			}
		}
	}
	
	cout << m.size() << "\n";
	
	for(auto x : m){
		cout << x.first << " " << x.second << "\n";
	}
    
    
    return 0;
}
