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
    void reorderList(ListNode* head) {
      if(!head||!(head->next)||!(head->next->next))return;/*edge cases of the linked list ,basically we cant reorder the list cuz , theres no need of reordering when there is just 1,2,3 elements in the list */
        ListNode* ptr=head;
        int size=0;
        
      
             stack<ListNode *>st;// we push eevery node into the list 
          while(ptr!=NULL){
             st.push(ptr);
              size++;
              ptr=ptr->next;
          }
          ListNode *pptr=head;
          for(int i=0;i<size/2;i++){/*and we also connect the alternative nodes to the top of the stack */ 
             ListNode *ele=st.top();
              st.pop();
              ele->next=pptr->next;
              pptr->next=ele;
              pptr=pptr->next->next;
          }
          pptr->next=NULL;//end of the list has to be assigned with NULL
       
    }
};