#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<ll> res(n); //res[i] is the best sum that ends in i

    for(int i=0;i<n;++i){
       ll val;
       cin >> val;
       if(i==0){
        res[i] = val;
       } else {
        res[i] = max(res[i-1]+val, val);
       }
    }
    ll maxi = numeric_limits<ll>::min();
    for(const auto& x : res){
        maxi = max(maxi, x);
    }

    cout << maxi << '\n';


    return 0;
}
