/*
    Intuition:
    - The skyline changes only at building start and end points.
    - To capture this, we process all these events in sorted order.
    - We maintain a multiset of active building heights to simulate
    the "skyline" at any given x-position.

    Key Idea:
    - When a building starts: add its height to the active set.
    - When a building ends: remove its height from the active set.
    - After each event, the tallest height in the active set is 
    what the skyline should be at that x-coordinate.

    How We Capture Changes:
    - Track the previous max height (`ongoingMax`).
    - Whenever the current max height differs from the previous one,
    a critical point in the skyline has occurred, so we record it.

    Why multiset:
    - To efficiently support duplicate heights and remove only one 
    instance when a building ends.
    - `*rbegin()` always gives the current max height in O(1).
*/

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        vector<pair<int, int>> points;

        for (auto& b : buildings) {
            points.push_back({b[0], -b[2]});
            points.push_back({b[1], b[2]});
        }

        sort(points.begin(), points.end());
        multiset<int> st = {0};

        int ongoingMax = 0;

        for (int i = 0; i < points.size(); i++) {
            int currPoint = points[i].first;
            int currPointHeight = points[i].second;

            if (currPointHeight < 0) {
                st.insert(-currPointHeight);
            } else {
                st.erase(st.find(currPointHeight));
            }

            auto it = *st.rbegin();

            if (it != ongoingMax) {
                ans.push_back({currPoint, it});
                ongoingMax = it;
            }
        }

        return ans;
    }
};