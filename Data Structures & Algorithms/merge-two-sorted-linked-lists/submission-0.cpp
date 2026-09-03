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
    ListNode **minNode(ListNode **l1, ListNode **l2){
        ListNode *list1 = *l1;
        ListNode *list2 = *l2;

        if(list1 == nullptr){
            return l2;
        }
        else if (list2 == nullptr){
            return l1;
        }
        else{
            if(list1->val < list2->val){
                return l1;
            }
            else{
                return l2;
            }
        }

        return nullptr; // should never happen
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode **min = minNode(&list1, &list2);
        ListNode *head = *min;
        ListNode *prev = *min;

        if(head == nullptr)
            return head;

        (*min) = (*min)->next;

        while(list1 != nullptr || list2 != nullptr){
            min = minNode(&list1, &list2);

            prev->next = *min;
            prev = *min;
            (*min) = (*min)->next;
        }

        return head;
    }
};