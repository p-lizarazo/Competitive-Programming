#include <bits/stdc++.h>
#define foi(i,k,n) for(int i = (int)k; i < (int)n; ++i)


using namespace std;
typedef long long ll;

template<class T>
struct min_stack{
	private:
	const T INF = numeric_limits<T>::max();
	stack<pair<T,T> > s; // element, min
	public:
	void push(const T& x){ s.push( pair<T,T>(x, min(x, getmin()))); }
	void pop(){ s.pop(); }
	bool empty(){ return s.empty(); }
	T getmin(){ return empty() ? INF : s.top().second; }
	T top(){ return s.top().first; }
};

template<class T> 
struct min_queue{
	private:
	min_stack<T> s1,s2;
	public:
	void transfer(){
		if(s2.empty()){
			while(!s1.empty()){
				s2.push(s1.top());
				s1.pop();
			}
		}
	}
	
	void push(const T& x){ s1.push(x); }
	void pop(){ transfer(); s2.pop(); }
	bool empty(){ return s1.empty() && s2.empty(); };
	T getmin(){ return min(s1.getmin(),s2.getmin()); }
	void front(){ transfer(); s2.top(); }
	
};


int main(){
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
	int n;
	cin >> n;
	
	min_queue<int> mq;
	
	char c;
	int el;
	
	for(int i=0;i<n;++i){
		cin >> c;
		if(c == '+'){
			cin >> el;
			mq.push(el);
		} else if(c == '-'){
			mq.pop();
		} else { // ?
			cout << mq.getmin() << "\n";
		}
		
	}

	
	
	return 0;
}
