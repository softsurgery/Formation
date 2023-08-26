class Solution {
    public static void main(String[] args) {
        int s = 0;
        for (int i = 1; i <= 1001; i++) s += i;
        for (int i = 2; i <= 100; i++) s += i;
        System.out.println("Resultat ="+s);
    }
}