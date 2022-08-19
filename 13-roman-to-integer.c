char* subtract_case(char* s, char five, char ten, int scale, int* result) {
    if (s[1] == five) { *result += 4 * scale; s++; }
    else if (s[1] == ten)  { *result += 9 * scale; s++; }
    else *result += scale;
    
    return s;
}

int romanToInt(char* s){
    int result = 0;
    
    while (*s != '\0') {
        
        switch (s[0]) {
        
            case 'I':
                s = subtract_case(s, 'V', 'X', 1, &result);
                break;

            case 'V':
                result += 5;
                break;
                
            case 'X':
                s = subtract_case(s, 'L', 'C', 10, &result);
                break;
            
            case 'L':
                result += 50;
                break;
                
            case 'C':
                s = subtract_case(s, 'D', 'M', 100, &result);
                break;
                
            case 'D':
                result += 500;
                break;
                
            case 'M':
                result += 1000;
                break;
        }
        
        s++;
    }
    
    return result;
}
