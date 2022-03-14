class Solution {
    public String simplifyPath(String path) {
        String[] dir = path.split("/");
        Stack<String> st = new Stack<>();
        for(String s : dir) {
            if(s.length() == 0) continue;
            else if(s.equals("..") && st.size() > 0) st.pop();
            else if(!s.equals(".") && !s.equals("..")) st.push(s);
        }
        StringBuilder sb = new StringBuilder();
        Iterator it = st.iterator();
        while(it.hasNext()) sb.append("/").append(it.next());
        return sb.length() > 0 ? sb.toString() : "/";
    }
}