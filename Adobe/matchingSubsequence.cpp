#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool isSubsequence(string s, string word) 
{
 
    if(s.length() < word.length()) 
        return false;
    int sIndex = 0, wIndex = 0; 
    
    while(sIndex < s.length() && wIndex < word.length()) 
    {
    
        if(s[sIndex] == word[wIndex]) 
        {
            sIndex++;
            wIndex++;
        } 
        else
        {
            sIndex++;
        }
    }
    
    
    return (wIndex == word.length());
}

int numMatchingSubseq(string s, vector<string>& words) 
{
    int matchCount = 0;
    unordered_map<string, int> cache; 
    
    
    for(auto &word : words)
     {
       
        if(cache.count(word))
         {
            matchCount += cache[word];
        }
         else
         {
            matchCount += cache[word] = isSubsequence(s, word);
        }
    }
    return matchCount;
    }
};