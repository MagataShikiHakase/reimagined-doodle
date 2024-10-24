#include <stdio.h>
#include <time.h>   //to use time(0);
#include <stdlib.h> //to use rand()%;
#include <stdbool.h>//to use bool

#define ROW 5
#define COLUM 5

void fillBingo(int arr[][COLUM]){
    for(int i = 0; i < COLUM; i++){
        for(int j = 0; j < COLUM; j++){
            arr[i][j] = (rand() % 15 + 1) + (i * 15);
            int iteration = 0;
            while(iteration < j){
                if(arr[i][j] == arr[i][iteration]){
                    arr[i][j] = (rand() % 15 + 1) + (i * 15);
                    iteration = 0;
                }
                else
                    iteration++;
            }
        }
    }
    arr[ROW / 2][COLUM / 2] = 0;
}

void printBingo(int arr[][COLUM]){
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COLUM; j++)
            printf("%d\t", arr[j][i]);
        printf("\n");
    }
}

void printBingoToFile(int arr[][COLUM], FILE *f){
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COLUM; j++)
            fprintf(f, "%d\t", arr[j][i]);
        fprintf(f, "\n");
    }
    fprintf(f, "------------------------------------\n");
}

int selectingNumber(int arr[], int iteration){
    int num = rand() % 75 + 1, counter = 0;
    char letter;
    while(iteration > counter){
        if(arr[counter] == num){
            num = rand() % 75 + 1;
            counter = 0;
        }
        else
            counter++;
    }
    arr[iteration] = num;

    if(1 <= num && num <= 15)
        letter = 'B';
    else if(16 <= num && num <= 30)
        letter = 'I';
    else if(31 <= num && num <= 45)
        letter = 'N';
    else if(46 <= num && num <= 60)
        letter = 'G';
    else if(61 <= num && num <= 75)
        letter = 'o';
    printf("Letter: %c  Number: %d\nDoes your bingo card has this number?", letter, num);
    return num;
}

bool existInBingo(int arr[][COLUM], int num){
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COLUM; j++){
            if(arr[i][j] == num){
                arr[i][j] = 0;
                return true;
            }
        }
    }
    return false;
}

bool checkRow(int arr[][COLUM]){
    for(int i = 0; i < ROW; i++){
        int sum = 0;
        for(int j = 0; j < COLUM; j++){
            sum += arr[j][i];
        }
        if(sum == 0)
            return true;
    }
    return false;
}

bool checkColum(int arr[][COLUM]){
    for(int i = 0; i < ROW; i++){
        int sum = 0;
        for(int j = 0; j < COLUM; j++){
            sum += arr[i][j];
        }
        if(sum == 0)
            return true;
    }
    return false;
}

bool checkDiagonal(int arr[][COLUM]){
    int sum = 0;
    for(int i = 0; i < COLUM; i++){
        sum += arr[i][i];
    }
    if(sum == 0)
        return true;
    sum = 0;
    for(int i = 0; i < COLUM; i++){
        sum += arr[i][ROW - i - 1];
    }
    if(sum == 0)
        return true;
    return false;
}

int main(){
    srand(time(0));
    int bingoCard[ROW][COLUM], arr[75], loop = 0, i = 0;
    char response[100];
    bool row = false, colum = false, diagonal = false;
    fillBingo(bingoCard);
    printBingo(bingoCard);
    
    

    FILE *file = fopen("BINGO.card", "w");
    printBingoToFile(bingoCard, file);
    

    while(loop < 75 && !row && !colum && !diagonal){
        int num = selectingNumber(arr, loop);
        scanf("%s", response);
        if(response[0] != 'Y' && response[0] != 'y'){
            printBingo(bingoCard);
            loop++;
        }
        else{
            if(existInBingo(bingoCard, num) == false)
                printf("You're cheating\n");
            else{
                row = checkRow(bingoCard);
                colum = checkColum(bingoCard);
                diagonal = checkDiagonal(bingoCard);
            }
            loop++;
            printBingo(bingoCard);
        }
    }
    if(row == true && colum == true && diagonal == true)
        printf("Row, colum, and diagonal are filled!");
    else if(row == true && colum == true)
        printf("Row and colum are filled!");
    else if(row == true && diagonal == true)
        printf("Row and diagonal are filled!");
    else if(diagonal == true && colum == true)
        printf("Row and colum are filled!");
    else if(row == true)
        printf("Row is filled!");
    else if(colum == true)
        printf("Colum is filled!");
    else if(diagonal == true)
        printf("Diagonal is filled!");
        
    
    printBingoToFile(bingoCard, file);
    fprintf(file, "\n");
    while(i < loop){
        fprintf(file, "%d ", arr[i]);
        if((i + 1) % 10 == 0)
            fprintf(file, "\n");
        i++;
    }

    fclose(file);
    return 0;
}
