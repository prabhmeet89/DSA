
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode* c = new ListNode(100);
        ListNode* tempc = c;

        while(a != NULL && b != NULL) {
            if(a->val <= b->val) {
                tempc->next = a;
                a = a->next;
                tempc = tempc->next;
            }
            else {
                tempc->next = b;
                b = b->next;
                tempc = tempc->next;
            }
        }

        if(a == NULL) tempc->next = b;
        else tempc->next = a;

        return c->next;
    }

    ListNode* sortList(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return head;

        // Find left middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* a = head;
        ListNode* b = slow->next;

        slow->next = NULL;

        a = sortList(a);
        b = sortList(b);

        ListNode* c = mergeTwoLists(a, b);

        return c;
    }
};
