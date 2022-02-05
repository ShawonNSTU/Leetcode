class Solution {
    
    map<char, vector<string> > mp;
    vector<string> res;
    
    void combination(int pos, string digits, string curr) {
        
        if(digits.size() == pos) res.push_back(curr);
        
        vector<string> vec = mp[digits[pos]];
        
        for(int i = 0; i < vec.size(); i++) {
            curr += vec[i];
            combination(pos + 1, digits, curr);
            curr.pop_back();
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        
        if(digits.size() == 0) return res;
        
        mp['2'] = {"a", "b", "c"};
        mp['3'] = {"d", "e", "f"};
        mp['4'] = {"g", "h", "i"};
        mp['5'] = {"j", "k", "l"};
        mp['6'] = {"m", "n", "o"};
        mp['7'] = {"p", "q", "r", "s"};
        mp['8'] = {"t", "u", "v"};
        mp['9'] = {"w", "x", "y", "z"};
        
        combination(0, digits, "");
        
        return res;
    }
};