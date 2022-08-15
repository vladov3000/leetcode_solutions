int reverse(int x) {
    int y = 0;
    bool negative = false;
    
    if (x < 0) {
        negative = true;
        if (x == INT_MIN)
            return 0;
        x = -x;
    }
    
    while (x > 0) {
        int digit = x % 10;
        if (y > (INT_MAX - digit) / 10)
            return 0;
        
        y = (y * 10) + digit;
        x /= 10;
    }
    
    return negative ? -y : y;
}
