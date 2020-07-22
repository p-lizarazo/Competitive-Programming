#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        int a;
        cin >> a;
        bool odd=false, even=false;
        int nodds = 0;
        for(int i=0;i<a;++i){
            int temp; cin >> temp;
            if(temp % 2==0){
                even = true;
            } else {
                odd = true;
                nodds++;
            }
        }
        if( (odd && even) || (odd && nodds%2==1)){
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << "\n";
    }

    return 0;
}

