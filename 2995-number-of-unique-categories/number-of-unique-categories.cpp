/**
 * Definition for a category handler.
 * class CategoryHandler {
 * public:
 *     CategoryHandler(vector<int> categories);
 *     bool haveSameCategory(int a, int b);
 * };
 */
class Solution {
public:
    int numberOfCategories(int n, CategoryHandler* categoryHandler) {
        set<int> cats;
        for (int i = 0; i < n; ++i) {
            bool valid = true;
            for (int cat : cats) {
                if (categoryHandler->haveSameCategory(cat, i)) {
                    valid = false;
                    break;
                }
            }
            if (valid) cats.insert(i);
        }

        return cats.size();
    }
};