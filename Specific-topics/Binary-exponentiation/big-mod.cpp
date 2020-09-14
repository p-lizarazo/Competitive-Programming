#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll binary_exp(ll x, ll y, ll n)
{
    ll res = 1;
    x %= n;
    while( y>0)
    {
        if(y&1)
        {
            res*=x;
            res%=n;
        }
        x*=x;
        x%=n;
        y>>=1;
    }
    return res;
}

int main(){
    cin.tie(0);ios_base::sync_with_stdio(false);
    ll x,y,n;
    while(cin >> x >> y >> n)
    {
        cout << binary_exp(x,y,n) << "\n";
    }

    return 0;
}
