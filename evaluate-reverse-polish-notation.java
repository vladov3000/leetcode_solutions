class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> s = new Stack<> ();
        for (String token : tokens) {
            int op1 = s.isEmpty() ? 0 : s.pop();
            int op2 = s.isEmpty() ? 0 : s.pop();

            if (token.equals("+")) s.push(op2 + op1);
            else if (token.equals("-")) s.push(op2 - op1);
            else if (token.equals("*")) s.push(op2 * op1);
            else if (token.equals("/")) s.push(op2 / op1);
            else {
                s.push(op2);
                s.push(op1);
                s.push(Integer.parseInt(token));
            }
            // System.out.println(Arrays.toString(s.toArray()));
        }
        
        return s.pop();
    }
}
