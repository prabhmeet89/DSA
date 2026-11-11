class Solution {
public:
     ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* c = new ListNode(100);
        ListNode* tempc = c;
        while(a!=NULL && b!=NULL){
            if(a->val <= b->val){
                tempc->next = a;
                a = a->next;
                tempc = tempc->next;
            }
            else{
                tempc->next = b;
                b = b->next;
                tempc = tempc->next;
            }
        }
        if(a==NULL) tempc->next = b;
        else tempc->next = a;
        return c->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& arr) {
        if(arr.size()==0) return NULL;
        while(arr.size()>1){
        ListNode* a = arr[0];
        arr.erase(arr.begin());
        ListNode* b = arr[0];
        arr.erase(arr.begin());
        ListNode* c = merge(a,b);
        arr.push_back(c);
        }
        return arr[0];
    }

};