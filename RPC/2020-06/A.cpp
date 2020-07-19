#include <bits/stdc++.h>

using namespace std;

int main(){
    string str;
    int n;
    cin >> str;
    int last_l = str[str.size()-1] - 'a';
    cin >> n;
    vector< pair<pair<int,int>,int> > poss(n); // last -> first
    vector< string > original_str (n);
    int i=0;
    for(auto &x : poss){
        cin >> str;
        original_str[i] = str;
        x = { {str[0] - 'a', i++}, str[str.size()-1] - 'a'} ;
    }

    sort(poss.begin(),poss.end());
    int resultado = -1;

    auto it = lower_bound(poss.begin(),poss.end(),make_pair(make_pair(last_l,0),0));
    if(it!=poss.end() && it->first.first == last_l){

        bool another_play = true;
        while(it->first.first == last_l){

            auto it2 = lower_bound(poss.begin(),poss.end(),make_pair(make_pair(it->second,0),0) );
            if(it2!=poss.end() && it2->first.second == it->first.second){
                it2++;
            }

            if(it2==poss.end() || it2->first.first != it->second){
                another_play = false;
                resultado = it->first.second;
                break;
            }
            it++;
        }

        if(another_play){
            it = lower_bound(poss.begin(),poss.end(),make_pair(make_pair(last_l,0),0));
            cout << original_str[it->first.second];
        } else {
            cout << original_str[resultado] << "!";
        }

    } else {
        cout << "?";
    }

    cout << endl;





    return 0;
}

