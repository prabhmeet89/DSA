class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* Next = NULL;
        while(curr!=NULL){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        ListNode* a = NULL;
        ListNode* b = NULL;
        ListNode* c = NULL;
        ListNode* d = NULL;
        ListNode* temp = head;
        int n = 1;
        while(temp!=NULL){
            if(n==left-1) a=temp;
            if(n==left) b=temp;
            if(n==right) c=temp;
            if(n==right+1){ d = temp; break; }   // ✅ d mil gaya to aage traverse mat karo
            temp = temp->next;
            n++;
        }
        if(a!=NULL) a->next = NULL;
        c->next = NULL;
        c = reverseList(b);
        if(a!=NULL) a->next = c;
        b->next = d;
        if(a!=NULL) return head;
        return c;
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* temp = head;   // ✅ temp = previous group ka last node
        int gap = 2;             // ✅ next group ka size (pehla group size 1 hai, skip)
        while(temp && temp->next){
            // actual length count karo (last group chhota ho sakta hai)
            int len = 0;
            ListNode* t = temp->next;
            while(len < gap && t != NULL){
                t = t->next;
                len++;
            }

            // even hai to reverse karo (temp position 1 hai, group 2..len+1 pe hai)
            if(len % 2 == 0) reverseBetween(temp, 2, 1 + len);

            // temp ko is group ke last node pe le jao
            for(int i = 0; i < len; i++) temp = temp->next;

            gap++;
        }
        return head;
    }
};