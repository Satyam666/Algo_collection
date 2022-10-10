#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool CyclicUtil(int curr, int parent, vector<bool> &visited, vector<int> adj[])
    {
        visited[curr] = true;

        for (auto x : adj[curr])
        {
            if (!visited[x])
            {
                bool flag = CyclicUtil(x, curr, visited, adj);
                if (flag == true)
                    return true;
            }
            else if (x != parent)
                return true;
        }

        return false;
    }

    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                bool flag = CyclicUtil(i, -1, visited, adj);
                if (flag == true)
                    return true;
            }
        }
        return false;
    }
};