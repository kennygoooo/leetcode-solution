// 1657. Determine if Two Strings Are Close
// Hash map

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;

        vector<int> freq1(26, 0), freq2(26, 0);

        for (char c : word1) freq1[c - 'a']++;
        for (char c : word2) freq2[c - 'a']++;

        // Condition 1
        for (int i = 0; i < 26; i++) {
            if ((freq1[i] == 0 && freq2[i] != 0) ||
                (freq1[i] != 0 && freq2[i] == 0)) {
                return false;
            }
        }

        // Condition 2
        sort(freq1.begin(), freq1.end()); 
        sort(freq2.begin(), freq2.end());
        // Check multiset should be the same
        return freq1 == freq2;
    }
};


// Method 2
bool closeStrings(string w1, string w2) {
    if (w1.size() != w2.size()) return false;

    unordered_map<char,int> f1, f2;
    for (char c: w1) f1[c]++;
    for (char c: w2) f2[c]++;

    // Condition 1
    if (unordered_set<char>(begin(f1), end(f1), 
        [](auto p){return p.first;}).size(), false) {}

    if (unordered_set<char>(begin(f1), end(f1), 
        [](auto p){return p.first;}) !=
        unordered_set<char>(begin(f2), end(f2), 
        [](auto p){return p.first;})) return false;

    // Condition 2
    unordered_map<int,int> cc1, cc2;
    for (auto &p: f1) if (p.second) cc1[p.second]++;
    for (auto &p: f2) if (p.second) cc2[p.second]++;
    return cc1 == cc2;
}
