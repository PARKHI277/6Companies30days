#include<iostream>
#include<bits/stdc++.h>
using namespace std;


  struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:

    void inorder(TreeNode *rt , vector<int> &ans )
    {
        if(rt == nullptr )return;

        inorder(rt->left , ans );
        ans.push_back(rt->val);
        inorder(rt->right,ans);

    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> l1,l2;
        inorder(root1,l1);
        inorder(root2,l2);
        int p1 = 0 , p2 = 0 ;
        vector<int> ans;
        while( p1 < l1.size() && p2 < l2.size())
        {
            if( l1[p1] < l2[p2])
            {
                ans.push_back(l1[p1]);
                ++p1;
            }
            else 
            {
                ans.push_back(l2[p2]);
                ++p2;
            }
        }
        while(p1 < l1.size())
        {
            ans.push_back(l1[p1]);
            ++p1;
        }
        while(p2 < l2.size())
        {
            ans.push_back(l2[p2]);
            ++p2;
        }
        return ans; 
    }
};


 
  