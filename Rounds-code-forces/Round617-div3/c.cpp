#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int main(){
    cin.tie(0);ios_base::sync_with_stdio(false);
    int test;
    cin >> test;

    while(test--){
        map<ii, vector<int> > times;
        times[{0,0}].push_back(0);
        int x=0,y=0;
        int tam;
        cin >> tam;
        for(int i=0;i<tam;++i){
            char a;
            cin >> a;
            switch(a){
                case 'L':
                    x -= 1;
                    break;
                case 'R':
                    x += 1;
                    break;
                case 'U':
                    y += 1;
                    break;
                case 'D':
                    y -= 1;
                    break;
            };
            times[{x,y}].push_back(i+1);
        }
/*

        for(const auto& vect: times){
            cout << "{{"<<vect.first.first <<  "," << vect.first.second << "}}KEY\n";
            for(const auto& el : vect.second){
                cout << el << " ";
            }
            cout << "\n";
        }
*/

        ll ini = -1, endi =-1, mini;
        mini = numeric_limits<ll>::max();
        for(const auto& vect : times){
            for(int j=0;j<vect.second.size()-1;++j){
                if( abs(vect.second[j+1] - vect.second[j]) < mini){
                    mini = abs(vect.second[j+1] - vect.second[j]);
                    if(vect.second[j+1] > vect.second[j]){
                        ini = vect.second[j];
                        endi = vect.second[j+1];
                    } else {
                        ini = vect.second[j+1];
                        endi = vect.second[j];

                    }
                }
            }
        }
        if(ini == -1 && endi == -1){
            cout << "-1";
        } else {
            cout << ini+1 << " " << endi;
        }

        cout << "\n";

    }

    return 0;
}

