/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* a=head;
        ListNode* b=head->next;
        ListNode* even=b;

        while(b!=NULL && b->next!=NULL){
            a->next=b->next;
            a=a->next;

            b->next=a->next;
            b=b->next;
        }
        a->next=even;
        return head;
    }
};