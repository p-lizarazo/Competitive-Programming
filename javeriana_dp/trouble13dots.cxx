#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(){
	int money, items;
	while(cin >> money >> items){
		
		//if(money>=1801) money+=200;
		
		vector<int> dp(money+300,0); // dp[i] maximum total favour with i money y gastando j plata
		vector<int> wasted(money+300,0); // wasted[i] means how much money wasted with i money
		// si tengo 1801, y gasto 2001 todo bien
		
		
		for(int i=0;i<items;++i){
			int price, value;
			cin >> price >> value;
			for(int j=money+200;j>=0;j-=price){
				if(j-price>=0){
					if(dp[j-price]+value > dp[j] ){
						dp[j] = dp[j-price]+value;
						wasted[j] = wasted[j-price]+price;
						/*
						if(wasted[j-price]+price>1801){
							
						} else {
							
						}
						* */
					}
					//dp[j]=max(dp[j], dp[j-price]+value);
				}
			}
		}
		/*
		for(auto x:dp){
			cout << x << " ";
		}
		*/
		cout << dp[money] << " "<< wasted[money] << "\n";
		//cout << dp[money] << "\n";
		
		
	}
	
	
	
	
	return 0;
}
