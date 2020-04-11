#include <bits/stdc++.h>

using namespace std;

long long sum[10000009];

int main(){
    long long n, k, t;
    cin >> t;

    for(int i=0;i<10000009;++i){
        sum[i] = 2LL*i + 1LL + (i>0 ? sum[i-1] : 0LL);
    }

    for(int i=0;i<t;++i){
        cin >> n >> k;

        if(k > n || n < sum[k-1] ){
            cout << "NO\n";
            continue;
        }


        if(n % 2 == 0 && k % 2==0){
            cout << "YES";
        } else if (n % 2 == 1 && k%2==1){
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << "\n";
    }

    return 0;
}
