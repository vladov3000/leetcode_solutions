int numTrees(int n) {
    int* solutions = calloc(n + 1, sizeof(int));
    solutions[0]   = 1;
    solutions[1]   = 1;

    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
            solutions[i] += solutions[j - 1] * solutions[i - j];

    return solutions[n];
}
