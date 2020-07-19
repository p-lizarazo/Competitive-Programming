#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int A,B;
        cin >> A >> B;
        long long b;
        b=9;
        long long cont = 0;
        while(b<=B){
            b=b*10+9;
            cont+=A;
        }
        cout << cont << "\n";
    }

    return 0;
}
