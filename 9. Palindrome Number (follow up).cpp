class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        else if (x == 0)
            return true;
        long int temp = 0;
        long int renum = 0;
        long int num = x;
        while (x > 0)
        {
            temp = x % 10;
            x /= 10;
            renum = (renum * 10) + temp;
        }
        if (num == renum)
            return true;
        else
            return false;
    }
};
