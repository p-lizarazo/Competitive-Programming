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
	std::stack <ll> values;
	int n;
	cin >> n;
	for(int i=0;i<n;++i){
		char c;
		cin >> c;
		if(c=='*' || c=='+' || c=='-'){
			ll val1 = values.top();
			values.pop();
			ll val2 = values.top();
			values.pop();
			
			switch(c){			
				case '+':
					values.push(val1 + val2);
				break;
				case '-':
					values.push(val2 - val1);
				break;
				case '*':
					values.push(val1 * val2);
				break;
			}
		}
		else 
			values.push( (int) (c-'0'));
	}
	
	cout << values.top();

	return 0;
}
