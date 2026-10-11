
class Solution {
public:
    int reverseBits(int n) {
        uint32_t ans = 0;
        uint32_t num = static_cast<uint32_t>(n);

        for (int i = 0; i < 32; i++) {
            ans <<= 1;
            ans |= (num & 1);
            num >>= 1;
        }

        return static_cast<int>(ans);
    }
};
