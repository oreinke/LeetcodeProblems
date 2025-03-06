class Solution {
public:
    int largestVariance(string s) {
        int n = s.length();
        int best = 0;
        for (int i = 0; i < n; ++i) {
            int big = 1, low = 1;
            int bigC = 1, lowC = 1;
            vector<int> freq (26, 0);
            freq[s[i] - 'a']++;
            for (int j = i + 1; j < n; ++j) {
                freq[s[j] - 'a']++;
                bool updateLow = false;
                if (freq[s[j] - 'a'] - 1 == low || freq[s[j] - 'a'] < low) {
                    updateLow = true; 
                    if (freq[s[j] - 'a'] < low) {
                        low = freq[s[j] - 'a'];
                        lowC = 1;
                        if (big - low > best) {
                            best = big - low;
                            // printf("updated best: %d, big: %d, low: %d, i: %d, j: %d\n", best, big, low, i, j);
                            
                        }

                    }
                } 
                while (j < n - 1 && s[j] == s[j + 1]) {
                    freq[s[j] - 'a']++;
                    ++j;
                }
                if (updateLow) {
                    lowC--;
                    if (lowC == 0) {
                        low = freq[s[j] - 'a'];
                        lowC = 0;
                        for (int num : freq) {
                            if (num == 0) continue;
                            if (num < low) {
                                low = num;
                                lowC = 1;
                            }
                            else if (num == low) {
                                lowC++;
                            }
                        }
                    }
                }

                if (freq[s[j] - 'a'] < low) {
                    low = freq[s[j] - 'a'];
                    lowC = 1;
                }

                if (freq[s[j] - 'a'] > big) {
                    big = freq[s[j] - 'a'];
                    bigC = 1;
                }
                else if (freq[s[j] - 'a'] == big) {
                    bigC++;
                }
                if (big - low > best) {
                    best = big - low;
                    // printf("updated best: %d, big: %d, low: %d, i: %d, j: %d\n", best, big, low, i, j);
                    
                }
            }
        }
        return best;
    }
};