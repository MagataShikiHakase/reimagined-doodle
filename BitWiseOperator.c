#include <stdio.h>

#define BITS 8

void convertDecimalToBinary(int num, char arr[]){
    int arrDigit[BITS];
    for(int i = 0; i < BITS; i++){
        arrDigit[i] = num >> i;
        arrDigit[i] &= 1;
        arr[BITS - i - 1] = (char)(arrDigit[i] + '0'); 
    }
}

void showResult(char arr1[], char arr2[], char arr3[], char op){
    printf("In %d-bit base 2...\n", BITS);
    printf("%s", arr1);
    printf("\n%c\n", op);
    printf("%s", arr2);
    printf("\n");
    for(int i = 0; i < BITS; i++)
        printf("=");
    printf("\n");
    printf("%s", arr3);
}

void showResult2(char arr1[], char arr3[], char op[], int x){
    printf("In %d-bit base 2...\n", BITS);
    printf("%s", arr1);
    printf("  %s  %d\n", op, x);
    printf("%s", arr3);
}

void showResult3(char arr1[], char arr3[], char op[]){
    printf("In %d-bit base 2...\n", BITS);
    printf("%c%s\n", op[0], arr1);
    for(int i = 0; i < BITS + 1; i++)
        printf("=");
    printf("\n %s", arr3);
}

int main(){
    char operator[3];
    char rightBit[BITS + 1] = {};
    char leftBit[BITS + 1] = {};
    char ans[BITS + 1] = {};
    int right, left;
    scanf("%d %s %d", &left, operator, &right);

    while(0 > right || right > 255 || 0 > left || left > 255){
        printf("Try again\n");
        scanf("%d %s %d", &left, operator, &right);
    }
    
    convertDecimalToBinary(left, leftBit);
    convertDecimalToBinary(right, rightBit);

    switch(operator[0]){
        case '&':
            printf("In base 10...\n%d %c %d = %d\n\n", left, operator[0], right, left & right);
            for(int i = 0; i < BITS; i++)
                ans[i] = (rightBit[i] - '0') & (leftBit[i] - '0') + '0';
            showResult(leftBit, rightBit, ans, operator[0]);
            break;
        case '^':
            printf("In base 10...\n%d %c %d = %d\n\n", left, operator[0], right, left ^ right);
            for(int i = 0; i < BITS; i++)
                ans[i] = (rightBit[i] - '0') ^ (leftBit[i] - '0') + '0';
            showResult(leftBit, rightBit, ans, operator[0]);
            break;
        case '|':
            printf("In base 10...\n%d %c %d = %d\n\n", left, operator[0], right, left | right);
            for(int i = 0; i < BITS; i++)
                ans[i] = (rightBit[i] - '0') | (leftBit[i] - '0') + '0';
            showResult(leftBit, rightBit, ans, operator[0]);
            break;
        case '>':
            printf("In base 10...\n%d %s %d = %d\n\n", left, operator, right, left >> right);
            if(right >= 8){
                for(int i = 0; i < BITS; i++)
                    ans[i] = '0';
            }
            else{
                for(int i = 0; i < right; i++)
                    ans[i] = '0';
                for(int i = 0; i < BITS - right; i++)
                    ans[right + i] = leftBit[i];
            }
            showResult2(leftBit, ans, operator, right);
            break;
        case '<':
            printf("In base 10...\n%d %s %d = %d\n\n", left, operator, right, left << right);
            if(right >= 8){
                for(int i = 0; i < BITS; i++)
                    ans[i] = '0';
            }
            else{
                for(int i = 0; i < BITS - right; i++)
                    ans[i] = leftBit[right + i];
                for(int i = 0; i < right; i++)
                    ans[BITS - right + i] = '0';
            }
            showResult2(leftBit, ans, operator, right);
            break;
        case '~':
            printf("In base 10...\n%s%d = %d\n\n", operator, left, ~left);
            for(int i = 0; i < BITS; i++)
                ans[i] = ~(leftBit[i] - '0') + '0' + 2;
            showResult3(leftBit, ans, operator);
            break;
            
        default:
            printf("Operator %s is invalid", operator);
    }
    return 0;
}