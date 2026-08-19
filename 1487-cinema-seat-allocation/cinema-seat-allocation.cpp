class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rowMask; // row -> bitmask of reserved seats (bits 2..9 used)

        for (auto &r : reservedSeats) {
            int row = r[0], seat = r[1];
            if (seat >= 2 && seat <= 9) {
                rowMask[row] |= (1 << seat);
            }
            // seats 1 and 10 never matter, since no block uses them
        }

        // Bitmasks for the three possible blocks
        const int leftMask  = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5); // seats 2-5
        const int midMask   = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7); // seats 4-7
        const int rightMask = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9); // seats 6-9

        // Rows with no reservations at all can fit 2 groups each
        int result = 2 * (n - (int)rowMask.size());

        for (auto &[row, mask] : rowMask) {
            bool leftFree  = (mask & leftMask)  == 0;
            bool rightFree = (mask & rightMask) == 0;

            if (leftFree && rightFree) {
                result += 2; // left and right blocks don't overlap, both fit
            } else if (leftFree || rightFree || (mask & midMask) == 0) {
                result += 1; // at least one block (left, right, or middle) is free
            }
            // else: no block fits in this row, add 0
        }

        return result;
    }
};