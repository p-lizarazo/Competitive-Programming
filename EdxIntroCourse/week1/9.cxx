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

int main(){

	
	int n;
	cin >> n;
	std::vector<ll> in(n);
	for(int i=0;i<n;++i){
		cin >> in[i];
	}
	
	std::sort(in.begin(), in.end());
	
	ll sum=0;
	int cant=0;
	
	for(int i=0;i<(int)in.size();++i){
		sum+=in[i];
		if(sum<=18000){
			cant++;
		} else {
			break;
		}
	}
	
	cout << cant;
	return 0;
}
