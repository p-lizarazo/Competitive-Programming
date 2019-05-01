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
	
	std::stack< int > mystack;
	int n;
	cin >> n;
	char sign;
	for(int i=0;i<n;++i){
		cin >> sign;
		if(sign=='+'){
			ll t;
			cin >> t;
			mystack.push(t);
		} else {
			cout << mystack.top() << "\n";
			mystack.pop();
		}
	}
	
	
	return 0;
}
