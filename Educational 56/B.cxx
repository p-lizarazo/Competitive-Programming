#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string str) 
{  
    int l = 0; 
    int h = str.length() - 1; 
    // Keep comparing characters while they are same 
    while (h > l) 
    { 
        if (str[l++] != str[h--]) 
        { 
            return false; 
        } 
    }
    return true; 
} 

bool ans = false;
/*
string permute(string str, string out)
{
    // When size of str becomes 0, out has a 
    // permutation (length of out is n) 
    if (str.size() == 0)
    {
		if(!isPalindrome(out)){
			return out;
		} else {
			return "";
		}
    }
  
    // One be one move all characters at 
    // the beginning of out (or result) 
    for (int i = 0; i < (int) str.size(); i++) 
    {
        // Remove first character from str and 
        // add it to out 
        string s = permute(str.substr(1), out + str[0]); 
		if(s!=""){
			return s;
		}
        // Rotate string in a way second character 
        // moves to the beginning. 
        rotate(str.begin(), str.begin() + 1, str.end()); 
    }
    return "";
}
*/

int main(){
	
	int t;
	cin >> t;
	string a;
	for(int i=0;i<t;i++){
		cin >> a;
		if(!isPalindrome(a)){
			cout << a <<"\n";
			continue;
		} else {
			bool ans=false;
			for(int k=1;k<(int)a.length();k++){
				if (a[k]!=a[0]){
					char temp = a[0];
					a[0] = a[k];
					a[k] = temp;
					ans = true;
					cout << a << "\n";
					break;
				}
			}
			if(ans)
				continue;
			cout << "-1" << "\n";
		}
		/*
		string ss = permute(a,"");
		if(ss == ""){
			cout << "-1" << "\n";
		} else{
			cout << ss << "\n";
		}*/
		
	}
	

	return 0;
}
