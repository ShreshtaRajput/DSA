class ProductOfNumbers {
public:
    vector<int> prefixProd;
    int size = 0;

    ProductOfNumbers() {
        prefixProd.push_back(1);
    }
    
    void add(int num) {
        if(num == 0){
            // reset the array
            prefixProd = {1};
            size = 0;
        }else{
            prefixProd.push_back(prefixProd[size] * num);
            size++;
        }
    }
    
    int getProduct(int k) {
        if(k > size) return 0;
        return prefixProd[size]/prefixProd[size - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */