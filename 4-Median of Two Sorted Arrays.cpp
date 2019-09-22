class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v(nums1);
        v.insert(v.end(),nums2.begin(),nums2.end());
        quicksort(v, 0, v.size() - 1);
        if(v.size()%2 ==0){
            //cout << v[v.size()/2-1] << " " << v[v.size()/2];
            double a=v[v.size()/2-1], b= v[v.size()/2];
            return (a+b)/2;
        }else{
            //cout << v[v.size()/2];
            double c=v[v.size()/2];
            return c;
        }
        //for (auto it = v.begin(); it != v.end(); it++) 
        //    cout << *it << " "; 
        return 0;
    }
    
    int partition(vector<int> &values, int left, int right) {
        int pivotIndex = left + (right - left) / 2;
        int pivotValue = values[pivotIndex];
        int i = left, j = right;
        int temp;
        while(i <= j) {
            while(values[i] < pivotValue) {
                i++;
            }
            while(values[j] > pivotValue) {
                j--;
            }
            if(i <= j) {
                temp = values[i];
                values[i] = values[j];
                values[j] = temp;
                i++;
                j--;
            }
        }
        return i;
    }
    void quicksort(vector<int> &values, int left, int right) {
        if(left < right) {
            int pivotIndex = partition(values, left, right);
            quicksort(values, left, pivotIndex - 1);
            quicksort(values, pivotIndex, right);
    }
}
};
