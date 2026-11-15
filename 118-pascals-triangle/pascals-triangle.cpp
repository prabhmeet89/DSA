class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows; // yeh row bta rha hai kitni hai
        vector<vector<int>> v;
        for(int i = 0; i<n; i++){ // yeh har ek row ko taverse kar rha hai
            vector<int> a(i+1); // yeh har ek row mai elemtens bahr rha hai
            v.push_back(a); // or yeh [0,0] ka vector bna rhq hai
                for(int j = 0; j<=i; j++){
                    if(j==0 || j==i) v[i][j]=1;
                    else v[i][j] = v[i-1][j] + v[i-1][j-1];
                }
        }    
        return v;
    }
};