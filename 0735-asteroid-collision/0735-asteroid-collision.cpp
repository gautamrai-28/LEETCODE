class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for (int asteroid : asteroids) {
            if (asteroid > 0) {
                st.push_back(asteroid);
                continue;
            }
            while (!st.empty() && st.back() > 0 && st.back() < -asteroid) {
                st.pop_back();
            }

            if (!st.empty() && st.back() == -asteroid) {
                st.pop_back();                  
            }
            else if (st.empty() || st.back() < 0) {
                st.push_back(asteroid);        
            }
        }

        // vector<int> ans(st.size());

        // for (int i = st.size() - 1; i >= 0; i--) {
        //     ans[i] = st.top();
        //     st.pop();
        // }

        return st;
    }
};