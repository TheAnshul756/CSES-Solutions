#include <bits/stdc++.h>

using namespace std;
class LongestIncreasingSubsequence {
public:
    
    int binSearch(int dp[],int start,int end, int val )
    {
        int lo = start,hi = end;
        int mid;
        while(lo<hi)
        {
            mid = lo + (hi-lo)/2;
            if(dp[mid]>val)
            {
                hi = mid;
            }
            else if(dp[mid]<val)
            {
                lo = mid+1;
            }
            else return mid;
            
        }
        return hi;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        if(!n) return 0;
        int dp[n];
        // memset(dp,-1,sizeof(dp));
        int mx = 1;
        dp[0] = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            int x = nums[i];
            int pos = lower_bound(dp,dp+mx,x)-dp;
            dp[pos] = x;
            mx = max(mx,pos+1);
           
        }
        
        
        return mx;
        
        
        
    }
    int main()
    {
        int n;
        cin >> n;
        int tmp;
        vector <int> nums;
        for(int i=0;i<n;i++)
        {
            cin >> tmp; nums.push_back(tmp);
        }
        cout << lengthofLIS(nums) << endl;
    }
};
