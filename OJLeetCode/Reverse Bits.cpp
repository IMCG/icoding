/*Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), 
return 964176192 (represented in binary as 00111001011110000010100101000000).
*/
//AC
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> b(n);
		uint32_t res = 0;
		for (int i = 0; i <= 31; ++i){
			res += b[31 - i] * (1 << i);
		}
		return res;
    }
};