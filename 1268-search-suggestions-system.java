class Solution {
    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        Arrays.sort(products);
        
        List<List<String>> res = new ArrayList<> ();
        List<String> matches;
        String cur = "";
            
        for (char c : searchWord.toCharArray()) {
            matches = new ArrayList<> ();
            cur += c;
            
            // System.out.println(cur);
            for (String product : products) {
                if (product.startsWith(cur) && matches.size() < 3) {
                    matches.add(product);
                }
            }
            
            res.add(matches);
        }
        
        return res;
    }
}
