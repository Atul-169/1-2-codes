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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* cur1=list1;
        ListNode* cur2=list2;
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(cur1 && cur2){
            if(cur1->val < cur2->val){
                temp->next=cur1;
                temp=cur1;
                cur1=cur1->next;
            }
            else{
                temp->next=cur2;
                temp=cur2;
                cur2=cur2->next;
            }

        }
        if(cur1) temp->next=cur1;
        if(cur2) temp->next=cur2;
        return dummy->next;



        
    }
};
