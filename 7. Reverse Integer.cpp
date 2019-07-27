class Solution {
public:
    int reverse(int x) {
        int push = 0;
        int pop = x;
        while (pop != 0) {
            if (push > 2147483648/10 || push < -2147483648/10) {
                return 0;
            } else {
                push = (pop % 10) + (push * 10);
                pop /= 10;
            }
        }
        return push;
    }
};
