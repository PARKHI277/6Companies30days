#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

 void helper(int idx,int sum,int n,vector<vector<int>>&result,vector<int>&ans,int k)
 {
     if(sum == n && k == 0)
     {
         result.push_back(ans);
         return;
     }
     if(sum > n)
     {
         return;
     }

     for(int i = idx ;i <=9;i++)
     {
         if(i>n)
         {
             break;
         }

         ans.push_back(i);
         helper(i+1,sum+i,n,result,ans,k-1);
         ans.pop_back();
     }
 }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>ans;
        vector<vector<int>>result;
        helper(1,0,n,result,ans,k);
        return result;
    }
};