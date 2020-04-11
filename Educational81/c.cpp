#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){

    int test_cases;
    cin >> test_cases;
    for(int i=0;i<test_cases;++i){
        map<char,set<int> > m;
        string s,t;
        cin >> s >> t;
        for(int i=0; i<s.size();++i){
            m[s[i]].insert(i);
        }
        bool valid = true;
        int cont = 1;
        int last = 0;
        for(int i=0;i<t.size();++i){
            if(m.find(t[i]) == m.end()){
                valid = false;
                break;
            } else {
                auto it = m[t[i]].lower_bound(last);
                if( it != m[t[i]].end()){
                    last = *it+1;
                } else {
                    auto it2 = m[t[i]].lower_bound(-1);
                    cont++;
                    last = *it2 + 1;
                }
            }
        }

        if(valid){
            cout << cont << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
