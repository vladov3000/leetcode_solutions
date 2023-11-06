class Solution {
public:
    int integerBreak(int n) {
        vector<int> memory(n + 1);
        memory[2] = 1;

        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                memory[i] = max(memory[i], j * (i - j));
                memory[i] = max(memory[i], memory[j] * (i - j));
                memory[i] = max(memory[i], j * memory[i - j]);
                memory[i] = max(memory[i], memory[j] * memory[i - j]);
            }
        }

        return memory.back();
    }
};
