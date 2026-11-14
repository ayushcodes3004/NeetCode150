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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length=0;
        ListNode* temp=head;
        while(temp){
            length++;
            temp=temp->next;
        }
        if(length==n){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        temp=head;
        ListNode* prev=NULL;
        int find=length-n;
        for(int i=0;i<find-1;i++){
            temp=temp->next;
        }
        prev=temp->next;
        temp->next=prev->next;
        delete prev;
        return head;
    }
};
