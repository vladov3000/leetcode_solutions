int helper(
    int cookies[], 
    int size, 
    int children[],
    int k
) {
    if (size == 0) {
        int unfairness = INT_MIN;
        for (int i = 0; i < k; i++)
            if (children[i] > unfairness)
                unfairness = children[i];
        return unfairness;
    }

    int unfairness = INT_MAX;
    for (int i = 0; i < k; i++) {
        children[i] += cookies[0];
        int result = helper(&cookies[1], size - 1, children, k);
        if (result < unfairness)
            unfairness = result;
        children[i] -= cookies[0];
    }

    return unfairness;
}

int distributeCookies(int cookies[], int size, int k) {
    int* children = calloc(k, sizeof(int));
    int result = helper(cookies, size, children, k);
    free(children);
    return result;
}
