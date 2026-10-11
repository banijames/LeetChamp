/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int lenCycle(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;

            if(slow == fast){
                //calculate length
                ListNode* temp = slow;
                int length = 0;
                do{
                    temp = temp -> next;
                    length++;
                }while(temp != slow);
                return length;
            }
        }
    return 0;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        int length = 0;
        //intializing for the case of if no cycle present
        bool hasCycle = false;
        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;

            //cycle found
            if(slow == fast){
                length = lenCycle(slow);
                hasCycle = true;
                break;
            }
        }
        if(!hasCycle){
            return NULL;
        }
        //find the starting node
        ListNode* first = head;
        ListNode* second = head;
        while(length>0){
            second = second -> next;
            length --;
        }
        //keep moving both forward until they meet each other
        while(first != second){
            first = first -> next;
            second = second -> next;
        }
        return second;
    }
};