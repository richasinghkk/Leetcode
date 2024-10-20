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
        // ListNode*p1=list1;
        // ListNode*p2=list2;
        // ListNode*dummy=new ListNode(-1);
        // ListNode*p3=dummy;
        // while(p1!=NULL && p2!=NULL){
        //     if(p1->val<= p2->val){
        //         p3->next=p2;
        //         p1=p2->next;
        //     }
        //     else{
        //         p3->next=p2;
        //         p2=p2->next;
        //     }
        //     p3=p3->next;
        // }
        // if(p1!=NULL){
        //     p3->next=p2;
        // }
        // return dummy->next;

        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }
      ListNode* result=nullptr;
      if(list1->val < list2-> val)
      {
        result=list1;
        result->next=mergeTwoLists(list1->next ,list2);
      }   
      else{
        result=list2;
        result->next=mergeTwoLists(list1,list2->next);
      }
      return result;
    }
};