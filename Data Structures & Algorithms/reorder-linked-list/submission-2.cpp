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
    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* list2 = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        ListNode* curr = list2;
        while(curr){
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        ListNode* list1 = head;
        list2 = prev;
        while(list1 && list2){
            ListNode* tmp1 = list1->next;
            ListNode* tmp2 = list2->next;
            list1->next = list2;
            list2->next = tmp1;
            list1 = tmp1;
            list2 = tmp2;
        }

    }
};
