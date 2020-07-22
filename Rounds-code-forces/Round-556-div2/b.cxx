#include<bits/stdc++.h>

using namespace std;
int n;
bool valid(int x,int y){
	return (x>=0 && x<n)&&(y>=0&&y<n);
}

int main(){
	
	cin >> n;
	
	vector< vector< int > > board(n,vector<int>(n,0));
	
	
	for(int i=0;i<n;++i){
		string s;
		cin >> s;
		for(int j=0;j<n;j++){
			if(s[j]=='.')
				board[i][j]=1;
		}
	}
	int arrx[] = {0, 0, 1, -1};
	int arry[] = {1, -1, 0, 0};
	
	
	for(int i=0;i<n;++i){
		for(int j=0;j<n;j++){
			if(board[i][j]==1){
				bool put_board=true;
				for(int k=0;k<4;k++){
					int new_i = i+arrx[k];
					int new_j = j+arry[k]; 
					if(valid(new_i,new_j) && board[new_i][new_j] == 1){
						continue;
					} else {
						put_board=false;
						break;
					}
				}
				if(put_board){
					board[i][j]=0;
					
					for(int k=0;k<4;k++){
						
						int new_i = i+arrx[k];
						int new_j = j+arry[k];
						board[new_i][new_j] = 0;
					}
				}
			}
		}
	}
	
	bool valid = true;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;j++){
			if(board[i][j] == 1){
				valid = false;
				break;
			}
		}
	}
	
	if(valid)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
