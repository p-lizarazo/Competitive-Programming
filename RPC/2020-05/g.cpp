#include <bits/stdc++.h>

using namespace std;

int main(){
    set<int> posibles;
    posibles.insert(2018);

    int myMonth = 3;
    int m_year = 2018;
    while(m_year < 10050){
        m_year+=2;
        myMonth+=2;
        if(myMonth>=12){
            myMonth%=12;
            m_year++;
        }
        posibles.insert(m_year);
    }

    int year;
    cin >> year;
    if(posibles.find(year) != posibles.end()){
        cout <<  "yes";
    } else {
        cout << "no";
    }
    cout << "\n";

    return 0;
}
