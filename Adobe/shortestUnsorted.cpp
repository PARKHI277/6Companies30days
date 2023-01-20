#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
         vector<int> sortNums;
        sortNums = nums;
        bool flag = true;
        int start=0, end=0;
        sort(sortNums.begin(), sortNums.end()); // 2 4 6 8 9 10 15
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] != sortNums[i]){
                if(flag)
                {
                    start = i; // 1
                    flag = false;
                }
                else{
                    end = i; // 2
                }
            }
        }
        if(start==end) return 0;
        return end-start + 1;
    }
};