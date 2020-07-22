#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000000
int n, t[4*MAXN], //Segment tree stores at most 4*n vertices
  input[MAXN];
/*
    this function may be modified depending upon we want the max/min
    multiplication e.t.c.
*/
void build(int t[],int a[], int v, int tl, int tr)
{
    if (tl==tr){
        t[v] = a[tl];
    }
    else {
        int tm = (tl + tr)/2;
        build(t,a,2*v,tl,tm);
        build(t,a,2*v+1,tm+1,tr);
        t[v] = t[2*v] + t[2*v+1];
    }
}

int query(int t[],int v, int tl, int tr, int l, int r)
{
    if(l>r){
        return 0;
    }
    if(tl==l && tr==r){
        return t[v];
    }
    int tm = (tl+tr)/2;
    return query(t, 2*v, tl, tm, l, min(r,tm) )
        + query(t, 2*v+1, tm+1, tr, max(l,tm+1) ,r);

}

void update(int t[],int v, int tl, int tr, int pos, int new_val){
    if(tl==tr){
        t[v] = new_val;
    } else {
        int tm = (tl+tr)/2;
        if(tm<=pos)
            update(t,2*v,tl,tm,pos,new_val);
        else
            update(t,2*v+1,tm+1,tr,pos,new_val);

        t[v] = t[2*v]+t[2*v+1];
    }
}


int main(){
    cin >> n;
    for(int i=0;i<n;++i){
        cin >> input[i];
    }

    build(t,input, 1, 0, n-1);

    cout << "Input query l, r \n";
    int lq,rq; cin >> lq >> rq;
    cout << query(t,1,0,n-1,lq,rq);


    return 0;
}
