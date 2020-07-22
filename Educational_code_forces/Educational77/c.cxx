#include <bits/stdc++.h>

using namespace std;

int main(){
    int t_cases;
    cin >> t_cases;
    while(t_cases--){
        int r,b,k;
        cin >> r >> b >> k;
        int mini = min(r,b);
        int maxi = max(r,b);

        int res = maxi-1;
        int m = round(res*1.0/mini*1.0);
        int mcd = __gcd(mini,maxi);

        if(mcd != 1){
            m--;

        }


        if(m>=k){
            cout << "REBEL";
        } else {
            cout << "OBEY";
        }
        cout << "\n";

    }

    return 0;
}
