#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
/*
bool ok(str){
	stack<char> s;
	for(int i=0;i<str.size();++i){
		if( str[i] == '(' ){
			s.push();
		} else {
			if(s.empty()){
				return false;
			} else {
				s.pop();
			}
		}
	}
	
	if(s.empty()){
		return true;
	}
}
*/
void solve(string& str ){
	string strleft = str;
	stack<char> s;
	for(int i=0;i<(int)str.size();++i){
		if( str[i] == '(' ){
			s.push('(');
		} else if( str[i] == ')' ){
			if(s.empty()){
				str = "X";
			} else {
				s.pop();
			}
		} else if( str[i] == '?' ){
			if(s.empty()){
				str[i] = '(';
				s.push('(');
			} else {
				str[i] = ')';
				s.pop();
			}
		} else {
			assert(false);
		}
	}
	// ((((?))))((((?))))
	if(s.empty() && str!="X"){
		return;
	}
	
	str = strleft;
	while(!s.empty()) s.pop();
	s = stack<char>();
	
	for(int i=str.size()-1;i>=0;--i){
		if( str[i] == ')' ){
			s.push(')');
		} else if( str[i] == '(' ){
			if(s.empty()){
				str = "X";
			} else {
				s.pop();
			}
		} else if( str[i] == '?' ){
			if(s.empty()){
				str[i] = ')';
				s.push(')');
			} else {
				str[i] = '(';
				s.pop();
			}
		} else {
			cout << "WTF";
			assert(false);
		}
	}
	
	if(!s.empty()) str="X";
	
	return;
}

int main(){
	cin.tie(0);
	int n;
	cin >> n;
	string str;
	cin >> str;
	if(n%2==1 || str[n-1] == '(' || str[0] == ')' ){
		cout << ":(" << "\n";
		return 0;
	}
	
	str[n-1] = ')';
	string new_str;
	for(int i=1;i<n-1;++i){
		new_str+=str[i];
	}
	solve(new_str);
	if(new_str=="X"){
		cout << ":(" << "\n";
	} else{
		cout << "(";
		for(const auto& c:new_str){
			cout << c;
		}
		cout << ")";
	}
	
	
	return 0;
}
