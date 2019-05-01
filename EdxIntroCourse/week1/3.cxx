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

//using namespace std;
typedef long long ll;

ll MAX = 10e5+10;
std::vector<ll> dp(MAX,MAX);


ll fibo(int n){
	
	if(dp[n]!=MAX){
		return dp[n];
	} else{
		dp[n] = fibo(n-1) + fibo(n-2) - fibo(n-3);
		return dp[n];
	}
}

int main(){
	ll a,b,c,n;
	cin >> a >> b >> c >> n;
	dp[0]=a;
	dp[1]=b;
	dp[2]=c;
	cout << fibo(n);
	return 0;
}


