#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bull,cow = 0;
        int n = secret.size();
        vector<int>s(10),g(10);
        for(int i = 0;i<n;i++)
        {
            if(secret[i] == guess[i])
            {
                bull++;
            }
            else
            {
                s[secret[i]-'0']++;
                g[guess[i]-'0']++;
            }
        }
        for(int i = 0;i<n;i++)
        {
            cow += min(s[i],g[i]);
        }
        string ans = "";
        ans += to_string(bull);
        ans += "A";
        ans += to_string(cow);
        ans += "B";
        return ans;
    }
};