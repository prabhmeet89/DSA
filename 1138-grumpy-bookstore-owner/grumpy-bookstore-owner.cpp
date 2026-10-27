class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        vector<int>& arr = customers;
        int n = arr.size();
        int k = minutes;
        int maxloss = 0;
        int prevloss = 0;
        int maxidx = 0;
        for(int i = 0; i<n; i++){
            if(grumpy[i]==1) prevloss +=arr[i];
        }
        maxloss = prevloss;
        int i = 1;
        int j = k;
        while(j<n){
            int currloss = prevloss;
            if(grumpy[j]==1) currloss +=arr[j];
            if(grumpy[i-1]==1) currloss -=arr[i-1];
            if(maxloss<currloss){
                maxloss = currloss;
                maxidx = i;
            }
            prevloss = currloss;
            i++;
            j++;
        }
        for(int i = maxidx; i<maxidx+k; i++){
            grumpy[i] = 0;
        }
        int sum = 0;
        for(int i = 0; i<n; i++){
            if(grumpy[i]==0) sum +=arr[i];
        }
        return sum;
    }
};