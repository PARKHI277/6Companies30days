#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int>adj[n];
        for(auto it : prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }

        // next topological sort
        int degree[n] = {0};

        for (int i = 0; i < n; i++) 
        {
			for (auto it : adj[i]) 
            {
				degree[it]++;
			}
		}

        queue<int> q;
		for (int i = 0; i < n; i++)
         {
			if (degree[i] == 0) 
            {
				q.push(i);
			}
		}

        vector<int> topo;
		while (!q.empty()) 
        {
			int node = q.front();
			q.pop();
			topo.push_back(node);
			for (auto it : adj[node]) 
        {
				degree[it]--;
				if (degree[it] == 0) 
                q.push(it);
			}
		}

		if (topo.size() == n) return true;
		return false;
    }
};