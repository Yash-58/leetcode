/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        Node*dummy=new Node(0);
        Node*tempD=dummy;
        while(temp){
            tempD->next=new Node(temp->val);
            tempD=tempD->next;
            temp=temp->next;
        }
        Node*a=head;
        Node*b=dummy->next;
        unordered_map<Node*,Node*>mp;
        Node*tempa=a;
        Node*tempb=b;
        while(tempa){
            mp[tempa]=tempb;
            tempa=tempa->next;
            tempb=tempb->next;
        }
        for(auto x:mp){
            Node*f=x.first;
            Node*s=x.second;
            if(f->random!=NULL){
                Node*oRan=f->random;
                Node*dRan=mp[f->random];
                s->random=dRan;


            }
        }
        return b;
    }
};