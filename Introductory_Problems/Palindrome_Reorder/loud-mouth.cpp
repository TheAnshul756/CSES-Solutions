#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
 
signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	cin>>s;
	int cnt[26]={}; //to store count of all letters
	int n=(int)s.length();
	for(auto ch : s)
	{
		cnt[ch-'A']++;
	}

	string ans="";
	//we can have atmost 1 leter with odd frequency
	bool x=false; //check whether we found that odd frequency letter
	char ch='.';
	for(int i=0; i<26; i++)
	{
		if(cnt[i]%2)
		{
			if(!x)
			{
				x=true;
				ch=(char)('A'+i); //store that odd character
				for(int j=0; j<cnt[i]/2; ++j)
				ans+=(char)('A'+i);
			}
			else
			{
				// >1 letter with odd frequency
				cout<<"NO SOLUTION";
				return 0;
			}
			
		}
		else
		{
			for(int j=0; j<cnt[i]/2; ++j)
				ans+=(char)('A'+i);
		}
	}
	cout<<ans; //left half
	if(x)
		cout<<ch; //middle odd element
	reverse(ans.begin(), ans.end()); 
	cout<<ans; //right half
 
	return 0;	
}