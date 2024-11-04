// 61. Rotate List
// Solved
// Medium
// Topics
// Companies
// Given the head of a linked list, rotate the list to the right by k places.

 

// Example 1:


// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]
// Example 2:


// Input: head = [0,1,2], k = 4
// Output: [2,0,1]
 

// Constraints:

// The number of nodes in the list is in the range [0, 500].
// -100 <= Node.val <= 100
// 0 <= k <= 2 * 109

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !k)
            return head;
        ListNode* iter = head;
        // ListNode* prev = head;
        ListNode* last = head;
        int cnt = 1;
        while (last->next != nullptr) {
            last = last->next;
            cnt += 1;
        }
        if (k % cnt == 0)
            return head;
        k = k % cnt;
        last->next = head;
        int start =1;
         for (int i = 1; i < cnt - k; i++) {
            iter = iter->next;
        }

        // Set the new head and break the loop
        head = iter->next;
        iter->next = nullptr;
        return head;
    }
};