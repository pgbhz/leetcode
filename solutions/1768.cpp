// as we need a bulk append of the remaining of the larger string, two pointers seems reasonable
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int i = 0, j = 0;
        std::string result = "";
        bool toggle = true;
        while (i < n && j < m) {
            result += word1[i++];
            result += word2[j++];
        }
        while (i < n) {
            result += word1[i++];
        }
        while (j < m) {
            result += word2[j++];
        }
        return result;
    }
};