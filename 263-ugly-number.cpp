class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0)
            return false;

        static const int factors[] = { 2, 3, 5 }; 
        for (int i : factors)
            while (n > 1)
                if (n % i == 0)
                    n /= i;
                else
                    break;
        return n == 1 || n == 0;
    }
};
