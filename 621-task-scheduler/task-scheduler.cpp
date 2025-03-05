class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int, int> cnt;
        for (char c : tasks)  cnt[c - 'a']++;
        int maxCnt = 0;
        for (auto [x, y] : cnt) maxCnt = max(maxCnt, y);
        int time = (maxCnt - 1) * (n + 1);
        for (auto [x, y] : cnt) if (y == maxCnt) time++;
        if (time < tasks.size()) return tasks.size();
        
        return time;
    }
};