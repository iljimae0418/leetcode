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
        if (head == NULL || head->next == NULL){
            return head; 
        }
        ListNode *oddList = new ListNode(-99999999); 
        ListNode *evenList = new ListNode(-99999999);  
        ListNode *connect = evenList; 
        ListNode *ret = oddList;  
        ListNode *temp = head; 
        int idx = 1; 
        while (temp != NULL){
            if (idx&1){ // odd 
                if (oddList->val == -99999999){
                    oddList->val = temp->val; 
                }else{
                    ListNode *nextNode = new ListNode(temp->val); 
                    oddList->next = nextNode;
                    oddList = nextNode; 
                }
            }else{
                if (evenList->val == -99999999){
                    evenList->val = temp->val;  
                }else{
                    ListNode *nextNode = new ListNode(temp->val);  
                    evenList->next = nextNode;   
                    evenList = nextNode; 
                }
            }  
            temp = temp->next; 
            idx++; 
        }
        oddList->next = connect; 
        return ret; 
    }
};
