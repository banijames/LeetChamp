/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //empty list
        if(head == NULL || head -> next == NULL){
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head;

        // Move fast by 2 steps and slow by 1 step
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            // If fast and slow meet, a cycle exists anywhere in the list
            if (slow == fast) {
                return true;
            }
        }

        // Reached NULL -> No cycle
        return false;
    }
};