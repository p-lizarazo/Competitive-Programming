#include <bits/stdc++.h>

using namespace std;

int main(){
    int cans;
    cin >> cans;

    vector< pair<int,int> > nums(cans);
    for(int i=0;i<cans;++i){
        int val;cin >> val;
        nums[i] = {val,i+1};
    }

    sort(nums.rbegin(), nums.rend());

    long long shots = 0;
    for(int i=0; i<cans;++i){
        shots+=(i*(nums[i].first)+1);
    }

    cout << shots << "\n";

    for(int i=0;i<cans;++i){
        cout << nums[i].second << " ";
    }
    cout << "\n";



    return 0;
}
