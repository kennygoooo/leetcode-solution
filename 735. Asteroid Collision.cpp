// 735. Asteroid Collision
// Stack

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        
        for (int i = 0; i < asteroids.size(); i++) {
            int a = asteroids[i];
            bool alive = true;

            while (alive && a < 0 && !st.empty() && st.back() > 0){
                if (st.back() == -a) {
                    st.pop_back();
                    alive = false;
                } else if (st.back() < -a){
                     st.pop_back();
                } else {
                    alive = false;
                }
            }


            if(alive) st.push_back(a);
        }
        return st;
    }
};