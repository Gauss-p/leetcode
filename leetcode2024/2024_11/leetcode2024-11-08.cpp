#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<bool> visited;
    bool pointInCircle(int px, int py, int x, int y, int r){
        // 该函数用来判断一个点(px,py)是否在给定的圆内，直接用点到圆心的距离和半径的大小关系比较即可
        long long left = 1ll*(px-x)*(px-x)+1ll*(py-y)*(py-y);
        long long right = 1ll*r*r;
        return left <= right;
    }
    bool circleIntersect_LeftTop(int x, int y, int r, int xCorner, int yCorner){
        // 该函数用来判断给定的圆和给定矩形的左、上边是否相交
        bool leftIntersect = ((abs(x-0) <= r) && (0 <= y && y <= yCorner)); // 是否与左边相交
        bool topIntersect = ((abs(y-yCorner) <= r) && (0 <= x && x <= xCorner)); // 是否与上边相交
        // 但是如果单独判断上面两种情况是不够的，如果有一个圆非常大，却只有一点点和矩形的左上角相交，上面两种情况就都无法成立，所以我们还需要判断一下坐上顶点是否在圆内
        bool topLeft_Point = pointInCircle(0, yCorner, x, y, r);
        return leftIntersect || topIntersect || topLeft_Point; // 最后，三种情况相或即可
    }
    bool circleIntersect_RightBottom(int x, int y, int r, int xCorner, int yCorner){
        // 该函数用来判断给定的圆和给定矩形的右、下边是否相交
        bool rightIntersect = ((abs(x-xCorner) <= r) && (0 <= y && y <= yCorner)); // 是否与右边相交
        bool bottomIntersect = ((abs(y-0) <= r) && (0 <= x && x <= xCorner)); // 是否与下边相交
        // 和上一个函数一样，单独上面两种情况会出现纰漏，所以还需再次判断右下顶点是否在圆内
        bool rightBottom_Point = pointInCircle(xCorner, 0, x, y, r);
        return rightIntersect || bottomIntersect || rightBottom_Point;
    }
    bool twoCircles_Intersect(int x1, int y1, int r1, int x2, int y2, int r2, int xCorner, int yCorner){
        // 该函数用来判断两个给定的圆的相交部分是否在矩形内部
        bool circlesIntersect = (1ll*(x1-x2)*(x1-x2)+1ll*(y1-y2)*(y1-y2))<=1ll*(r1+r2)*(r1+r2);
        // 第一个要满足的条件就是两个圆相交，接下来在相交的区域内取一个点，可以用定比分点的方法，取一点A使得AO1:AO2 = r1:r2，所以点A的横坐标就是(r2*x1+r1*x2)/(r1+r2)，纵坐标就是(r2*y1+r2*y2)/(r1+r2)
        // 如果该点位于矩形的内部，那么就说明这两个给定的圆的相交部分在矩形的内部，否则就不在
        bool xA = (1ll*r2*x1+1ll*r1*x2) <= 1ll*(r1+r2)*xCorner;
        bool yA = (1ll*r2*y1+1ll*r1*y2) <= 1ll*(r1+r2)*yCorner;
        return circlesIntersect && xA && yA;
    }
    bool dfs(int i, int xCorner, int yCorner, vector<vector<int>> &circles){
        // 该函数用来判断从第i个圆出发，是否能把从矩形左下到右上的通路给阻断，用dfs的方法，从一个与左上边相交的圆出发，不断和其他的圆连接并形成一个阻拦网，看最终是否能到达一个与右下边相交的圆，如果能够到达，就说明有一条由圆构成的阻拦网把左下点和右上点完全隔开，无法存在一条通路，这时返回true，否则返回false，表示无法完全阻断
        int curX = circles[i][0], curY = circles[i][1], curR = circles[i][2];
        if (circleIntersect_RightBottom(curX, curY, curR, xCorner, yCorner)){
            // 如果碰到右下边，又因为是从左上边开始的，那么说明可以完全阻断
            return true;
        }
        visited[i] = true; // 否则先标记，然后继续找和当前圆相交的圆，继续寻找
        for (int j=0; j<circles.size(); j++){
            int nX = circles[j][0], nY = circles[j][1], nR = circles[j][2];
            if (!visited[j] && twoCircles_Intersect(curX, curY, curR, nX, nY, nR, xCorner, yCorner) && dfs(j, xCorner, yCorner, circles)){
                return true;
            }
        }
        // 如果能执行到这里，说明无法完全阻断，返回false
        return false;
    }
public:
    bool canReachCorner(int X, int Y, vector<vector<int>>& circles) {
        int n = circles.size();
        visited.resize(n, false);
        for (int i=0; i<n; i++){
            int x = circles[i][0], y = circles[i][1], r = circles[i][2];
            // 只要右上顶点或左下顶点有一个被圆包裹，就返回false
            if (pointInCircle(0, 0, x, y, r) || pointInCircle(X, Y, x, y, r)){
                return false;
            }
        }
        for (int i=0; i<n; i++){
            int x = circles[i][0], y = circles[i][1], r = circles[i][2];
            if (!visited[i] && circleIntersect_LeftTop(x, y, r, X, Y) && dfs(i, X, Y, circles)){
                // 如果当前圆与左上边相交，那么如果从当前圆开始能够到达一个与右下边相交的圆，就返回false
                return false;
            }
        }
        // 如果能到这里，说明一定有一条通路，返回true即可
        return true;
    }
};

int main(){
    Solution s;
    int X = 3, Y = 4;
    vector<vector<int>> circles = {{2,1,1}};
    cout << s.canReachCorner(X,Y,circles) << endl;
}
