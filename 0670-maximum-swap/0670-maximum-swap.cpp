class Solution {
public:
    int maximumSwap(int num) {
        vector<int> digits;

        while (num) {
            digits.push_back(num % 10);
            num /= 10;
        }
        
        reverse(digits.begin(), digits.end());
        bool swapped = false;
        
        for (int i = 0; i < digits.size() && !swapped; i++) {
            int idx = i;
            for (int j = digits.size() - 1; j > i; j--) {
                if (digits[j] > digits[idx]) idx = j;
            }

            if (idx != i) {
                swap(digits[i], digits[idx]);
                swapped = true;
            }
        }

        int ans = 0;
        for (int d : digits) ans = ans * 10 + d;

        return ans;
    }
};