int numTrees(int n) {
    int* solutions = calloc(n + 1, sizeof(int));
    solutions[0]   = 1;
    solutions[1]   = 1;

    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
            solutions[i] += solutions[j - 1] * solutions[i - j];

    return solutions[n];
}

/* Naive O((2n) ^ n)
int numTrees(int n) {
    if (n < 2)
        return 1;

    int result = 0;
    for (int i = 1; i <= n; i++)
        result += numTrees(i - 1) * numTrees(n - i);
    return result;
}
*/
