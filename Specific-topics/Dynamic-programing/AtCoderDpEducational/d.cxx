#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
    ll N,W;
    cin >> N >> W;
    vector<ll> dp(W+1,0);

    for(int i=0;i<N;++i){
        ll w,v;
        cin >> w >> v;
        for(int j=W;j>=0;j--){
            if(j-w >=0)
                dp[j] = max(dp[j], dp[j-w] + v);
        }
    }

    ll maxi = 0;
    for(const auto& x : dp){
        maxi = max(maxi, x);
    }

    cout << maxi << '\n';


    return 0;
}
