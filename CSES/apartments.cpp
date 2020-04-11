#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, k; cin >> n >> m >> k;
    int point1,point2;
    point1 = point2 = 0;
    vector<int> app(n);
    vector<int> suites(m);

    for(int i=0;i<n;++i){
        cin >> app[i];
    }
    sort(app.rbegin(), app.rend());

    for(int i=0;i<m;++i){
        cin >> suites[i];
    }
    sort(suites.rbegin(), suites.rend());

    int cont = 0;
    while(point1 != n && point2 != m){
        if( suites[point2] >= app[point1]-k && suites[point2] <= app[point1]+k){
            cont++;
            point2++;
            point1++;
        } else if(suites[point2] < app[point1]-k ){
            point1++;
        } else if(suites[point2] > app[point1]+k){
            point2++;
        } else {
            assert(false);
        }
    }

    cout << cont << "\n";

    return 0;
}
