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
	for(int i=0;i<n;++i){
		std::string str="";
		cin >> str;
		std::stack<char> mystack;
		bool tr = true;
		for(int j=0;j<(int)str.length();++j){
			if(mystack.empty() && (str[j]==')' || str[j]==']')){
				tr=false;
				break;
			}
			if(str[j]=='(' || str[j]=='['){
				mystack.push(str[j]);
			} else {
				char c;
				c=mystack.top();
				mystack.pop();
				if(str[j] == ')' && c == '['){
					tr=false;
					break;
				} else if(str[j] == ']' && c== '('){
					tr=false;
					break;
				} else {
					continue;
				}
			}
		}
		if(!mystack.empty()){
			 tr=false;
		}
		tr?cout<<"YES\n" : cout << "NO\n";
		
	}

	
	
	return 0;
}
