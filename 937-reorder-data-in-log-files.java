class Solution {
    private Boolean isDigLog(String log) {
        for (int i = 1; i < log.length() - 1; i++) {
            if (log.charAt(i) == ' ') {
                int next = (int) log.charAt(i + 1) - (int) '0';
                return 0 <= next && next <= 9;
            }
        }
        
        return false;
    }
    
    private String cutoffId(String log) {
        int idx = 0;
        while (log.charAt(idx) != ' ') idx++;
        idx++;
        
        String res = "";
        for (int i = idx; i < log.length(); i++) {
            res += log.charAt(i);
        }
        return res;
    }
    
    public String[] reorderLogFiles(String[] logs) {
        
        // move digit logs to the back
        int back = logs.length - 1;
        for (int i = logs.length - 1; i > -1; i--) {
            if(isDigLog(logs[i])) {
                String temp = logs[back];
                logs[back] = logs[i];
                logs[i] = temp;
                back--;
            }
        }
        
        Arrays.sort(logs, 0, back + 1, (String l1, String l2) -> {
            int comp = cutoffId(l1).compareTo(cutoffId(l2));
            if (comp == 0) {
                return l1.compareTo(l2);
            }
            return comp;
        });
        return logs;
    }
}
