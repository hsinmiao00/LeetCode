//1351. Count Negative Numbers in a Sorted Matrix
class Solution {
public:
    int BinarySearchInRow(vector<int> row){
        if( row.empty() || row.at(row.size()-1) >= 0 ) return 0;
        int count=0;
        if(row[0] < 0){
            return row.size();
        }
        else{
            if(row[row.size()/2 ] < 0 ){
                count+= row.size() - row.size()/2;   
                vector<int> newVec(row.begin(), row.begin() + row.size()/2);
                count+=BinarySearchInRow(newVec);
            }
            else{
                vector<int> newVec(row.begin() + row.size()/2,row.end());
                count=BinarySearchInRow(newVec);
            }
                
        }
        return count;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++){
            count+=BinarySearchInRow(grid[i]);
        }
        return count;
    }
};
/*
Runtime: 40 ms, faster than 28.26% of C++ online submissions for Count Negative Numbers in a Sorted Matrix.
Memory Usage: 12.9 MB, less than 5.08% of C++ online submissions for Count Negative Numbers in a Sorted Matrix.


Should not use recursive


 int binarysearch(vector<int> nums)
    {
        int low=0;
        int high=nums.size()-1;
        
        while(low<high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]<0)
                high=mid;
            else
                low=mid+1;
        }
        
        if(nums[low]<0)
            return nums.size()-low;
        else
            return 0;
    }



Runtime: 32 ms, faster than 91.10% of C++ online submissions for Count Negative Numbers in a Sorted Matrix.
Memory Usage: 11.1 MB, less than 10.63% of C++ online submissions for Count Negative Numbers in a Sorted Matrix.



*/
