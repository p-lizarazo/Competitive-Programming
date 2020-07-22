#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;
struct point {
    int sx;
    int sy;
    int fx;
    int fy;
    bool visited;
    point(int sx, int sy, int fx, int fy):sx(sx),sy(sy), fx(fx), fy(fy){
        visited=false;
    }
};

// n, m, k < 200
int MVX[] =  {1, -1, 0,  0};
int MVY[] =  {0,  0, 1, -1};
char DIRS[] = {'D','U','R','L'};
//          D   U  R   L

int main(){

    int N,M,K;
    cin >> N >> M >> K;
    int cont = 0;

    string result = "";

    for(int i=0;i<2*K;++i){
        int a,b;
        cin >> a >> b;
    }

    for(int i=0;i<M-1;++i){
        result+= "L";
        cont++;
    }
    for(int i=0;i<N-1;++i){
        result+= "U";
        cont++;
    }

    for(int i=0;i<N;++i){
        for(int j=0;j<M-1;++j){
            string x = i%2 ? "L" : "R";
            cont++;
            result+= x;
        }
        if(i<N-1){

            result+= "D";
            cont++;
        }
    }

    cout << cont << endl << result << endl;


    return 0;
}
