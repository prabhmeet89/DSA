class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int prev[n];
        prev[0] = -1;
        int max = height[0];
        for(int i = 1; i<n; i++) {
            prev[i]=max;
            if(height[i]>max) max = height[i];
        }

        int next[n];
        next[n-1] = -1;
        max = height[n-1];
        for(int i = n-1; i>=0; i--){
            next[i] = max;
            if(height[i]>max) max = height[i];
        }

        for(int i =0; i<n; i++){
            prev[i] = min(prev[i],next[i]);
        }

        int water = 0;
        for(int i = 0; i<n; i++){
            if(height[i]<prev[i]) water += (prev[i]-height[i]);
        }
        return water; 
    }
};
