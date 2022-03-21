class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        int n = s.length();
        vector<int> arr(26, -1);
        
        for(int i = 0; i < n; i++) {
            arr[s[i]-'a'] = i;
        }
        
        vector<int> res;
        int cnt = 0;
        int lastIdx = 0;
        
        for(int i = 0; i < n; i++) {
            ++cnt;
            if(lastIdx < arr[s[i]-'a']) {
                lastIdx = arr[s[i]-'a'];
            }
            if(lastIdx == i) {
                res.push_back(cnt);
                cnt = 0;
            }
        }
        
        return res;
    }
};

// C# Language
public class Solution {
    public static int Compare(KeyValuePair<int, int> a, KeyValuePair<int, int> b) {
        return a.Key.CompareTo(b.Key);
    }
    public IList<int> PartitionLabels(string s) {
        int[] lPos = new int[26], rPos = new int[26];
        for(int i = 0; i < s.Length; ++i) rPos[s[i]-'a'] = i + 1;
        for(int i = s.Length - 1; i >= 0; --i) lPos[s[i]-'a'] = i + 1;
        List<KeyValuePair<int, int>> posList = new List<KeyValuePair<int, int>>();
        for(int i = 0; i < 26; ++i) {
            if(lPos[i] > 0) {
                posList.Add(new KeyValuePair<int, int>(lPos[i], rPos[i]));
            }
        }
        posList.Sort(Compare);
        List<int> res = new List<int>();
        int lMin = posList[0].Key, rMax = posList[0].Value;
        for(int i = 1; i < posList.Count; ++i) {
            if(posList[i].Key > rMax) {
                res.Add(rMax - lMin + 1);
                lMin = posList[i].Key;
                rMax = posList[i].Value;
            }
            else rMax = Math.Max(rMax, posList[i].Value);
        }
        res.Add(rMax - lMin + 1);
        return res;
    }
}
