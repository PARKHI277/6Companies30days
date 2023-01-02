#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
        {
            return 0;
        }
        int sum = 0;
        int f = 0;
        for(int i = 0;i<n;i++)
        {
            sum += nums[i];
            f += i*nums[i];  // 0*4 + 1*3 + 2*2 + 3*6
        }
        int maxi = INT_MIN;
        vector<int>prev(n);
        prev[0] = f;
        maxi = prev[0];
        for(int i =1;i<n;i++)
        {
            prev[i] = prev[i-1] + sum - (n *nums[n-i]);
            maxi = max(maxi,prev[i]);
        }


        return maxi;


    }
};
