#include <bits/stdc++.h>
#define foi(i,k,n) for(int i = (int)k; i < (int)n; ++i)

using namespace std;
typedef long long ll;

template<class T>
struct persistent_stack{
	private:
	T value;
	persistent_stack* next;
	public:
	persistent_stack(){
		next = NULL;
	};
	persistent_stack(const T& val, persistent_stack<T>* ne){
		this->value = val;
		this->next = ne;
	}
	T top(){ return value; }
	persistent_stack* push(const T& element){
		return new persistent_stack<T>(element, this);
	}
	persistent_stack* pop(){
		return (next);
	}
	bool empty(){
		if(next==NULL){
			return true;
		}
		else return false;
	}
	
};

int main(){
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
	int n;
	cin >> n;
	vector< persistent_stack< pair<long,long> >* > input2(n);
	
	persistent_stack< pair<long,long> > cero({0,0},NULL);
	
	foi(i,0, n){
		long t,m;
		cin >> t >> m;
		if(t==0){
			input2[i] = ( cero.push( pair<long,long>(m,m) ));
		} else {
			if(m==0){ input2[i] = input2[t-1]->pop(); }
			else {
				input2[i] = ( input2[t-1]->push( pair<long,long>(m,input2[t-1]->empty()?m:input2[t-1]->top().second+m) ));
			}
		}
	}
	
	ll sum=0;
	foi(i,0,n){
		if(!input2[i]->empty()){
			sum+=input2[i]->top().second;
		}
	}
	cout << sum;
	
	
	
	
	return 0;
}
