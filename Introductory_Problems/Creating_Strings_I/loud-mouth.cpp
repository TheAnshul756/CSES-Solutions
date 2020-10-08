#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
set<string> se;
string a;

void permute(int l, int r)  
{  
    // Base case  
    if (l == r)  
        se.insert(a); 
    else
    {  
        // Permutations made  
        for (int i = l; i <= r; i++)  
        {  
  
            // Swapping done  
            swap(a[l], a[i]);  
  
            // Recursion called  
            permute(l+1, r);  
  
            //backtrack  
            swap(a[l], a[i]);  
        }  
    }  
}  
 
signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//string s;
	cin>>a;
	permute(0, (int)a.size()-1);
	cout<<(int)se.size()<<"\n";
	for(string s : se)
		cout<<s<<"\n";
 
 
	return 0;	
}