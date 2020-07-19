#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

ull score(const ll& target,const vector<ll>& arr)
{
    ull sum = 0ULL;
    for(int i=0;i<(int)arr.size();++i){
        sum += abs(target-arr[i]) * 1ULL;
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    vector<ll> sticks(n);

    for(auto& val : sticks)
    {
        cin >> val;
    }

    ll a,b;
    a = 0; b = numeric_limits<int>::max();

    while(a<b){
        ll m = (a+b)/2;
        //cout << "valor m" << m << '\n';
        //cout << score(m, sticks) << " " << score(m+1, sticks) << '\n';
        if(score(m, sticks) >= score(m+1, sticks))
        {
            a = m+1;
        } else { // scoe m < score m+1
            b = m;
        }
    }

    //cout << b << '\n';
    cout << score(b,sticks) << '\n';


    return 0;
}
