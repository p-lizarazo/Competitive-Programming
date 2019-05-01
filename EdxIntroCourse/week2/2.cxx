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
	
	std::queue< int > myqueue;
	int n;
	cin >> n;
	char sign;
	for(int i=0;i<n;++i){
		cin >> sign;
		if(sign=='+'){
			ll t;
			cin >> t;
			myqueue.push(t);
		} else{
			cout << myqueue.front() << "\n";
			myqueue.pop();
		}
	}
	
	
	return 0;
}
