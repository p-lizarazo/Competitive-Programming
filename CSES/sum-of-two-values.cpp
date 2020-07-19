#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;

int main()
{
    map<int, vector<int> > m_map;

    vector<int> a;

    int n, target;
    cin >> n >> target;

    for(int i=0;i<n;++i)
    {
        int in; cin >> in;
        m_map[in].push_back(i);
    }

    int resa, resb;
    resa = resb = -1;
    for(const auto& el : m_map)
    {
        int expect = target - el.first;
        auto it = m_map.find(expect);
        if(it != m_map.end())
        {
            if( expect == el.first && it->second.size() == 1)
                continue;

            resa = el.second.front();
            resb = it->second.back();
            break;
        }
    }

    if(resa == -1){
        cout << "IMPOSSIBLE";
    } else {
        cout << resa+1 << " " << resb+1;
    }
    cout << "\n";

    return 0;
}
