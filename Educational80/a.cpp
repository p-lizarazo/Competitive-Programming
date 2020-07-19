#include <bits/stdc++.h>

using namespace std;

long long valid(long long& n, long long& d, long long x){
    long long days = x + ceil(d/((x+1.0)*1.0));
    return days;
}
double valid2(long long& n, long long& d, long long x){
    double days = x + d/((x+1.0)*1.0);
    return days;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        long long n,d;
        cin >> n >> d;
        long long a, b;
        a = 0; b = numeric_limits<long long>::max();
        bool res = false;
        while(a<b){ // 1,2 -> 1
            long long m = (a+b)/2;
            double ftemp1 = valid2(n,d,m);
            double ftemp2 = valid2(n,d,m+1);
            long long temp1 = valid(n,d,m);
            long long temp2 = valid(n,d,m+1);
            if(temp1 <= n || temp2 <= n){
                res = true;
                break;
            }
            if(ftemp1>ftemp2){
                a=m+1;
            } else {
                b=m;
            }
        }
        cout << (res ? "YES" : "NO") << '\n';
    }

    return 0;
}
