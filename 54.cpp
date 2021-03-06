class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size()!=0)
        {
            int m=matrix.size();
            int n=matrix[0].size();
            int l,r,u,d;
            l=0,r=n,u=0,d=m;
            while(r>l&&d>u){
                int i=l;
                int j=u;
                for(;i<r;++i)    res.push_back(matrix[j][i]);
                --i;
                if(u+1==d) break;
                for(j++;j<d;++j) res.push_back(matrix[j][i]);
                --j;
                if(l+1==r) break;
                for(--i;i>=l;--i) res.push_back(matrix[j][i]);
                ++i;
                for(--j;j>u;--j) res.push_back(matrix[j][i]);
                l++;
                u++;
                d--;
                r--;
            }
        }
        return res;
    }
};
/* 解题思路：
1.按圈循环处理
2.在只剩一行或只剩一列时，在输出行或输出列后跳出
*/

/* Others

Visualization
Here's how the matrix changes by always extracting the first row and rotating the remaining matrix counter-clockwise:

    |1 2 3|      |6 9|      |8 7|      |4|  =>  |5|  =>  ||
    |4 5 6|  =>  |5 8|  =>  |5 4|  =>  |5|
    |7 8 9|      |4 7|
Now look at the first rows we extracted:

    |1 2 3|      |6 9|      |8 7|      |4|      |5|
Those concatenated are the desired result.

Another visualization
  spiral_order([[1, 2, 3],
                [4, 5, 6],
                [7, 8, 9]])

= [1, 2, 3] + spiral_order([[6, 9],
                            [5, 8],
                            [4, 7]])

= [1, 2, 3] + [6, 9] + spiral_order([[8, 7],
                                     [5, 4]])

= [1, 2, 3] + [6, 9] + [8, 7] + spiral_order([[4],
                                              [5]])

= [1, 2, 3] + [6, 9] + [8, 7] + [4] + spiral_order([[5]])

= [1, 2, 3] + [6, 9] + [8, 7] + [4] + [5] + spiral_order([])

= [1, 2, 3] + [6, 9] + [8, 7] + [4] + [5] + []

= [1, 2, 3, 6, 9, 8, 7, 4, 5]

*/
