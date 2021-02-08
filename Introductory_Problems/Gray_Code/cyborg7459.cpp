#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<string> gc = {"0", "1"};
    int n;
    cin >> n;
    if(n==1) {
        for(int i=0; i<gc.size(); i++)
        	cout << gc[i] << "\n";
    }
    else {
        n--;
        while(n--) {
            vector<string> v1 = gc, v2 = gc;
            vector<string> temp;
            reverse(v2.begin(), v2.end());
            int t = v1.size();
            for(int i=0; i<t; i++) {
                v1[i] = "0" + v1[i];
                temp.push_back(v1[i]);
            }
            for(int i=0;i<t; i++) {
                v2[i] = "1" + v2[i];
                temp.push_back(v2[i]);
            }
            gc = temp;
        }
        for(int i=0; i<gc.size(); i++)
        	cout << gc[i] << "\n";
    }
}

