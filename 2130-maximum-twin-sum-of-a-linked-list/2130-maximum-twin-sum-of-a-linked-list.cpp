class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr) {
            ListNode* Next = curr->next;

            curr->next = prev;
            prev = curr;
            curr = Next;
        }

        return prev;
    }

    int pairSum(ListNode* head) {

        if(head == NULL) return 0;

        ListNode* temp = head;
        int len = 0;

        while(temp) {
            len++;
            temp = temp->next;
        }

        int revlen = len / 2;
        temp = head;

        while(revlen > 0) {
            temp = temp->next;
            revlen--;
        }

        ListNode* temp1 = reverseList(temp);

        int sum = 0;
        int Max = INT_MIN;

        while(temp1) {
            sum = head->val + temp1->val;
            Max = max(Max, sum);

            head = head->next;
            temp1 = temp1->next;
        }

        return Max;
    }
};