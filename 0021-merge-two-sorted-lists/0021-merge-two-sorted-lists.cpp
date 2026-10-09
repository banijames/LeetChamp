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
private:
private:
    ListNode* solve(ListNode* list1, ListNode* list2) {
        // If list1 has only one node, attach list2 directly to its next
        if (list1->next == NULL) {
            list1->next = list2;
            return list1;
        }

        ListNode* curr1 = list1;
        ListNode* next1 = curr1->next;
        ListNode* curr2 = list2;

        while (next1 != NULL && curr2 != NULL) {
            if ((curr2->val >= curr1->val) && (curr2->val <= next1->val)) {
                // Insert curr2 between curr1 and next1
                curr1->next = curr2;
                ListNode* next2 = curr2->next; // Declared type
                curr2->next = next1;

                // Update pointers
                curr1 = curr2;
                curr2 = next2;
            } else {
                // Move curr1 and next1 forward
                curr1 = next1;
                next1 = next1->next;

                // If end of list1 reached, append remaining list2
                if (next1 == NULL) {
                    curr1->next = curr2;
                    return list1;
                }
            }
        }
        return list1;
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;

        // Ensure solve() is always called with the list starting with the smaller head
        if (list1->val <= list2->val) {
            return solve(list1, list2);
        } else {
            return solve(list2, list1);
        }
    }
};