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
#include <vector> 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        vector<int> v; 
        ListNode *temp = head; 
        while (temp != NULL){
            v.push_back(temp->val); 
            temp = temp->next;  
        }
        reverse(v.begin(),v.end());   
        if (v.size() <= 1){
            return head; 
        }
        ListNode *newNode = new ListNode(v[0]); 
        ListNode *ret = newNode; 
        for (int i = 1; i < v.size(); i++){
            ListNode *nextNode = new ListNode(v[i]); 
            newNode->next = nextNode; 
            newNode = nextNode; 
        }
        return ret; 
    }
};
