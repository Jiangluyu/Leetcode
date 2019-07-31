class Solution {
public:
    int fib(int N) {
        int res = 0;
        if (N == 0 || N == 1) {
            return N;
        } else if (N == 2) {
            return 1;
        }

        res += 2*fib(N-2) + fib(N-3);
        return res;
    }
};
