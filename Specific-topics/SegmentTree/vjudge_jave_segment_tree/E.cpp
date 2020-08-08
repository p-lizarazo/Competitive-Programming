//https://vjudge.net/contest/385427#problem/E

#include <bits/stdc++.h>

using namespace std;

const int MAX = 100000;

struct st_node {
    int sum;
    int max_preffix;
    int max_suffix;
    int max_sum;
};

st_node st[4*MAX];
int arr[MAX];

st_node make_data(int val) {
    st_node res;
    res.sum = val;
    res.max_preffix = res.max_suffix = res.max_sum = val;
    return res;
}

st_node combine(const st_node& l_node,const st_node& r_node){
    st_node new_node;
    new_node.sum = l_node.sum + r_node.sum;
    new_node.max_preffix = max(l_node.sum + r_node.max_preffix, l_node.max_preffix);
    new_node.max_suffix = max(r_node.sum + l_node.max_suffix, r_node.max_suffix);
    new_node.max_sum = max(l_node.max_suffix + r_node.max_preffix, max(l_node.max_sum, r_node.max_sum) );
    return new_node;
}

void build(int v, int ls, int rs){
    if(ls==rs){
        st[v] = make_data(arr[ls]);
    } else {
        int tm = (ls+rs)/2;
        build(2*v, ls, tm);
        build(2*v+1, tm+1 , rs);
        st[v] = combine(st[2*v], st[2*v+1]);
    }
}

st_node query(int v, int ls, int rs, int l, int r){
    if(l>r){
        return make_data(0);
    }
    if(l == ls && r == rs){
        return st[v];
    }
    int tm =(ls+rs)/2;
    if(r <= tm) return query(2*v, ls, tm, l, r);
	else if(l > tm) return query(2*v+1, tm+1, rs, l, r);

    return combine(
        query(2*v, ls, tm, l, tm),
        query(2*v+1, tm+1, rs, tm+1 , r )
    );
}

int main(){
    cin.tie(0); ios_base::sync_with_stdio(false);
    int tests; cin >> tests;
    while(tests--){
        int n; cin >> n;
        for(int i=0;i<n;++i){
            cin >> arr[i];
        }
        build(1, 0, n-1);
        int q; cin >> q;
        for(int i=0;i<q;++i){
            int x1,x2,y1,y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1--;x2--;y1--;y2--;

            if(y1<x2){
                int q1 = query(1,0,n-1, x1, y1).max_suffix;
                int q2 = query(1,0,n-1, y1+1, x2-1).sum;
                int q3 = query(1,0,n-1, x2, y2).max_preffix;
                cout << q1+q2+q3 << "\n";
            } else { // x2 metido en x1

                int case2, case3, case4;
                case2 = (x2-1 >= 0 ? query(1,0,n-1, x1, x2-1).max_suffix : 0) + query(1,0,n-1, x2, y2).max_preffix;
                case3 = (y1+1 < n ? query(1,0,n-1, y1+1,y2).max_preffix : 0) + query(1,0,n-1,x1,y1).max_suffix;
                case4 = query(1,0,n-1, x2, y1).max_sum;
                cout << max(case2,max(case3, case4)) << "\n";
            }
        }
    }

    return 0;
}
