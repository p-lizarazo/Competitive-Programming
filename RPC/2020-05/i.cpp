#include <bits/stdc++.h>

using namespace std;

string replacestr(string& s){
    string news = "";
    for(char& x : s){
        char w;
        switch(x){
        case '0':
            w = 'O';
            break;
        case '1':
            w = 'L';
            break;
        case '2':
            w = 'Z';
            break;
        case '3':
            w = 'E';
            break;
        case'5':
            w = 'S';
            break;
        case '6:':
            w = 'B';
            break;
        case '7':
            w = 'T';
            break;
        case '8':
            w = 'B';
            break;
        default:
            w = x;
            break;
        }
        news+=w;
    }
    return news;
}

int main(){
    cin.tie(0);ios_base::sync_with_stdio(false);
    int N,M;
    cin >> N >> M;
    vector<string> bad_words(N);
    vector<string> plates(M);

    for(auto& x : bad_words){
        cin >> x;
    }
    for(auto& x : plates){
        cin >> x;
        string aux = replacestr(x);
        bool valid = true;
        for(auto& bad : bad_words){
            if(aux.find(bad) != string::npos){
                valid=false;
                break;
            }
        }
        if( valid )
            cout << "VALID\n";
        else
            cout << "INVALID\n";
    }


    return 0;
}

