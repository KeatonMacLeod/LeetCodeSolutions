class Solution {
    public String complexNumberMultiply(String one, String two) {
        String[] a = one.split("[+i]");
        String[] b = two.split("[+i]");

        int a1 = Integer.parseInt(a[0]);
        int a2 = Integer.parseInt(a[1]);
        int b1 = Integer.parseInt(b[0]);
        int b2 = Integer.parseInt(b[1]);
        
        int firstTerm = a1 * b1;
        int secondTerm = a1 * b2 + a2 * b1;
        int thirdTerm = -(a2 * b2);
        return firstTerm + thirdTerm + "+" + secondTerm + "i";
    }
}
