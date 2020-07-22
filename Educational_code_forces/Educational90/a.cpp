#include <bits/stdc++.h>

using namespace std;

int main(){
    int tcases;
    cin >> tcases;
    while(tcases--){
        long long a,b,c;
        cin >> a >> b >> c;
        int n1,n2;
        n1=n2=-1;
        if(c<a*b)
            n2 = b;
        if(a<c)
            n1 = 1;

        cout << n1 << " " << n2 << "\n";
    }

    return 0;
}

