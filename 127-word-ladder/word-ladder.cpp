class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ind = -1;
        for (int i = 0; i < wordList.size(); ++i)  {
            if (wordList[i] == endWord) {
                ind = i;
                break;
            }
        }

        if (ind == -1) return 0;

        deque<int> frontier;
        for (int i = 0; i < wordList.size(); ++i) {
            int dif = 0;
            for (int j = 0; j < beginWord.length() && dif < 2; ++j) {
                if (beginWord[j] != wordList[i][j]) {
                    dif++;
                }
            }
            if (dif < 2) {
                if (i == ind) return 2;
                frontier.push_back(i);
            }
        }

        printf("ind: %d\n", ind);
        vector<vector<int>> adjL (wordList.size());
        for (int i = 0; i < wordList.size(); ++i) {
            for (int j = i + 1; j < wordList.size(); ++j) {
                int dif = 0;
                for (int k = 0; k < beginWord.length() && dif < 2; ++k) {
                    if (wordList[j][k] != wordList[i][k]) {
                        dif++;
                    }
                }
                if (dif < 2) {
                    printf("adding edge from %d to %d\n", i, j);
                    adjL[i].push_back(j);
                    adjL[j].push_back(i);
                }
            }
        }

        vector<bool> visited (wordList.size(), false);
        int step = 2;
        while (!frontier.empty()) {
            deque<int> next;
            while (!frontier.empty()) {
                int u = frontier.front(); frontier.pop_front();
                if (visited[u]) continue;
                visited[u] = true;
                for (int v : adjL[u]) {
                    if (!visited[v]) {

                        if (v == ind) {
                            printf("hit from u: %d, v: %d\n", u, v);
                            return step + 1;
                            
                        }
                        next.push_back(v);
                    }
                }
            }
            step++;
            frontier = next;
        }
        return 0;

    }
};