#include<stdio.h>

#define ll long long int
#define MAXn (110)
#define mod 1000000007

double a, b;
int t, p = 3;

double Sum(double, double);
double Sub(double, double);
double Mul(double, double);
double Div(double, double);

void setPrecision() {
    printf("Choose the precision for ur answers : \n");
    scanf("%d", &p);
    printf("Done!\n\n");
}

void getInput() {
    printf("Choose a command: \n");
    scanf("%d",&t);
    if (t == 1) {
        printf("Sum \"a + b\" enter a & b : \n");
        scanf("%lf%lf", &a, &b);
        printf("Answer : %.*lf\n\n", p, Sum(a, b));
    }
    else if (t == 2) {
        printf("Subtraction \"a - b\" enter a & b : \n");
        scanf("%lf%lf", &a, &b);
        printf("Answer : %.*lf\n\n", p, Sub(a, b));
    }
    else if (t == 3) {
        printf("Multiply \"a * b\" enter a & b : \n");
        scanf("%lf%lf", &a, &b);
        printf("Answer : %.*lf\n\n", p, Mul(a, b));
    }
    else if (t == 4) {
        printf("Division \"a / b\" enter a & b (b != 0): \n");
        scanf("%lf%lf", &a, &b);
        if (!b) {
            printf("error: \"b\" should be non-zero!\n\n");
            return;
        }
        printf("Answer : %.*lf\n\n", p, Div(a, b));
    }
    else if (t == 5) {
        setPrecision();
    }
    else {
        printf("error: \"command number\" should be between 1 and 5\n\n");
   }
}

int main()
{
    printf("Commands List :\n1: Sum\n2: Subtraction\n3: Multiply\n4: Divide\n5: Change precision\n\n");

    getInput();
    while(getchar() != EOF) {
        getInput();
    }
}

double Sum(double a, double b) {
    return (a + b);
}

double Sub(double a, double b) {
    return (a - b);
}

double Mul(double a, double b) {
    return (a * b);
}

double Div(double a, double b) {
    return (a / b);
}
