class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree (numCourses, 0);
        vector<vector<int>> adjL (numCourses);
        for (vector<int> edge : prerequisites) {
            inDegree[edge[0]]++;
            adjL[edge[1]].push_back(edge[0]);
        }

        deque<int> degreeZero;
        vector<int> result;
        vector<bool> visited (numCourses, false);
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                degreeZero.push_back(i);
                visited[i] = true;
                result.push_back(i);
            }
        }

        while (!degreeZero.empty() && result.size() < numCourses) {
            deque<int> next;
            while (!degreeZero.empty()) {
                int u = degreeZero.front(); degreeZero.pop_front();
                for (int v : adjL[u]) {
                    if (visited[v]) continue;
                    inDegree[v]--;
                    if (inDegree[v] == 0) {
                        next.push_back(v);
                        result.push_back(v);
                        visited[v] = true;
                    }
                }
            }
            degreeZero = next;
        }
        
        if (result.size() == numCourses) {
            return result;
        }
        vector<int> dummy;
        return dummy;
    }
};