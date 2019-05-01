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


int primes[] = {2,3,5,7,11,13,17,10};
int n_primes = 8;

int main(){
	
	ll k,mini=0,val, val2;
	cin >> k;
	int n, count;
	for(ll i=2;i<=k;++i){
		count = 1;
		val = i;
		for(ll j=0;j<n_primes && val >= primes[j];j++){
			n=0;
			while(val%primes[j]==0){
				val/=primes[j];
				n++;
			}
			count *= (1+n);
		}
		if(count>mini){
			mini = count;
			val2 = i;
		}
	}
	
	cout << k-val2+1;
	
	return 0;
}
