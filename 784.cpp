class Solution {
public:
    void generateLetterCase(string s, string p, int idx, vector<string> &res) {
        if(idx == s.length()) {
            res.push_back(p);
            return;
        }
        p += s[idx];
        generateLetterCase(s, p, idx + 1, res);
        if(s[idx] >= 'a' && s[idx] <= 'z') {
            p.pop_back();
            p += s[idx] - 32;
            generateLetterCase(s, p, idx + 1, res);
        }
        else if(s[idx] >= 'A' && s[idx] <= 'Z') {
            p.pop_back();
            p += s[idx] + 32;
            generateLetterCase(s, p, idx + 1, res);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        generateLetterCase(s, "", 0, res);
        return res;
    }
};