// 1768. Merge Strings Alternately 

string mergeAlternately(string word1, string word2) { 

      std::string merged; 

      int maxLength = std::max(word1.length(), word2.length()); 

  

      for (int i = 0; i < maxLength; i++) { 

        if (i < word1.length()) { 

            merged += word1[i]; 

        } 

        if (i < word2.length()) { 

            merged += word2[i]; 

        } 

      }  

      return merged;   

    } 


// Method 2
string mergeAlternately(string word1, string word2) { 

      std::string merged; 

      merged.reserve(word1.size() + word2.size()); 

 

      int i = 0,  j = 0;   

  

      while( i < word1.size() || j < word2.size()){ 

        if(i < word1.size()){ 

            merged += word1[i++]; 

        } 

        if (j < word2.size()){ 

            merged += word2[j++]; 

        } 

      } 

      return merged; 

    } 


 
// Pre-allocate memory:
// string merged; 
//  merged.reserve(word1.size() + word2.size()); 
 