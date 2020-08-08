// https://vjudge.net/contest/385427#problem/B

#include <bits/stdc++.h>
#define MAXN 100500
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
        st[v] = 0;
    }
}

void update(int v, int tl, int tr, int l, int r){
    if(l>r){
        return;
    }
    if( l == tl &&  r == tr){
        st[v]+=1;
    } else {
        int tm = (tl+tr)/2;
        update(2*v, tl, tm,l,min(tm,r));
        update(2*v+1, tm+1, tr, max(l,tm+1),r);
    }
}

int query(int v, int tl, int tr, int pos){
    if(tl==tr){
        return st[v];
    }
    int tm = (tl+tr)/2;
    if(pos<=tm){
        return st[v] + query(2*v,tl,tm,pos);
    } else {
        return st[v] + query(2*v+1, tm+1, tr, pos);
    }
}

int main()
{
    cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
    int tests;
    int n,q;
    cin >> tests;
    int cont = 1;
    while(tests--){
        string s;
        cin >> s;
        input = vector<int>(s.size());
        n = s.size();
        for(int i=0;i<(int)s.size();++i){
            input[i] = s[i] - '0';
        }
        build(1,0,n-1);
        cin >> q;
        cout << "Case " << cont++ << ":\n";
        for(int i=0;i<q;++i){
            char k;
            cin >> k;
            int q1,q2;
            if(k == 'Q' || k == 'q'){
                cin >> q1;q1--;
                cout << query(1,0,n-1,q1)%2 << '\n';
            } else if(k=='I' || k== 'i'){
                cin >> q1 >> q2;
                q1--;q2--;
                update(1,0,n-1,q1,q2);
            }
        }
    }



    return 0;
}
