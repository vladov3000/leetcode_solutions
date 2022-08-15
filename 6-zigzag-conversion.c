char* convert(char* s, int rows) {
    if (rows == 1)
        return s;
    
    int   len    = strlen(s);
    char* result = malloc(len + 1);
    char* out    = result;
    int   offset = rows + rows - 2;
    
    for (int i = 0; i < rows; i++)
        for (int j = i; j < len; j += offset) {
            *(out++) = s[j];
            if (i > 0 && i < rows - 1 && j + offset - 2 * i < len)
                *(out++) = s[j + offset - 2 * i];
        }
    
    result[len] = '\0';
    return result;
}
