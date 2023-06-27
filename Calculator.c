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
    scanf("%s", input);
    if(strstr(input, "prev")/* && &prevAns != NULL*/) *secondNum = (float)prevAns;
    else *secondNum = atof(input);
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
    if(strstr(input, "prev")) firstNum = (int)prevAns;
    else firstNum = (int)atof(input); //did this to awoid warnings
    int secondNum;
    printf("\nEnter the second number: ");
    scanf("%s", input);
    if(strstr(input, "prev")) secondNum = (int)prevAns;
    else secondNum = (int)atof(input);
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
    char input[30];
    printf("Enter the number: ");
    scanf("%s", input);
    if(strstr(input, "prev")) num = (float)prevAns;
    else num = atof(input); //did this to awoid warnings
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
void localSin(){
    char input1[30];
    printf("What type of input do you want to give? [rad/deg] ");
    scanf("%s", input1);
    char input2[30];
    float num;
    printf("\nEnter your number: ");
    scanf("%s", input2);
    if(strstr(input2, "prev")) num = (float)prevAns;
    else num = atof(input2);
    if(strstr(input1, "deg")) num = num/180*acosl(-1);
    double answer = sin(num);
    printf("The sin of the provided number is: %f", answer);
    prevAns = answer;
}
void inputHandler(){
    printf("Enter the desired operation:\n");
    char operation[4];
    const char list[] = "Currently the valid inputs are: sum|+, subt|-, mult|*, div|/, mod|%, pow|^, sign|sgn, sin|sn\n";
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
    else if(strstr(operation, "sin") || strstr(operation, "sn")) localSin();
    else {
        printf("Invalid input!\n");
        inputHandler();
        return;
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
    printf("Thank You for using My calculator!\n");
    getchar();
    getchar();
    return 0;
}