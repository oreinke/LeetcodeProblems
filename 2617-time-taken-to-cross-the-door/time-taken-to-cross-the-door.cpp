class Solution {
public:
    vector<int> timeTaken(vector<int>& arrival, vector<int>& state) {
        int n = arrival.size();
        queue<int> enter, exit;
        vector<int> answer (n);
        int time = arrival[0];
        bool e = true;
        int i = 0;
        while (i < n) {
            if (arrival[i] > time) {
                e = true;
                time = arrival[i];
            }

            while (i < n && arrival[i] <= time) {
                if (1 == state[i]) {
                    exit.push(i);
                }
                else {
                    enter.push(i);
                }

                ++i;
            }

            while (!exit.empty() || !enter.empty()) {
                
                while (i < n && arrival[i] <= time) {
                    
                    if (1 == state[i]) {
                        exit.push(i);
                    }
                    else {
                        enter.push(i);
                    }

                    ++i;
                }

                if (exit.empty() || enter.empty()) {
                    
                    if (exit.empty()) {
                        int ind = enter.front(); enter.pop();
                        answer[ind] = time;
                        ++time;
                        e = false;
                    }
                    else {
                        int ind = exit.front(); exit.pop();
                        answer[ind] = time;
                        ++time;
                        e = true;
                    }
                }
                else if (e) {
                    int ind = exit.front(); exit.pop();
                    answer[ind] = time;
                    ++time;
    
                }
                else {
                    int ind = enter.front(); enter.pop();
                    answer[ind] = time;
                    ++time;
                }
            }
        }
        return answer;
    }
};