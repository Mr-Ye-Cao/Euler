/*  Mistake made by me: 
 *      Spent too much time on finding high performance solution
 *
 *
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        int x=1;
        int y=1000;

        vector<vector<int>> result;

        while (x <= 1000 && y > 0) {
            int temp = customfunction.f(x, y);
            if (temp > z) {
                y--;
            } else if (temp < z) {
                x++;
            } else {
                result.push_back({x, y});
                y--;
                x++;
            }
        }

        return result;
    }
};