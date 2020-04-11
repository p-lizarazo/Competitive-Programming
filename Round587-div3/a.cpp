#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    string s = "";
    int cont = 0;
    for(int i=0;i<n;i+=2){
        char a,b;
        cin >> a >> b;
        if(a == b){
            cont++;
            s+="ab";
        } else {
            s+= a;
            s+= b;
        }
    }

    cout << cont << "\n" << s << "\n";

    return 0;
}

