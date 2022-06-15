class NumArray {
public:   
    NumArray(vector<int>& nums) {
        input = nums;
        size = nums.size();
        for (int i = 0; i < nums.size(); i++)
            fenwickTree.push_back(0);
        buildTree();
    }
    
    void update(int index, int val) {
        auto delta = val - input[index];
        addTree(index, delta);
        input[index] = val;
    }
    
    int sumRange(int left, int right) {
        if (left == 0)
            return sumRangeHelper(right);
        return sumRangeHelper(right) - sumRangeHelper(left - 1);
    }
    
private:
    int size;
    vector<int> fenwickTree;
    vector<int> input;
   
    void buildTree() {
        for (int i = 0; i < size; i++)
            addTree(i, input[i]);
    }
    
    void addTree(int index, int delta) {
        while (index < size) {
            fenwickTree[index] += delta;
            index = (index | index + 1);
        }
    }
    
    int sumRangeHelper(int r) {
        int sum = 0;
        while (r >= 0) {
            sum += fenwickTree[r];
            r = (r & (r + 1)) - 1;
        }
        return sum;
    }
};