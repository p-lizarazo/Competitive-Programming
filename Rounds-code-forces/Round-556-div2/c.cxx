#include<bits/stdc++.h>

using namespace std;

const int MAX = 2000000*2+10;

bool primes[MAX];

void preprocess(){
    memset(primes, true, sizeof(primes)); 
  
    for (int p=2; p*p<=MAX; p++) 
    { 
        if (primes[p] == true) 
        { 
            
            for (int i=p*2; i<=MAX; i += p) 
                primes[i] = false; 
        } 
    }
}


int main(){
	preprocess();
	
	primes[1] = false;
	
	int n;
	cin >> n;
	
	
	int twos=0,ones=0;
	for(int i=0;i<n;++i){
		int val; cin >> val;
		if(val==1){
			ones++;
		} else {
			twos++;
		}
		//cin >> bag[i];
	}
	/*
	for(int i=0;i<n;++i){
		if(i%2==1 && twos>0){
			cout << 2 << " ";
			twos--;
		} else if(i%2==0 && ones>0){
			cout << 1 << " ";
			ones--;
		} else if(ones>0){
			cout << 1 << " ";
			ones--;
		} else if(twos>0){
			cout << 2 << " ";
			twos--;
		}
			
	}
	*/
	
	vector<int> dp(ones+2*twos+1,0); //dp[i] number of primes with prefixsum i
	
	int prefixsum = 0;
	
	for(int i=0;i<n;++i){
		if(ones>0 && primes[prefixsum+1]){
			cout << 1 << " ";
			prefixsum+=1;
			ones--;
		} else if(twos>0 && primes[prefixsum+2]){
			cout << 2 << " ";
			prefixsum+=2;
			twos--;
		} else if(ones>0 && twos>0){
			if( (prefixsum+1) % 2 == 1){
				cout << 1 << " ";
				ones--;
				prefixsum+=1;
			} else {
				cout << 2 << " ";
				twos--;
				prefixsum+=2;
			}
		} else {
			if(ones>0){
				cout << 1 << " ";
				ones--;
			} else if(twos>0){
				cout << 2 << " ";
				ones--;
			}
		}
	}
	
	/*
	while(ones>0 && twos>0){
		if(prefixsum-2>=0){
			dp[prefixsum] = max(dp[prefixsum],max(dp[prefixsum-2]+1,dp[prefixsum-2]+2));
		}
	}
	*/
	
	/*
	bool ones_s = true;
	if(ones%2==0){
		ones--;
		ones_s=false;
	}
	for(int i=0;i<ones;++i){
		cout << 1 << " ";
	}
	for(int j=0;j<twos;++j){
		cout << 2 << " ";
	}
	
	if(!ones_s){
		cout << 1;
	}
	*/
	//cout << dp[ones+2*twos];
	cout << "\n";
	
	
	
	
	return 0;
}
