class Solution {
public:
    double x,y,r;
    Solution(double radius, double x_center, double y_center) 
        :x(x_center),y(y_center),r(radius)
    {
        srand(time(0));
    }
    
    vector<double> randPoint() {
        double ar=sqrt((double)rand()/RAND_MAX)*r,aa=(double)rand()/RAND_MAX*2.0*acos(-1.0);
        vector<double> ans={x+ar*cos(aa),y+ar*sin(aa)};
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj.randPoint();
 */