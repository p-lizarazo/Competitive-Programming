#include <bits/stdc++.h>

using namespace std;

int N,NUMBER_B,NUMBER_W;
int grid[50][50];

int solve(){
    for(int i=0;i<N;++i){
        int bl_r,wh_r,bl_c,wh_c,cont_r,cont_c;
        bl_r = wh_r = bl_c = wh_c = 0;
        cont_r = cont_c = 1;
        for(int j=0;j<N;++j){
            if(cont_r>=3 || cont_c>=3){
                return 0;
            }
            if(j>0 && grid[j-1][i]==grid[j][i])
                cont_c++;
            else
                cont_c=1;

            if(j>0 && grid[i][j-1]==grid[i][j])
                cont_r++;
            else
                cont_r=1;

            if(grid[i][j]==0){
                wh_r++;
            } else {
                bl_r++;
            }
            if(grid[j][i]==0){
                wh_c++;
            } else {
                bl_c++;
            }

        }
        if(bl_r != wh_r || bl_c != wh_c){
            return 0;
        }
    }
    return 1;
}

int main(){
    NUMBER_B = NUMBER_W = 0;
    cin >> N;
    for(int i=0;i<N;++i){
        for(int j=0;j<N;j++){
            char b;
            cin >> b;
            if(b=='W'){
                grid[i][j] = 1;
                NUMBER_W++;
            } else {
                NUMBER_B++;
                grid[i][j] = 0;
            }
        }
    }

    cout << solve() << "\n";

    return 0;
}

