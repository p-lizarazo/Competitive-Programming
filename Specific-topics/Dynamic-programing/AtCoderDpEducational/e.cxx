#include <bits/stdc++.h>

#define MAX_VAL 300010

using namespace std;

using ii = pair<int,int>;
using ll = long long;

int main()
{
    cin.tie(0);ios_base::sync_with_stdio(false);
    int N, W;
    cin >> N >> W;

    vector<ll> dp(MAX_VAL, numeric_limits<ll>::max());
    dp[0] = 0;

    for(int i=0;i<N;++i){
        ll w; int v; cin>>w>>v;
        for(int j=MAX_VAL;j>=0;j--){
            if(dp[j] != numeric_limits<ll>::max() && j+v < MAX_VAL){
                dp[j+v] = min(dp[j+v], dp[j] + w);
            }
        }
    }


    for(int i=MAX_VAL-1;i>=0;i--){
        if(dp[i] != numeric_limits<ll>::max() && dp[i] <=W){
            cout << i << '\n';
            break;
        }
    }
    return 0;
}
