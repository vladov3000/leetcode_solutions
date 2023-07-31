int singleNumber(int* nums, int size) {
    int one = 0;
    int two = 0;

    for (int i = 0; i < size; i++) {
        one = (nums[i] ^ one) & ~two;
        two = (nums[i] ^ two) & ~one;
    }

    return one;
}
