#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

vector<int> coins;
vector< vector<ll> > memo; // [i][j] max cantidad de poder cambiar monedas con la moneda j como maximo

const int MAX = 7490;

ll solve(int num, int max){
	//quiero llenar memo
	if(num < 0 || max <0)
		return 0;
		
	
	if(memo[num][max]!=-1) return memo[num][max];
	ll res = 0;
	
	res = solve(num,max-1) + solve(num-coins[max],max);
	
	memo[num][max]=res;
	return memo[num][max];
}

int main(){
	int n;
	memo = vector< vector<ll> >(MAX,vector<ll>(5,-1) );
	coins = vector<int>{1,10,5,50,25};
					
	for(int i=0;i<5;++i){
		memo[0][i]=1;
	}
	for(int i=0;i<MAX;++i){
		memo[i][0]=1; // de 1 manera puedo dar vueltas de cualq con monedas de 1
	}
	
	
	while(cin>>n){
		cout << solve(n,4) << "\n";
	}
	
	return 0;
}
