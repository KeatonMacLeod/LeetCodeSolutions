class Solution {
    public int calPoints(String[] ops) {
        int points = 0;
        LinkedList<Integer> list = new LinkedList();
        int temp = 0;
        for (int a=0; a<ops.length; a++) {
            if (ops[a].equals("C")) {
                points -= list.removeLast();
            }
            else if (ops[a].equals("D")) {
                temp = list.peekLast() * 2;
                points += temp;
                list.addLast(temp);
            }
            else if (ops[a].equals("+")) {
                temp = list.peekLast() + list.get(list.size()-2);
                points += temp;
                list.addLast(temp);
            }
            else {
                temp = Integer.parseInt(ops[a]);
                points += temp;
                list.addLast(temp);
            }
        }
        return points;
    }
}
