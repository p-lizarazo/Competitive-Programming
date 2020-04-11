#include <bits/stdc++.h>

using namespace std;

// n, m, k < 200

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector< vector<bool> > board(n, vector<bool>(m), false);
    vector< vector<bool> > desired(n, vector<bool>(m), false);

    for(int i=0;i<k;++i){
        int sxi, syi;
        cin >> sxi >> syi;
        board[sxi][syi] = true;
    }
    for(int i=0;i<k;++i){
        int fxi, fyi;
        cin >> fxi >> fyi;
        desired[fxi][fyi] = true;
    }



    return 0;
}
