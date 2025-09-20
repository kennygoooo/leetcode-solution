// 1456. Maximum Number of Vowels in a Substring of Given Length
// Sliding window

bool isVowel (char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return true;
        return false;
    }
    int maxVowels(string s, int k) {
        // unordered_set<char> vowels = {'a','e','i','o','u'};
        int n = s.size();
        int ans = 0;
        int cnt = 0;
        
        for(int i=0; i<k; i++){
            if(isVowel(s[i])){
                cnt++;
            }
        }

        ans = max(ans, cnt);
        
        if(ans==k) return ans;

        for(int i=k; i<n; i++){
            // if (vowels.count(s[i])) cnt++;
            // if (vowels.count(s[i - k])) cnt--;
            if(isVowel(s[i])) cnt++;
            if(isVowel(s[i-k])) cnt--;
            
            ans=max(ans, cnt);
        }
        return ans;
    }

    // unordered_set:

    // unordered_set<int> s = {1, 2, 1, 3, 3, 3, 4, 5}
    // s will be {1 ,2 ,3, 4, 5} but without orde so {2, 3, 4, 1, 5} also correct

    // count:

    //check s have 3?
    // if (s.count(3)) { 

    //  } 