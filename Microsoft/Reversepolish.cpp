#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens)
     {
        stack<int> st;
       for (int i = 0; i < tokens.size(); i++)
     {
        if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "/"
            && tokens[i] != "*") 
        {
            st.push(stoi(tokens[i]));
            
        }
        else
        {
            long long int b = st.top();
            st.pop();
            long long int a = st.top();
            st.pop();
            if (tokens[i] == "+")
                st.push(a + b);
            else if (tokens[i] == "-")
                st.push(a - b);
            else if (tokens[i] == "*")
                st.push(a * b);
            else
                st.push(a / b);
        }
    }
    return st.top();
    
    }
};