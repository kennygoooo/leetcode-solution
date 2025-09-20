// 151. Reverse Words in a String 
string reverseWords(string s) { 

       istringstream iss(s);     // treat s as input stream 

        string word; 

        vector<string> words;     // store words 

         

        while (iss >> word) {     // automatically skips extra spaces 

            words.push_back(word); 

        } 

         

        reverse(words.begin(), words.end());  // reverse order 

         

        string result; 

        for (int i = 0; i < words.size(); i++) { 

            if (i > 0) result += ' '; 

            result += words[i]; 

        } 

        return result; 

    } 

// Method 2
string reverseWords(string s) { 

        int n = s.size(); 

        int i = 0, j = 0; 

 

        while (i < n) { 

            // skip extra spaces 

            while (i < n && s[i] == ' ') i++; 

            if (i >= n) break; 

            // copy word 

            if (j > 0) s[j++] = ' '; // insert single space before next word 

            while (i < n && s[i] != ' ') { 

                s[j++] = s[i++]; 

            } 

        } 

        s.resize(j); // shrink to new size (trimmed string) 

  

        // 2. Reverse the whole string 

        reverse(s.begin(), s.end()); 

  

        i// 3. Reverse each word 

        int start = 0; 

        for (int k = 0; k <= s.size(); k++) { 

            if (k == s.size() || s[k] == ' ') { 

                reverse(s.begin() + start, s.begin() + k); 

                start = k + 1; 

            } 

        } 

        return s; 

    } 