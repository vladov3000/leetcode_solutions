int myAtoi(char* s) {
    while (*s == ' ')
        s++;
    
    bool negative = *s == '-';
    if (negative || *s == '+')
        s++;

    int x = 0;
    
    while ('0' <= *s && *s <= '9') {
        int digit = *s - '0';
        if (x < (INT_MIN + digit + 1 - negative) / 10)
            return negative ? INT_MIN : INT_MAX;
        x = (x * 10) - digit;
        s++;
    }
    
    return negative ? x : -x;
}
