#include <stdio.h>
#include <string.h>
void floatInput(float *firstNum, float *secondNum){
    printf("Enter the first number: ");
    scanf("%f", firstNum);
    printf("\nEnter the second number: ");
    scanf("%f", secondNum);
}
void sum(){
    float firstNum, secondNum;
    floatInput(&firstNum, &secondNum);
    float answer = firstNum + secondNum;
    if((int)answer == answer) printf("The sum of the provided numbers is: %d", (int)answer);
    else printf("The sum of the provided numbers is: %.2f", firstNum + secondNum);
}
void subt(){
    float firstNum, secondNum;
    floatInput(&firstNum, &secondNum);
    float answer = firstNum  - secondNum;
    if((int)answer == answer) printf("The second number subtracted from the first number is: %d", (int)answer);
    else printf("The second number subtracted from the first number is: %.2f", firstNum - secondNum);
}
void mult(){
    float firstNum, secondNum;
    floatInput(&firstNum, &secondNum);
    float answer = firstNum  * secondNum;
    if((int)answer == answer) printf("The product of the first and second number is: %d", (int)answer);
    else printf("The product of the first and second number is: %.2f", firstNum * secondNum);
}
void div(){
    float firstNum, secondNum;
    floatInput(&firstNum, &secondNum);
    float answer = firstNum / secondNum;
    if((int)answer == answer) printf("The fraction of the provided numbers is: %d", (int)answer);
    else printf("The fraction of the provided numbers is: %.2f", answer);
}
void mod(){
    int firstNum;
    printf("Enter the first number: ");
    scanf("%d", &firstNum);
    int secondNum;
    printf("\nEnter the second number: ");
    scanf("%d", &secondNum);
    int answer = firstNum % secondNum;
    printf("The modulus of the provided numbers is: %d", answer);
}
void inputHandler(){
    printf("Enter the desired operation:\n");
    char operation[4];
    const char list[] = "The currently valid inputs are: sum|+, subt|-, mult|*, div|/, mod|%\n";
    scanf("%s", operation);
    if(strstr(operation, "list")) {
        printf("%s", list);
        inputHandler();
    }
    else if(strstr(operation, "sum") || strstr(operation, "+")) sum();
    else if(strstr(operation, "subt")|| strstr(operation, "-")) subt();
    else if(strstr(operation, "mult")|| strstr(operation, "*")) mult();
    else if(strstr(operation, "div") || strstr(operation, "/")) div();
    else if(strstr(operation, "mod") || strstr(operation, "%")) mod();
    else {
        printf("Invalid input!\n");
        inputHandler();
    }

}
int main(){
    printf("Welcome to My Calculator!\n");
    printf("If you would like to see a list of options enter \"list\"\n");
    inputHandler();
    return 0;
}