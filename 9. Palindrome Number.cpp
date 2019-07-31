class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        } else if (x < 10) {
            return true;
        } else if (x < 100) {
            if (x % 11 != 0) {
                return false;
            } else {
                return true;
            }
        } else {
            string xString = to_string(x);
            int len = xString.length();
            int front = 0;
            int back = len - 1;
            if(len % 2 == 0) {
                while (front-1 != back) {
                    if (xString[front] != xString[back]) {
                        return false;
                    }
                    front++;
                    back--;
                }
            } else {
                while (front != back) {
                    if (xString[front] != xString[back]) {
                        return false;
                    }
                    front++;
                    back--;
                }
            }
        }
        return true;
    }
};
