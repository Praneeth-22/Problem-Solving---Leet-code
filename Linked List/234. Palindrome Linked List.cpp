//234. Palindrome Linked List
//Solved
//Easy
//Topics
//Companies
//Given the head of a singly linked list, return true if it is a 
//palindrome
// or false otherwise.
//
// 
//
//Example 1:
//
//
//Input: head = [1,2,2,1]
//Output: true
//Example 2:
//
//
//Input: head = [1,2]
//Output: false
// 
//
//Constraints:
//
//The number of nodes in the list is in the range [1, 105].
//0 <= Node.val <= 9

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
    ListNode* reversePart(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr!=NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        //brute force
        // vector<int> list;
        // ListNode* head = temp;
        // while(head!=NULL){
        //     list.push_back(head->val);
        //     head = head->next;
        // }
        // int l=0,r = list.size()-1;
        // while(l<=r){
        //     if(list[l]!=list[r]) return false;
        //     l++;r--;
        // }
        // return true;
        //
        if(head == NULL || head->next == NULL) return true;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast= fast->next->next;
        }
        ListNode* newHead = reversePart(slow->next);
        slow->next= NULL;
        ListNode* left = head;
        ListNode* right = newHead;
        while(right!=NULL){
            if(left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }
};
