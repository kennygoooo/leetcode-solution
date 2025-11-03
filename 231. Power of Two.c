// 231. Power of Two

// Bit

bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    return (n & -n) == n;
}