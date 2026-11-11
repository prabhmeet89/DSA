
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));

        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;

        ListNode* temp = head;

        while (top <= bottom && left <= right) {
            if (temp == NULL) return matrix;

            // 1. Left -> Right
            for (int j = left; j <= right && temp != NULL; j++) {
                matrix[top][j] = temp->val;
                temp = temp->next;
            }
            top++;

            // 2. Top -> Bottom
            for (int i = top; i <= bottom && temp != NULL; i++) {
                matrix[i][right] = temp->val;
                temp = temp->next;
            }
            right--;

            // 3. Right -> Left
            if (top <= bottom) {
                for (int j = right; j >= left && temp != NULL; j--) {
                    matrix[bottom][j] = temp->val;
                    temp = temp->next;
                }
                bottom--;
            }

            // 4. Bottom -> Top
            if (left <= right) {
                for (int i = bottom; i >= top && temp != NULL; i--) {
                    matrix[i][left] = temp->val;
                    temp = temp->next;
                }
                left++;
            }
        }

        return matrix;
    }
};
