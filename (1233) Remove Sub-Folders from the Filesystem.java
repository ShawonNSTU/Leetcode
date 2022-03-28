class Solution {
    int[][] prefixTree;
    boolean[] endDir;
    int nNode;
    private void initPrefixTree() {
        prefixTree = new int[100001][27];
        endDir = new boolean[100001];
        nNode = 0;
        for(int i = 0; i < 27; ++i) prefixTree[0][i] = -1;
    }
    private boolean insert(String dir) {
        int currNode = 0;
        for(int i = 0; i < dir.length(); ++i) {
            int idx = dir.charAt(i) == '/' ? 0 : dir.charAt(i) - 'a' + 1;
            if(prefixTree[currNode][idx] == -1) {
                prefixTree[currNode][idx] = ++nNode;
                for(int j = 0; j < 27; ++j) prefixTree[nNode][j] = -1;
            }
            currNode = prefixTree[currNode][idx];
            if(endDir[currNode] && dir.charAt(i+1) == '/') return false;
        }
        return endDir[currNode] = true;
    }
    public List<String> removeSubfolders(String[] folder) {
        initPrefixTree();
        Arrays.sort(folder);
        List<String> res = new ArrayList<String>();
        for(String dir : folder) {
            if(insert(dir)) res.add(dir);
        }
        return res;
    }
}