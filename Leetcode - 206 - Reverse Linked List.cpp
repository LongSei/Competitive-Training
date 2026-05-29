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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        if (head->next == nullptr) {
            return head;
        }
        ListNode* currentNode = head->next;
        ListNode* prevNode = head;
        prevNode->next = nullptr;
        ListNode* tempNode = nullptr;
        while (currentNode != nullptr) {
            tempNode = currentNode->next;
            currentNode->next = prevNode;
            prevNode = currentNode;
            currentNode = tempNode;
        }   
        return prevNode;
    }
};
