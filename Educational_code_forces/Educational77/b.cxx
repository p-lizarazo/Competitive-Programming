#include <bits/stdc++.h>

using namespace std;

int main(){

    int t_cases;
    cin >> t_cases;

    for(int i=0;i<t_cases;++i){
        long long a,b;
        cin >> a >> b;
        if(a==0 && b==0 ){
            cout << "YES" << "\n";
            continue;
        }
        if(a==0 || b==0){
            cout << "NO" << "\n";
            continue;
        }



        long long x = (2*a-b)/3;
        long long  y = a - 2*x;

        if( x>=0 && y>=0 && 2*x + y == a && 2*y+x==b){
            cout << "YES";
        } else {
            cout << "NO";
        }


        cout << "\n";
    }


    return 0;
}
