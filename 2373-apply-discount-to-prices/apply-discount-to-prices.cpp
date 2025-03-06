class Solution {
public:



    string discountPrices(string sentence, int discount) {
        string result = "";
        int i = 0;
        
        while (i < sentence.length()) {
            if (sentence[i] == '$' ) {
                if (i == 0 && result.size() != 0 && result[result.size() - 1] != ' ') {
                    i++;
                    continue;
                } 
                if (i > 0 && sentence[i - 1] != ' ') {
                    i++;
                    continue;
                } 
                result += sentence.substr(0, i + 1);
                i++;
                string num = "";
                while (i < sentence.length() && sentence[i] - '0' >= 0 && sentence[i] - '0' < 10) {
                    num += sentence[i];
                    ++i;
                }
                if (num.size() != 0 && (i == sentence.length() || sentence[i] == ' ')) {
                    // cout << num << endl;
                    // cout << ((double) stoi(num) * discount) * .01 << endl;
                    result += format("{:.2f}", ((double) stoll(num) * (100 - discount)) * .01);
                }
                else {
                    result += num;
                }
                sentence = sentence.substr(i);
                i = 0;
            }
            else {
                i++;
            }
        }
        result += sentence;
        return result;
    }
};