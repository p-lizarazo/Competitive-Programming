// https://vjudge.net/contest/385427#problem/C

#include <bits/stdc++.h>
#define MAXN 1005000
#define INF 2e9
using ll = long long;
using namespace std;
ll st[4*MAXN];
vector<ll> input;


void build(int v, int tl, int tr){
    if(tl==tr){
        st[v] = input[tl];
    } else {
        int tm = (tl+tr)/2;
        build(2*v,tl,tm);
        build(2*v+1,tm+1,tr);
        st[v] = st[v*2+1] + st[2*v];
    }
}

void update(int v, int tl, int tr, int pos, int val){
    if(tl==tr){
        st[v]+=val;
        return;
    }
    int tm = (tl+tr)/2;
    if(pos<=tm){
        update(2*v,tl,tm,pos,val);
    } else {
        update(2*v+1, tm+1, tr, pos,val);
    }
    st[v] = st[2*v] + st[2*v+1];
}

int query(int v, int tl, int tr, int l, int r){
    if(l>r){
        return 0;
    }
    if(tl==l && tr==r){
        return st[v];
    }
    int tm = (tl+tr)/2;
    return query(2*v,tl,tm, l, min(r,tm))
        + query(2*v+1, tm+1, tr, max(l,tm+1), r);
}
#define ulk int
ulk main()
{
    cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
    int tests;
    cin >> tests;
    int n,q;
    int cont = 1;
    while(tests--){
        cin >> n >> q;
        input = vector<ll>(n);
        for(auto& x:input){
            cin >> x;
        }
        build(1,0,n-1);
        cout << "Case " << cont++ << ":\n";
        while(q--){
            int op, i, other;
            cin >> op >> i;
            if(op==1){
                int amount = query(1,0,n-1,i,i);
                cout << amount << "\n";
                update(1,0,n-1,i,-amount);
            } else if(op==2){
                cin >> other;
                update(1,0,n-1,i,other);
            } else {
                cin >> other;
                cout << query(1,0,n-1,i,other) << "\n";
            }
        }
    }



    return 0;
}
