class Solution {
public:
    string reorganizeString(string s) {
        int maxSize = s.length() / 2 + (s.length() % 2 == 1 ? 1 : 0);
        unordered_map<char, int> chars;
        for (char c : s){
            chars[c]++;
            if (chars[c] > maxSize) return "";
        }

        priority_queue<pair<int, char>> pq;
        for (auto &[x, y] : chars) pq.push({y, x});
        char prev = 1;
        string res = "";
        while (!pq.empty()) {
            char c = pq.top().second;
            int cnt = pq.top().first;
            pq.pop();
            if (c == prev) {
                char c2 = pq.top().second;
                int cnt2 = pq.top().first;
                pq.pop();
                pq.push({cnt, c});
                c = c2;
                cnt = cnt2;
            }
            res += c;
            if (cnt > 1) pq.push({cnt - 1, c});
            prev = c;

        }
        return res;
    }
};