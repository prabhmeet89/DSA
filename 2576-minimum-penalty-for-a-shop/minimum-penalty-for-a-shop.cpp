class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int pre[n+1]; // yeh hai n ke liye 
        int suf[n+1]; // yeh y ke liye 
        pre[0] = 0;
        for(int i = 0; i<n; i++){
            pre[i+1] = pre[i] + ((customers[i]=='N') ? 1:0);
        }
        suf[n] = 0;
        for(int i = n-1; i>=0; i--){
            suf[i] = suf[i+1] + ((customers[i]=='Y') ? 1:0);
        }
        int minpen = n;
        for(int i = 0; i<=n; i++){
            pre[i] += suf[i];
            int pen = pre[i];
            minpen = min(minpen,pen);
        }

        for(int i = 0; i<=n; i++){
            int pen = pre[i];
            if(pen==minpen) return i;
        }
        return n;
    }
};