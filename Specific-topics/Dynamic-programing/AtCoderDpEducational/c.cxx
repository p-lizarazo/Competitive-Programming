#include <bits/stdc++.h>

using namespace std;

#define INF 2e9

int main(){
    int n;
    cin >> n;
    vector<vector<int>> happiness(n, vector<int>(3));
    vector<vector<int> > dp(n, vector<int>(3, -INF)); // Maxima felicidad eligiendo a la actividad X

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<3;j++)
        {
            int a; cin >> a;
            happiness[i][j] = a;
        }
    }

    for(auto x : {0,1,2}){
        dp[0][x] = happiness[0][x];
    }

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<3;j++){
            if(i-1>=0)
                for(int k=0;k<3;k++){
                    if(j!=k){
                        dp[i][j] = max(dp[i][j], dp[i-1][k] + happiness[i][j]);
                    }
                }
        }
    }


    int maxi = -INF;
    for(int i=0;i<3;++i){
        maxi = max(maxi, dp[n-1][i]);
    }

    cout << maxi << '\n';



    return 0;
}
