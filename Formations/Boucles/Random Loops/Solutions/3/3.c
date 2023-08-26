#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int score = 0;
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        int a = rand() % 10 + 1;
        int b = rand() % 10 + 1;
        int rep = a * b;

        printf("%d x %d = ? ", a, b);
        int sugg;
        scanf("%d", &sugg);

        if (rep == sugg) {
            score++;
        } else {
            score--;
        }
    }
    printf("Your Score = %d\n", score);
    return 0;
}
