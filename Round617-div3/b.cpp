#include <bits/stdc++.h>

typedef long long ll;

using namespace std;



int main(){
    int test;
    cin >> test;
    while(test--){
        ll money;
        cin >> money;
        ll wasted = 0;
        while(money>=10){
            ll remain = money%10;
            wasted+= money-remain;
            money = money/10;
            money+=remain;
        }
        wasted += money;

        cout << wasted << "\n";
    }


    return 0;
}
