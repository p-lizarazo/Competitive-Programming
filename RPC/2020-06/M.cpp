#include <bits/stdc++.h>

using namespace std;
using ii = pair<int,int>;

vector< vector<ii> > graph;
// AIR, BOAT, RAIL, TRUCK
// i*4+0   +1   +2   +3
unordered_map< string, int> types;
int NODES;

int solve(int node1, int node2){
    priority_queue< ii, vector<ii>, greater<ii> > pq; // 1 peso, 2 a donde va
    pq.push({0,node1});
    vector< long long > dist(NODES*4 + 2,1000000000);
    vector< bool > visited(NODES*4+2,false);
    dist[node1] = 0;

    while(!pq.empty()){
        ii my_pair = pq.top();pq.pop();
        int u = my_pair.second;
        int d= my_pair.first;
        visited[u] = true;

        if(d > dist[u])
            continue;

        for(int i=0;i<(int)graph[u].size();i++){
            if(visited[graph[u][i].first]){
                continue;
            }

            ii v = graph[u][i];
            if(v.second + dist[u] < dist[v.first]){
                dist[v.first] = v.second + dist[u];
                pq.push({ dist[v.first] , v.first});
            }
        }
    }

    return dist[node2];
}

int main(){
    types["AIR"] = 0;
    types["SEA"] = 1;
    types["RAIL"] = 2;
    types["TRUCK"] = 3;
    cin.tie(0); ios_base::sync_with_stdio(false);

    int tests;
    cin >> tests;
    string name;
    string name1, name2, type;


    while(tests--){
        int weight, nodes; cin >> nodes;
        NODES = nodes;
        graph = vector< vector<ii> >(nodes*4 + 2, vector<ii>());
        unordered_map< string, int > names;

        for(int i=0;i<nodes;++i){
            cin >> name >> weight;
            names[name] = i;
            for(int j=0;j<4;j++){
                for(int k=0;k<4;k++){
                    if(j!=k){
                        assert(i*4+j<nodes*4);
                        graph[i*4+j].push_back({i*4+k, weight});
                    }
                }
            }
        }


        // AIR, BOAT, RAIL, TRUCK
        // i*4+0   +1   +2   +3

        int conn; cin >> conn;
        for(int i=0;i<conn;++i){
            cin >> name1 >> name2 >> type >> weight;
            int position = types[type];
            graph[ names[name1]*4 + position ].push_back( {names[name2]*4 + position, weight });
            graph[ names[name2]*4 + position ].push_back( {names[name1]*4 + position, weight});
        }

        cin >> name1 >> name2; // El resutlado a cotuer
        int pos1, pos2;
        pos1 = names[name1]; pos2=names[name2];
        pos1*=4; pos2*=4;
        for(int i = 0 ;i<4;++i){
            graph[nodes*4].push_back({pos1+i,0});

            graph[pos2+i].push_back({nodes*4+1,0});
        }

        cout << solve( nodes*4 , nodes*4+1) << "\n";

    }

    return 0;
}

