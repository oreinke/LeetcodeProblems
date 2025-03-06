class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int, int>> bookings;
        for (vector<int> arr : intervals) {
            bookings.push_back({arr[0], arr[1]});
        }

        sort(bookings.begin(), bookings.end());
        
        int num = 0;
        while (!bookings.empty()) {
            num++;
            vector<pair<int, int>> next;
            int time = 0;
            for (int i = 0; i < bookings.size(); ++i) {
                if (bookings[i].first >= time ) {
                    time = bookings[i].second;
                }
                else {
                    next.push_back(bookings[i]);
                }
            }
            bookings = next;
        }
        return num;
    }
};