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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head -> next == NULL) return head;

        ListNode* dummyNode = new ListNode();

        ListNode* prevNode = dummyNode;
        ListNode* curr = head;

        while(curr && curr->next){
            prevNode-> next = curr->next;
            curr->next = prevNode->next->next;
            prevNode->next->next = curr;

            prevNode = curr;
            curr = curr->next;
        }
        return dummyNode -> next;
    }
};