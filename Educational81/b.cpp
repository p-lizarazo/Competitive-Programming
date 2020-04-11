
    #include<bits/stdc++.h>

    typedef long long ll;

    using namespace std;

    int main(){
        cin.tie(0); ios_base::sync_with_stdio(false);
        int test_cases;
        cin >> test_cases;

        ll n, x;
        for(int i=0;i<test_cases;++i){
            cin >> n >> x;

            vector<ll> diff(n);

            for(int j=0;j<n;j++){
                char a;
                cin >> a;
                ll val;
                if(a=='0'){
                    val = 1;
                } else {
                    val = -1;
                }
                diff[j] = (j>0 ? diff[j-1] : 0) + val;
            }
            ll res = 0;
            bool infi = false;
            for(const auto& el : diff){
                ll a;

                if(diff.back()==0){
                     a = (x-el);
                } else {
                    a = (x-el)/diff.back();
                }

                if(a*diff.back() + el == x){
                    //cout << "val a" <<a << "\n";
                    if(a>=0){
                        res++;
                    }
                    if(a>=0 && diff.back()==0){
                        infi = true;
                    }
                }
            }
            if(infi){
                cout << -1 << "\n";
            } else {
                if(x==0){
                    res++;
                }
                cout << res << "\n";
            }
            /*
            cout << "DIFFS ";
            for(auto x : diff){
                cout <<x << " ";
            }
            cout << "\n";
            */



            //ver si el ultimo multiplicado por Y + alguno del vector es = a la suma


            //1 0 1 2 1 2 + 3 2 3 4 3 4 + 5

        }

        return 0;
    }
