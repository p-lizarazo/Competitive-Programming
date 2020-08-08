// https://vjudge.net/contest/385427#problem/D

#include <bits/stdc++.h>
#define MAXN 1000000

using namespace std;

int st[4*MAXN];
vector<int> input;

int build(int v, int tl, int tr){
    if(tl==tr){
        st[v] = input[tl];
        return 0;
    } else {
        int tm = (tl+tr)/2;
        build(2*v, tl, tm);
        int op = build(2*v+1,tm+1,tr);
        if(op == 0)
            st[v] = st[2*v] | st[2*v+1];
        else
            st[v] = st[2*v] ^ st[2*v+1];
        return  op^1;
    }
}

int update(int v, int tl, int tr, int pos, int val){
    if(tl==tr){
        st[v] = val;
        return 0;
    }
    int tm = (tl+tr)/2;
    int op;
    if(pos<=tm){
        op = update(2*v,tl,tm, pos, val);
    } else{
        op = update(2*v+1,tm+1,tr,pos,val);
    }
    if(op == 0)
        st[v] = st[2*v] | st[2*v+1];
    else
        st[v] = st[2*v] ^ st[2*v+1];
    return op^1;
}

int main(){
    cin.tie(0);ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    n = 1 << n;
    input = vector<int>(n);

    for(auto& x: input){
        cin >> x;
    }

    build(1, 0, n-1);

    while(m--){
        int q,p;
        cin >> q >> p;
        update(1,0,n-1,q-1,p);
        cout << st[1] << "\n";
    }

}
