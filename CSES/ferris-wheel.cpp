#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m_weight; cin >> n >> m_weight;

    vector<int> children(n);
    for(int i=0;i<n;++i){
        cin >> children[i];
    }
    sort(children.begin(),children.end());

    int p1, p2;
    p1 = 0;
    p2 = n-1;
    int cont = 0;
    while(p2 - p1 >= 0 ){
        if(children[p1] + children[p2] <= m_weight){
            p1++;
            p2--;
        } else{
            p2--;
        }
        cont++;
    }

    cout << cont << "\n";

    return 0;
}
