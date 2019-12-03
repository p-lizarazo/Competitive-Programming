#include <bits/stdc++.h>

using namespace std;

bool prime(int x){
    if(x<2) return false;
    for(int i=2;i*i<=x;++i){
        if( x%i == 0) return false;
    }
    return true;
}

vector<int> factors(int n){
    vector<int> res;

    for(int i=2;i*i<=n;++i){
        while(n%i==0){
            res.push_back(i);
            n/=i;
        }
    }
    if (n > 1) res.push_back(n);
    return res;
}

vector<int> sieve(int maxi){
    vector<int> primes(maxi+1,0);

    for(int i=2;i<=maxi;++i){
        if(primes[i]) continue;
        for(int j=2*i;j<=maxi;j+=i){
            primes[j]=1;
        }
    }
    return primes;
}

vector<int> sieveFactor(int maxi){
    vector<int> primes(maxi+1,0);

    for(int i=2;i<=maxi;++i){
        if(primes[i]) continue;
        for(int j=i;j<=maxi;j+=i){
            if(primes[j]==0){
                primes[j]=i;

            }

        }
    }
    return primes;
}

vector<int> findPrimes(int n, vector<int>& extendedSieve){
    vector<int> res;
    int i;
    do {
        i=extendedSieve[n];
        if(i<2){
            break;
        }
        n/=i;
        res.push_back(i);
    } while(n != 1);

    //if (n > 1) res.push_back(n);

    return res;
}

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);

}



int main(){
    int n, k;
    cin >> n >> k;
    vector<int> res1 = sieve(n);
    vector<int> res2 = sieveFactor(n);

    vector<int> res3 = findPrimes(k, res2);

    for(int i=0;i<=n;++i){
        cout <<  res1[i] << " ";

    }
    cout << endl;
    for(int i=0;i<=n;++i){

        cout <<  res2[i] << " ";

    }

    cout << endl;

    for(int i=0;i<res3.size();++i){
        cout << res3[i] << " ";
    }


    cout << endl;


    return 0;
}
