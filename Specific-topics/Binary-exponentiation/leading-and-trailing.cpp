#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll binary_exp(ll x, ll y, ll n = 1000)
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
    int cases;
    cin >> cases;
    while(cases--)
    {
        ll x, y; cin >> x >> y;
        double logx = log10(x) * y;
        int first_digits = (int) pow(10,logx - floor(logx)+2);
        printf("%d...%03d\n", first_digits,binary_exp(x,y));
    }

    return 0;
}
