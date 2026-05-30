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
        if (head == nullptr) {
            return nullptr;
        }
        if (head->next == nullptr) {
            return head;
        }
        ListNode* currentNode = head->next;
        ListNode* prevNode = head; 
        ListNode* tempNode = nullptr;

        ListNode* returnNode = head->next;

        bool turn = true; 
        while (true) {
            if (turn) {
                prevNode->next = currentNode->next;
                currentNode->next = prevNode;
                tempNode = currentNode;  
                currentNode = prevNode->next; 
            } else if (!turn && currentNode->next != nullptr) {
                tempNode = prevNode->next; 
                prevNode->next = currentNode->next;
                prevNode = tempNode;
                currentNode = currentNode->next;
            } else {
                break;
            }
            turn = !turn;
            if (currentNode == nullptr) {
                break;
            }
        } 
        return returnNode;
    }
};
