#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n; cin >> n;
    vector< pair<int, bool> > events(2*n);

    for(int i=0;i<n;++i)
    {
        int in,off;
        cin >> in >> off;
        events[2*i] = {in, true};
        events[2*i+1] = {off, false};
    }

    int maxi = 0;
    int actual = 0;

    sort(events.begin(), events.end());

    for(int i=0;i<2*n;++i)
    {
        maxi = max(actual, maxi);
        actual += events[i].second ? 1 : -1;
    }

    cout << maxi << '\n';

}
