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
	
	double a,b,c;
	cin >> a >> b >> c;
	a = (a+b+c)/6;
	cout.precision(17);
	cout << a;
	
	return 0;
}
