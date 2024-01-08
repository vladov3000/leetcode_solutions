/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix& matrix) {
        vector<int> dimensions = matrix.dimensions();
        int row    = 0;
        int column = dimensions[1] - 1;
        while (row < dimensions[0] && column >= 0)
            if (matrix.get(row, column) == 1)
                column--;
            else
                row++;
        return column == dimensions[1] - 1 ? -1 : column + 1;
    }
};
