#include <bits/stdc++.h>

using namespace std;

#define INF 2e9

using ii = pair<int,int>;

int main()
{
    cin.tie(0);ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> heights(n);
    vector<int> dp(n,INF);
    dp[0] = 0; //minimum cost
    for(auto& x : heights)
    {
        cin >> x;
    }

    for(int i=0;i<n;++i)
    {
        if(i-1>=0)
            dp[i] = min(dp[i],dp[i-1] + abs(heights[i] - heights[i-1]));
        if(i-2>=0)
            dp[i] = min(dp[i],dp[i-2] + abs(heights[i] - heights[i-2]));
    }

    cout << dp[n-1] << '\n';


    return 0;
}

