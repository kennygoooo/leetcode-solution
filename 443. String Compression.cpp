int compress(vector<char>& chars) { 

int read_ptr = 0; // read pointer 

        int write_idx = 0;  // write pointer  

 

        for (read_ptr; read_ptr < chars.size(); ) {  // 用 i 作為每一段的起點 

            char current = chars[read_ptr]; 

            int j = read_ptr; 

            // 一直往右數到這段 current 的尾巴 

            while (j < chars.size() && chars[j] == current) { 

                j++; 

            } 

  

            // 1) 先寫字母 再write_idx += 1 

            chars[write_idx++] = current; 

  

            // 2) 這段的長度 

            int count = j – read_ptr; 

            // 若長度 > 1，寫入次數的每一位數字 

            if (count > 1) { 

                string cntStr = to_string(count); // 例如 12 → "12" 

                for (char c : cntStr) { 

                    chars[write_idx++] = c;          // 逐字寫回 

                } 

            } 

  

            // 3) 跳到下一段 

            read_ptr = j; 

        } 

  

        return write_idx; // 新的有效長度 

    } 