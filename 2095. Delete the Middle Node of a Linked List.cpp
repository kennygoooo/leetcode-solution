// 2095. Delete the Middle Node of a Linked List

//Linked list

// p -> val = (*p).val 

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
    ListNode* deleteMiddle(ListNode* head) {
        
        // If the list is empty or has only one node, deleting the middle means the list becomes empty.
        if (!head || !head->next) return nullptr;


        // slow -> moves one step at a time
        // fast -> moves two steps at a time
        // prev -> keeps track of the node before slow
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        

        // When the list has odd length (7 nodes)
        // 1 → 3 → 4 → 7 → 1 → 2 → 6 → NULL
        // fast : 1 -> 4 -> 1 -> 6
        // fast->next: 3 -> 7 -> 2 -> NULL


                

        // When the list has eve length (6 nodes)
        // 1 → 3 → 4 → 7 → 1 → 2 → NULL
        // fast : 1 -> 4 -> 1 -> NULL
        // fast->next: 3 -> 7 -> 2 -> N/A

        while (fast && fast->next) {
            prev = slow; // Store the node before slow
            slow = slow->next; // Move slow one step
            fast = fast->next->next; // Move fast two steps
        }

        // Remove the middle node by linking prev->next to slow->next
        prev->next = slow->next;

        // Free the memory of the deleted node
        delete slow;

        return head;
    }
};