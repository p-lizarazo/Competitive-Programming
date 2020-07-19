#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;

    if(N==100){
        cout << "Even";
    } else if(N%2==0){
        if((N/2)%2==0){
            cout << "Even";
        } else {
            cout << "Odd";
        }
    } else{
        cout << "Either";
    }
    cout << "\n";
    return 0;
}
