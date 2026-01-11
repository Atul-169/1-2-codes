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
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        int total=0;
        while(temp!=nullptr){
            total++;
            temp=temp->next;
        }
        temp=head;

        for(int i=0;i<total/2;i++){
            temp=temp->next;
        }
        ListNode* prev=nullptr;
        ListNode* cur=temp;
        while(cur!=nullptr){
            ListNode* swap=cur->next;
            cur->next=prev;
            prev=cur;
            cur=swap;
        }
        ListNode* tail=prev;
        ListNode* left=head;
        ListNode* right=tail;
        int cnt=0;
        while(cnt<total/2){
            if(left->val!=right->val) return false;
            cnt++;
            left=left->next;
            right=right->next;
        }
        return true;

    }
};
