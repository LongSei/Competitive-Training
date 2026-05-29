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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) {
            return nullptr;
        }
        if (head->next == nullptr) {
            return nullptr;
        }
        int get_size = 0;
        ListNode* currentNode = head;
        while (currentNode) {
            get_size += 1;
            currentNode = currentNode->next;
        }

        int position_remove = get_size - n + 1;
        if (position_remove == 1) {
            return head->next;
        }
        currentNode = head;
        ListNode* prevNode = nullptr;
        while (position_remove) {
            position_remove -= 1;
            if (position_remove == 0) {
                prevNode->next = currentNode->next;
            } else {
                prevNode = currentNode;
                currentNode = currentNode->next;
            }
        }
        return head;
    }
};
