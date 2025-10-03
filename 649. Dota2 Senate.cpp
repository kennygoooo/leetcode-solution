// 649. Dota2 Senate

// Queue:
// push(x)
// pop()
// front()
// back()
// empty()
// size()

class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue <int> radient, dire;
        
        for(int i = 0; i < n; i++){
            if (senate[i] == 'R'){
                radient.push(i);
            } else {
                dire.push(i);
            }
        }
        
        while (!radient.empty() && ! dire.empty()) {
            int r = radient.front();
            radient.pop();
            int d = dire.front();
            dire.pop();

            if (r < d) {
                radient.push(n+r);
            } else {
                dire.push(n+r)
            }
        }
        return radient.empty() ? "Dire" : "Radiant";
    }
};