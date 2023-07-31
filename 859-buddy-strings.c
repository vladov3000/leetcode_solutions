bool buddyStrings(char* s, char* goal) {
    char swapped[2] = {};
    bool seen[256]  = {};
    bool seen_twice = false;
    bool equal      = true;
    bool swap_used  = false;

    while (*s && *goal) {
        if (*s != *goal) {
            equal = false;

            if (swapped[0] == '\0') {
                swapped[0] = *s;
                swapped[1] = *goal;
            } else if (swapped[0] != *goal || swapped[1] != *s) {
                return false;
            } else {
                swap_used = true;
                s++;
                goal++;
                break;
            }
        }

        if (seen[*s])
            seen_twice = true;
        seen[*s] = true;

        s++;
        goal++;
    }

    if (swap_used || (equal && seen_twice))
        return strcmp(s, goal) == 0;
    else
        return false;
}
