#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct rect {
    bool is_rec;
    ll x1;
    ll x2;
    ll y1;
    ll y2;
};

rect solve(ll wx1, ll wx2, ll wy1, ll wy2,
                    ll bx1, ll bx2, ll by1, ll by2){
    if(bx1 >= wx2 || bx2 <= wx1 || by1 >= wy2 || by2 <= wy1){
        rect res;
        res.is_rec = false;
        return res;
    }
/*
    if(by2 >= wy2){
        // nos importa es by1
    }

    if(by1 <= wy1){
        //nos importa es by2
    }

    if(bx2 >= wx2){

    }

    if(bx1 >= wx1 ){

    }
    */
    rect res;
    res.is_rec = true;
    res.x1 = -2;
    res.x2 = -2;
    res.y1 = -2;
    res.y2 = -2;

    if(wx1-bx1 < 0 && wx2-bx2 > 0){
        //horizontal full
        res.x1 = wx1;
        res.x2 = wx2;
    } else if(wx1-bx1 < 0){
        res.x1 = wx1;
        res.x2 = bx1;
    } else if(wx2-bx2 > 0){
        res.x1 = bx2;
        res.x2 = wx2;
    }else{
        res.x1
        assert(false);
    }

    if(wy1-by1 < 0 && wy2-by2 > 0){
        //vertical full
        res.y1 = wy1;
        res.y2 = wy2;
    } else if(wy1-by1 < 0){
        res.y1 = wy1;
        res.y2 = by1;
    } else if(wy2-by2 > 0){
        res.y1 = by2;
        res.y2 = wy2;
    }else{
        assert(false);
    }
    return res;
}

int main(){

    ll x1, x2, x3, x4, x5, x6, y1, y2, y3 , y4, y5, y6;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >>y4 >> x5 >> y5 >> x6 >>y6;

    rect temp = solve(x1,x2,y1,y2,x3,x4,y3,y4);
    cout << "first " << temp.is_rec;
    rect ans = solve(temp.x1,temp.x2,temp.y1,temp.y2,x5,x6,y5,y6);

    cout << "second " <<ans.is_rec;
    return 0;
}
