class Solution {
    private String removePunc(String s) {
        // Assumes string is lowercase
        
        String res = "";
        for (char c : s.toCharArray()) {
            if ((int) 'a' <= (int) c && (int) c <= (int) 'z') { 
                res += c;
            } else {
                break;
            }
        }
        return res;
    }
    
    public String mostCommonWord(String paragraph, String[] banned) {
        Map<String, Integer> freqs = new HashMap<> ();
        
        Set<String> bannedSet = new HashSet<String> ();
        for (String word : banned) bannedSet.add(word);
        
        String[] words = paragraph.split(" ");
        String substr;
        
        outerloop:
        for (String word : words) {
            word = word.toLowerCase();
            word = removePunc(word);
            
            if (bannedSet.contains(word)) continue;
            
            if (!freqs.containsKey(word)) freqs.put(word, 0);
            freqs.put(word, freqs.get(word) + 1);
        }
        
        int max = -1;
        String result = "";
        for (String key : freqs.keySet()) {
            int val = freqs.get(key);
            if (val > max) {
                max = val;
                result = key;
            }
        }
        
        return result;
    }
}
