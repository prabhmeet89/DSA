class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;   // ✅ empty list ka case

        // step -1 create a deep copy of LL
        Node* temp = head;
        Node* dummy = new Node(100);
        Node* tempD = dummy;
        while(temp){
            Node* a = new Node(temp->val);
            tempD->next = a;            // ✅ pehle link karo
            tempD = tempD->next;        // ✅ phir aage badho
            temp = temp->next;
        }

        // step 2 alternate connection
        Node* duplicate = dummy->next;
        Node* a = head;
        Node* b = duplicate;
        dummy = new Node(100);
        tempD = dummy;
        while(a){
            tempD->next = a;
            tempD = tempD->next;
            a = a->next;

            tempD->next = b;
            tempD = tempD->next;
            b = b->next;
        }
        dummy = dummy->next;

        // step 3 make random connection
        Node* t1 = dummy;
        while(t1){
            Node* t2 = t1->next;
            if(t1->random){
                t2->random = t1->random->next;
            }
            t1 = t1->next->next;        // ✅ if ke bahar, warna random NULL pe infinite loop
        }

        // step 4 remove connection
        Node* d1 = new Node(100);
        Node* d2 = new Node(100);
        Node* t = dummy;
        t1 = d1;
        Node* t2 = d2;
        while(t){                       // ✅ t1 ki jagah t pe loop
            t1->next = t;
            t = t->next;
            t1 = t1->next;

            t2->next = t;
            t = t->next;
            t2 = t2->next;
        }
        t1->next = NULL;
        t2->next = NULL;
        d1 = d1->next;
        d2 = d2->next;
        return d2;
    }
};