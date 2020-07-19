#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;

int main()
{
    int n;cin >> n;
    vector< ii > movies(n);
    for(int i=0;i<n;++i)
    {
        int in, off;
        cin >> in >> off;
        movies[i] = {off, in};
    }
    sort(movies.begin(),movies.end());

    int cont = 0;
    int last = 0;
    for(int i=0;i<n;++i){
        if(movies[i].second >= last){
            last = movies[i].first;
            cont++;
        }
    }
    cout << cont << '\n';
    return 0;
}
