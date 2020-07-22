// exercise from: https://vjudge.net/problem/LightOJ-1082
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define MAXN 1000000


/*
    this function may be modified depending upon we want the max/min
    multiplication e.t.c.
*/
void build(ll t[],ll a[], int v, int tl, int tr)
{
    if (tl==tr)
        t[v] = a[tl];
    else {
        int tm = (tl + tr)/2;
        build(t,a,2*v,tl,tm);
        build(t,a,2*v+1,tm+1,tr);
        t[v] = min(t[2*v], t[2*v+1]);
    }
}

ll query(ll t[],int v, int tl, int tr, int l, int r)
{
    if(l>r){
        return numeric_limits<int>::max();
    }
    if(tl==l && tr==r){
        return t[v];
    }

    int tm = (tl+tr)/2;
    return min( query(t, 2*v, tl, tm, l, min(r,tm) ), query(t, 2*v+1, tm+1, tr, max(l,tm+1) ,r));
}

ll t[4*MAXN], //Segment tree stores at most 4*n vertices
    input[MAXN];

int main(){

    cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
    int t_cases; cin >> t_cases;
    int m_case = 1;
    while(t_cases--){
        ll n,q;
        cin >> n >> q;
        for(int i=0;i<n;++i){
            ll in; cin >> in;
            input[i] = in;
        }

        build(t,input, 1, 0, n-1);
        cout << "Case " << m_case++ << ":\n";
        for(int i=0;i<q;++i){
            ll lq,rq; cin >> lq >> rq;
            lq--;rq--;
            cout << query(t,1,0,n-1,lq,rq) << "\n";
        }

    }


    return 0;
}
