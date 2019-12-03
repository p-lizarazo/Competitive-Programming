
#include <bits/stdc++.h>

using namespace std;

int main(){
    long long rooms;
    cin >> rooms;

    for(int i=0;i<rooms;++i){
        long long cant, sections;
        cin >> cant >> sections;

        if(cant>=sections){
            cout << sections;

        } else {
            long long mod = sections % cant;
            long long val = sections / cant;

            long long res = 0;

            res+= (cant - mod) * (val*val);
            res+= (mod) * ( (val + 1) * (val + 1)  );
            cout << res;
        }
        cout << "\n";

    }


    return 0;
}
