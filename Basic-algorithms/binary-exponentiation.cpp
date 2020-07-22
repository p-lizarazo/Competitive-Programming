#include <bits/stdc++.h>

#define M 1000000007

using namespace std;

int binary_exp(int a, int b)
{
    // a^b
    int result = 1;
    while(b>0){
        if(b%2==1){
            result = (result * a)%M;
        }
        a = (a * a) %   M;
        b/=2;
    }
    return result;
}



int main()
{
    int a,b;
    cin >> a >> b;
    cout << binary_exp(a,b) << endl;

    int result = 1;
    for(int i=0;i<b;++i)
    {
        result*=a;
    }

    cout << result;
}
