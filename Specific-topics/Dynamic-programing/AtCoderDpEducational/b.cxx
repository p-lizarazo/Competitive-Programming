
#include <bits/stdc++.h>

using namespace std;

#define INF 2e9

using ii = pair<int,int>;

int main()
{
    cin.tie(0);ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> heights(n);
    vector<int> dp(n,INF);
    dp[0] = 0; //minimum cost
    for(auto& x : heights)
    {
        cin >> x;
    }

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<=k;j++){
            if(i-j>=0)
                dp[i] = min(dp[i],dp[i-j] + abs(heights[i] - heights[i-j]));
        }
    }

    cout << dp[n-1] << '\n';


    return 0;
}

