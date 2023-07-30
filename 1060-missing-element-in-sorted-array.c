int missingElement(int numbers[], int size, int k) {
    int start = 0;
    int end   = size - 1;

    while (start <= end) {
        int middle  = start + (end - start) / 2;
        int missing = numbers[middle] - numbers[0] - middle;
        if (missing < k)
            start = middle + 1;
        else
            end = middle - 1;
    }

    int missing = numbers[end] - numbers[0] - end;
    return numbers[end] + k - missing;
}
