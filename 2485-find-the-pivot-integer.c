int pivotInteger(int n) {
    int a = n * (n + 1);
    if (a & 1) {
        return -1;
    }

    double b = sqrt(a / 2);
    return b == floor(b) ? b : -1;
}
