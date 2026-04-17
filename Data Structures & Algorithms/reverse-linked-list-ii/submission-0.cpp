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
    void reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr){
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0,head);
        ListNode* preNode = &dummy;
        ListNode* rightNode = &dummy;
        for(int i = 0; i < left - 1; i++){
            preNode = preNode->next;
        }
        for(int j = 0; j < right; j++){
            rightNode = rightNode->next;
        }
        ListNode* leftNode = preNode->next;
        ListNode* currNode = rightNode->next;
        preNode->next = nullptr;
        rightNode->next = nullptr;
        reverse(leftNode);
        preNode->next = rightNode;
        leftNode->next = currNode;
        return dummy.next;
    }
};