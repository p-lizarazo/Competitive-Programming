//https://vjudge.net/contest/385427#problem/A
#include <bits/stdc++.h>
#define MAXN 100050
#define INF 2e9
using namespace std;
int st[4*MAXN];
vector<int> input;


void build(int v, int tl, int tr){
    if(tl==tr){
        st[v] = input[tl];
    } else {
        int tm = (tl+tr)/2;
        build(2*v,tl,tm);
        build(2*v+1,tm+1,tr);
        st[v] = min(st[2*v],st[2*v+1]);
    }
}

int query(int v, int tl, int tr, int l, int r){
    if( l > r){
        return INF;
    }
    if(l==tl && r==tr){
        return st[v];
    }
    int tm = (tl+tr)/2;
    return min(query(2*v, tl, tm, l, min(tm,r)), query(2*v+1,tm+1,tr,max(l,tm+1), r) );


}

int main()
{
    cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
    int n, q, tests;
    cin >> tests;
    int cont = 1;
    while(tests--){
        cin >> n >> q;
        input = vector<int>(n);
        for(auto& x : input){
            cin >> x;
        }
        build(1,0,n-1);
        cout << "Case " << cont++ << ":\n";
        for(int i=0;i<q;++i){
            int a,b;
            cin >> a >>b;
            a--;b--;
            cout << query(1,0,n-1,a,b) << "\n";
        }

    }



    return 0;
}
