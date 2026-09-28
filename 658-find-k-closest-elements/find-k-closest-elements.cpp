class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size(); // size nikala array ka 
        vector<int> ans(k); // yeh vector bnaya jisme um push kar rahe hai  element
        if(x<arr[0]){
            for(int i = 0; i<k; i++){
                ans[i] = arr[i];
            }
            return ans;
        }
        if(x>arr[n-1]){ // k =3 // 000  // 345
            int i = n-1;
            int j = k-1;
            while(j>=0){
                ans[j] = arr[i];
                i--;
                j--;
            }
            return ans;
        }
        int low = 0;
        int high = n-1;
        int mid = -1;
        bool flag = false; // if x is not present
        int t = 0; // representig index of ans vector
        while(low<=high){
            mid = low + (high-low)/2;
            if(arr[mid]==x){
                flag = true;
                ans[t] = arr[mid];
                t++;
                break;
            }
            else if(arr[mid]>x) high = mid-1;
            else low = mid+1;
        }
        int lb = high;
        int ub = low;
        if(flag==true){
            lb = mid-1;
            ub = mid+1;
        }
        while(t<k && lb>=0 && ub<=n-1){
            int d1 = abs((x-arr[lb]));
            int d2 = abs((x-arr[ub])); // abs function modules nikalta hai
            if(d1<=d2){
                ans[t] = arr[lb];
                lb--;
            }
            else{ // d1 bada hai d2 se
                ans[t] = arr[ub];
                ub++;
            }
            t++; //yeh dono mai hora isiliye humne isse bhar likha hai
        }
        if(lb<0){
            while(t<k){
                ans[t] = arr[ub];
                ub++;
                t++;
            }
        }
        if(ub>n-1){
            while(t<k){
                ans[t] = arr[lb];
                lb--;
                t++;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;

        
    }
};