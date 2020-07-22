#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
    int n;
    cin >> n;
    int nums;
    for(int i=0;i<n;++i){
        cin >> nums;
        if(nums%2==0){
            int tam = nums/2;
            for(int j=0;j<tam;++j){
                cout << "1";
            }
            cout << "\n";
        } else {
            int tam = nums/2;
            cout << "7";
            for(int j=0;j<tam-1;++j){
                cout << "1";
            }
            cout << "\n";
        }
    }


    return 0;
}
