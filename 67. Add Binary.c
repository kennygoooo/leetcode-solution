// 67. Add Binary


char* addBinary(const char* a, const char* b) {
    int i = strlen(a) - 1;
    int j = strlen(b) - 1;

    int maxLen = (i>j ? i : j) + 3;

    char* res = (char*)malloc(maxLen*sizeof(char));
    if (!res) return NULL;
    
    int k = 0;
    int carry = 0;

    while( i >= 0 || j >= 0 || carry){
        int bitA = (i>=0) ? (a[i--] - '0') : 0;
        int bitB = (j>=0) ? (b[j--] - '0') : 0;

        int sum = bitA + bitB + carry;

        res[k++] = (sum % 2) + '0';

        carry = (sum / 2);
    }

    res[k] = '\0';

    for (int l=0, r = k-1; l<r; l++, r--){
        char temp = res[l];
        res[l] = res[r];
        res[r] = temp;
    }
    return res;
}