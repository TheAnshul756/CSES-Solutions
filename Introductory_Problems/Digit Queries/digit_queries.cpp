#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

	vector<ll> power_of_ten(19,1);
	for(int i=1; i<19; i++){
		power_of_ten[i]=power_of_ten[i-1]*10;
	}

	int q;
	cin>>q;
	int i=1;

	while(i<=q){
		long long int k;
		cin>>k;
		long long int sum=0, j=0, last_sum=0;
		while(sum<=k){
			last_sum = sum;
			j++;
			sum+=j*9*power_of_ten[j-1];
		}
		k-=last_sum;
		long long int nums = k/j - 1;
		long long int final_num = power_of_ten[j-1]+nums;
		long long int digits = k%j;
		string joined = to_string(final_num)[to_string(final_num).length()-1] + to_string(1+final_num);
		cout<<joined[digits]<<endl;
		i++;
	}

	return 0;
}
