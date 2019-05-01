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

int main(){
	
	int n;
	cin >> n;
	long sum=0;
	std::vector<int> pi(n),ti(n);

	for(int i=0;i<n;++i){
		cin >> pi[i];
	}
	for(int i=0;i<n;++i){
		cin >> ti[i];
	}
	
	bool t_ti=false;
	bool t_pi=false;
	
	for(int i=0;i<n;++i){
		if(pi[i]>ti[i]){
			sum+=pi[i];
			t_pi=true;
		} else {
			sum+=ti[i];
			t_ti=true;
		}
	}
	
	long maxsum=0;
	if(!t_ti){
		for(int i=0;i<n;++i){
			maxsum = std::max(maxsum,sum-pi[i]+ti[i]);
		}
		cout << maxsum;
	} else if(!t_pi){
		for(int i=0;i<n;++i){
			maxsum = std::max(maxsum,sum+pi[i]-ti[i]);
		}
		cout << maxsum;
	} else{
		cout << sum;
	}
	
	return 0;
}
