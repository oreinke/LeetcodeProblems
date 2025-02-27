class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        map<string, vector<pair<int, int>>> users;
        map<string, int> stringToI; 
        map<int, string> iToString;
        for (string web : website) {
            if (!stringToI.count(web)) {
                iToString[stringToI.size()] = web;
                stringToI[web] = stringToI.size();
            }
        }

        int n = username.size();
        for (int i = 0; i < n; ++i) {
            users[username[i]].push_back({timestamp[i], stringToI[website[i]]});
        }

        int freq = 0;
        map<tuple<int,int,int>, int> cnt;
        for (auto &[y, x] : users) {
            if (x.size() < 3) continue;
            sort(x.begin(), x.end());
            set<tuple<int, int, int>> found;
            for (int i = 0; i < x.size() - 2; ++i) {
                for (int j = i + 1; j < x.size() - 1; ++j) {
                    for (int k = j + 1; k < x.size(); ++k) {
                        found.insert(make_tuple(x[i].second, x[j].second, x[k].second));
                    }
                }
            }

            for (auto pattern : found) {
                cnt[pattern]++;
            }
        }
        int best = 0;
        string bestStr;
        tuple<int, int, int> bestI;
        for (auto &[x, y] : cnt) {
            if (y > best) {
                best = y;
                bestStr = iToString[get<0>(x)] + "$" + iToString[get<1>(x)] + "$" + iToString[get<2>(x)];
                bestI = x;
            }
            else if (y == best) {
                string offer = iToString[get<0>(x)] + "$" + iToString[get<1>(x)] + "$" + iToString[get<2>(x)];
                if (offer < bestStr) {
                    bestStr = offer;
                    bestI = x;
                }
            }
        }    
        
        return {iToString[get<0>(bestI)], iToString[get<1>(bestI)], iToString[get<2>(bestI)]};
    }
};