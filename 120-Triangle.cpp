class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row=triangle.size();
        vector<vector<int> > f(triangle);
        //cout << f[2][1];
        for(int x=row-2;x>=0;x--){
            for(int y=0;y<=x;y++){
                f[x][y] = min(f[x+1][y+1],f[x+1][y])+triangle[x][y];
            }
        }
        return f[0][0];
    }
};
