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
    int pairSum(ListNode* head) {
        //so the approach we use is 
        //5->4 1->2 adding 5 with 1 and 4 with 2 since even sized
        //find the middle 
        //reverse
        //add
        ListNode* slow = head;
        ListNode* fast = head;

        //middle found
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        //reverse after middle 
        ListNode* curr = slow;
        ListNode* prev = NULL;
        while(curr!=NULL){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        //adding?
        //head = 0 5->4   and  prev = 1 1->2
        int maxsum = 0;
        ListNode* first = head;//5,4
        ListNode* second = prev;//1,2

        while(second!=NULL){
            maxsum = max(maxsum,first->val+second->val);//5+1
            first = first->next;//4
            second = second -> next;//2
        }
        return maxsum;
    }
};