#include <stdio.h>
#include <string.h>
#include <math.h>

double prevAns;
void floatInput(float *firstNum, float *secondNum){
    char input[30];
    printf("Enter the first number: ");
    scanf("%s", input);
    if(strstr(input, "prev")/* && &prevAns != NULL*/) *firstNum = (float)prevAns;
    else *firstNum = atof(input);
    printf("\nEnter the second number: ");
    scanf("%f", secondNum);
}
void sum(){
    float firstNum, secondNum;
    floatInput(&firstNum, &secondNum);
    float answer = firstNum + secondNum;
    if((int)answer == answer) printf("The sum of the provided numbers is: %d", (int)answer);
    else printf("The sum of the provided numbers is: %.2f", firstNum + secondNum);
    prevAns = (double) answer;
}
void subt(){
    float firstNum, secondNum;
    floatInput(&firstNum, &secondNum);
    float answer = firstNum  - secondNum;
    if((int)answer == answer) printf("The second number subtracted from the first number is: %d", (int)answer);
    else printf("The second number subtracted from the first number is: %.2f", firstNum - secondNum);
    prevAns = (double) answer;
}
void mult(){
    float firstNum, secondNum;
    floatInput(&firstNum, &secondNum);
    float answer = firstNum  * secondNum;
    if((int)answer == answer) printf("The product of the first and second number is: %d", (int)answer);
    else printf("The product of the first and second number is: %.2f", firstNum * secondNum);
    prevAns = (double) answer;
}
void div(){
    float firstNum, secondNum;
    floatInput(&firstNum, &secondNum);
    float answer = firstNum / secondNum;
    if((int)answer == answer) printf("The fraction of the provided numbers is: %d", (int)answer);
    else printf("The fraction of the provided numbers is: %.2f", answer);
    prevAns = (double) answer;
}
void mod(){
    int firstNum;
    char input[30];
    printf("Enter the first number: ");
    scanf("%s", input);
    if(strstr(input, "prev")/* && &prevAns != NULL*/) firstNum = (int)prevAns;
    else firstNum = (int)atof(input); //did this to awoid warnings
    int secondNum;
    printf("\nEnter the second number: ");
    scanf("%d", &secondNum);
    int answer = firstNum % secondNum;
    printf("The modulus of the provided numbers is: %d", answer);
    prevAns = (double) answer;
}
void localPow(){
    float firstNum, secondNum;
    floatInput(&firstNum, &secondNum);
    double answer = pow(firstNum, secondNum);
    if((int)answer == answer) printf("The power of the provided numbers is: %d", (int)answer);
    else printf("The power of the provided numbers is: %.2lf", answer);
    prevAns = (double) answer;
}
void sgn(){
    float num;
    printf("Enter the number: ");
    scanf("%f", &num);
    printf("The sign of your number is ");
    if(num > 0) {
        printf("1\n");
        prevAns = 1;
    }
    else if(num < 0) {
        printf("-1\n");
        prevAns = -1;
    }
    else {
        printf("0\n");
        prevAns = 0;
    }
}
void inputHandler(){
    printf("Enter the desired operation:\n");
    char operation[4];
    const char list[] = "Currently the valid inputs are: sum|+, subt|-, mult|*, div|/, mod|%, pow|^, sign|sgn\n";
    scanf("%s", operation);
    if(strstr(operation, "list")) {
        printf("%s", list);
        inputHandler();
        return;
    }
    else if(strstr(operation, "sum") || strstr(operation, "+")) sum();
    else if(strstr(operation, "subt")|| strstr(operation, "-")) subt();
    else if(strstr(operation, "mult")|| strstr(operation, "*")) mult();
    else if(strstr(operation, "div") || strstr(operation, "/")) div();
    else if(strstr(operation, "mod") || strstr(operation, "%")) mod();
    else if(strstr(operation, "pow") || strstr(operation, "^")) localPow();
    else if(strstr(operation, "sign") || strstr(operation, "sgn")) sgn();
    else {
        printf("Invalid input!\n");
        inputHandler();
    }
    printf("\nWould you like to calculate again? [y/n] ");
    char input;
    scanf(" %c", &input);
    if(input == 'y') {
        printf("\nTo use the previously calculated value use the word \"prev\" as the first number\n");
        inputHandler();
    }

}
int main(){
    printf("Welcome to My Calculator!\n");
    printf("If you would like to see a list of options enter \"list\"\n");
    inputHandler();
    printf("Thank You for using My calculator!");
    return 0;
}