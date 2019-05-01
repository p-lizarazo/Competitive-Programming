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
	
	int in[3][3];
	for(int i=0;i<9;i++){
		cin >> in[i/3][i%3];
	}
	double ans = 0, realans=0;
	
	for(int i=0;i<3;++i){
		ans=0.0;
		for(int j=0;j<3;j++){
			if(j==i){
				continue;
			}
			for(int k=0;k<3;k++){
				if(k==i || k==j){
					continue;
				}
				ans=in[0][i]*in[0][i]+in[1][j]*in[1][j]+in[2][k]*in[2][k];
				realans = std::max(ans,realans);
			}
		}
	}
	cout.precision(17);
	cout << std::sqrt(realans);
	return 0;
}
