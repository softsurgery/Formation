import java.util.Random;
import java.util.Scanner;

class Solution {
    public static void main(String[] args) {
        int score = 0;
        Random random = new Random();
        Scanner scanner = new Scanner(System.in);
        
        for (int i = 0; i < 10; i++) {
            int a = random.nextInt(10) + 1;
            int b = random.nextInt(10) + 1;
            int rep = a * b;
            
            System.out.print(a + " x " + b + " = ?");
            int sugg = scanner.nextInt();
            
            if (rep == sugg) {
                score++;
            } else {
                score--;
            }
        }
        System.out.println("Your Score = " + score);
        scanner.close();
    }
}
