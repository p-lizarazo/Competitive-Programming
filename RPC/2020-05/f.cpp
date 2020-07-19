#include <bits/stdc++.h>

using namespace std;
using ic = pair<int,char>;

string sanitize(string s){
    string ms = "";
    for(const char& c: s){
        if(c>='a' && c<='z'){
            ms+=(c-'a'+'A');
        }
        if(c>='A' && c<='Z'){
            ms+=c;
        }
    }
    return ms;
}
int main(){
    string s;
    getline(cin,s);
    s = sanitize(s);

    vector<int> letters(26,0);
    /*
    int i=0;
    for(auto & x: letters){
        x.first =0;
        x.second=(char)i+'A';
        i++;
    }
    */

    for(const char& c: s){
        letters[c-'A']++;
    }

    sort(letters.rbegin(),letters.rend());


    long long cont = 0;
    cont+=(s.size()-1)*3;
    int val[] = {1,3,3,5,5,5,7,7,7,7,7,9,9,9,9,9,9,9,9,11,11,11,11,11,11,11,11,11,11,11,11,11
    };
// . .. - ... .- -. .... -- ..- -.. .-. ..... --. .-- -.- ...- -... ..-. .-..
// 1 3 3  5 5 5 7 7 7 7 7 9 9 9 9 9 9 9 9
    for(int i=0;i<26;++i){
        cont+= letters[i] * val[i];
    }

    cout << cont << "\n";






    return 0;
}

