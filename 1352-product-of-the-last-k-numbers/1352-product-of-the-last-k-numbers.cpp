class ProductOfNumbers {
public:
    vector<int> prefix;

    ProductOfNumbers() {}
    void add(int num) {
        prefix.push_back(num);
    }
    int getProduct(int k) {
        int product = 1;

        for(int i = prefix.size() - k; i < prefix.size(); i++) {
            product *= prefix[i];
        }
        return product;
    }
};