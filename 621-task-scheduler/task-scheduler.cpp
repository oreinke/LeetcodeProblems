class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<int, int> cnt;
        for (char c : tasks) cnt[c - 'a']++;
        deque<tuple<int, int, int>> backlog;
        priority_queue<pair<int, int>> pq;
        for (auto[x, y] : cnt) {
            pq.push({y, x});
        }
        int time = 0;
        while (!pq.empty() || !backlog.empty()) {
            if (!pq.empty()) {
                auto [x, y] = pq.top(); pq.pop();
                if (x != 1) {
                    backlog.push_back({n + 1, x - 1, y});
                }
            }

            deque<tuple<int, int, int>> nextLog;
            for (auto [delay, count, task] : backlog) {
                if (delay == 1) {
                    pq.push({count, task});
                }
                else {
                    nextLog.push_back({delay - 1, count, task});
                }
            }
            backlog = nextLog;
            time++;
        }
        return time;
    }
};