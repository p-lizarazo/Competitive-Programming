#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        set<int> princess, kingdom;
        for(int i=1;i<=n;++i){
            princess.insert(i);
            kingdom.insert(i);
        }

        for(int i=1;i<=n;++i){
            int k;
            cin >> k;
            bool found = false;
            for(int j=0;j<k;++j){
                int temp;
                cin >> temp;
                if( !found && kingdom.count(temp) != 0){
                    kingdom.erase(temp);
                    princess.erase(i);
                    found = true;
                }
            }
        }

        if(!princess.empty() && !kingdom.empty()){
            cout << "IMPROVE\n";
            cout << *princess.begin() << " " << *kingdom.begin() << '\n';
        } else {
            cout << "OPTIMAL\n";
        }
    }



    return 0;
}
