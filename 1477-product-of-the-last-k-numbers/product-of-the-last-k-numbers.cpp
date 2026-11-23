
class ProductOfNumbers {
public:
    vector<int> v;

    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num==0){
            v.clear();
        }
        else{
            if(v.size()==0){
                v.push_back(num);
            }
            else{
                v.push_back(v.back()*num);
            }
        }
    }
    
    int getProduct(int k) {
        if(v.size()<k) return 0;

        if(v.size()==k) return v.back();

        return v.back()/v[v.size()-k-1];
    }
};
