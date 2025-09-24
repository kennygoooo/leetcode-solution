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
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;

        unordered_map<char,int> freq1, freq2;

        for (char c : word1) freq1[c]++;
        for (char c : word2) freq2[c]++;

        // Step 1: check if character sets are the same
        unordered_set<char> set1, set2;
        for (auto &p : freq1) set1.insert(p.first);
        for (auto &p : freq2) set2.insert(p.first);
        if (set1 != set2) return false;

        // Step 2: check if frequency multisets are the same
        vector<int> values1, values2;
        for (auto &p : freq1) values1.push_back(p.second);
        for (auto &p : freq2) values2.push_back(p.second);

        sort(values1.begin(), values1.end());
        sort(values2.begin(), values2.end());

        return values1 == values2;
    }
};
