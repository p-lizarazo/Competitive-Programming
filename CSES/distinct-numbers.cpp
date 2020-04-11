#include <bits/stdc++.h>

using namespace std;

int main(){
    map<int,bool> nums;
    int n; cin >> n;
    while(n--){
        int a;
        cin >> a;
        nums[a] = true;
    }

    cout << nums.size() << "\n";


    return 0;
}
