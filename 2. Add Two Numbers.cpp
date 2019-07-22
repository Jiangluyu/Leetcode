/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL;
        ListNode *rcd = NULL;
        if((l1->val == 0 && l1->next == NULL) || (l2->val == 0 && l2->next == NULL)) {
            return (l1->val == 0)? l2 : l1;
        }

        int len1 = linklistLen(l1);
        int len2 = linklistLen(l2);
        int addBit = 0;
        if (len1 == len2) {
            head = l1;
            while(l1 != NULL) {
                l1->val = l1->val + l2->val + addBit;
                addBit = 0;
                if(l1->val >= 10) {
                    addBit = 1;
                    l1->val -= 10;
                }
                rcd = l1;
                l1 = l1->next;
                l2 = l2->next;
            }

            if (addBit == 1) {
                ListNode* temp = new ListNode(1);
                rcd->next = temp;
                return head;
            }
            return head;
        }

        if (len1 > len2) {
            head = l1;
            while(l2 != NULL) {
                l1->val = l1->val + l2->val + addBit;
                addBit = 0;
                if(l1->val >= 10) {
                    addBit = 1;
                    l1->val -= 10;
                }
                if(l1->next != NULL) {
                    l1 = l1->next;
                    l2 = l2->next;
                }else{
                    break;
                }
            }
            while (l1 != NULL) {
                if (l1->val == 0 && l1->next == NULL) {
                    ListNode* temp = new ListNode(1);
                    l1->next = temp;
                    return head;
                 }
                if(addBit == 0) {
                    break;
                }else{
                    l1->val += 1;
                    addBit = 0;
                    if(l1->val >= 10) {
                        l1->val -= 10;
                        addBit = 1;
                        if(l1->next != NULL) {
                            l1 = l1->next;
                        }
                    }
                }
            }
            return head;
        }else{
            head = l2;
            while(l1 != NULL) {
                l2->val = l1->val + l2->val + addBit;
                addBit = 0;
                if(l2->val >= 10) {
                    addBit = 1;
                    l2->val -= 10;
                }
                l1 = l1->next;
                l2 = l2->next;
            }
            while (l2 != NULL) {
                if (l2->val == 0 && l2->next == NULL) {
                    ListNode* temp = new ListNode(1);
                    l2->next = temp;
                    return head;
                 }
                if(addBit == 0) {
                    break;
                }else{
                    l2->val += 1;
                    addBit = 0;
                    if(l2->val >= 10) {
                        l2->val -= 10;
                        addBit = 1;
                        if(l2->next != NULL) {
                            l2 = l2->next;
                        }
                    }
                }

            }

            return head;
        }
    }

    int linklistLen(ListNode* l1) {
        int len = 0;
        while(l1->next != NULL) {
            l1 = l1->next;
            len++;
        }
        return len;
    }
};
