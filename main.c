#include <stdio.h>
#include <stdlib.h>

#define and &&
#define or ||

char indexs[10] = {'0','1','2','3','4','5','6','7','8','9'};
int gameWLCondi(){
    // In Rows
    if((indexs[1] == indexs[2] and indexs[2] == indexs[3]) or (indexs[4] == indexs[5] and indexs[5] == indexs[6]) or (indexs[7] == indexs[8] and indexs[8] == indexs[9])){
        return 1;
    }
    // Column
    else if((indexs[1] == indexs[4] and indexs[4] == indexs[7]) or (indexs[2] == indexs[5] and indexs[5] == indexs[8]) or (indexs[3] == indexs[6] and indexs[6] == indexs[9])){
        return 1;
    }
    // Diagonal
    else if((indexs[1] == indexs[5] and indexs[5] == indexs[9]) or (indexs[3] == indexs[5] and indexs[5] == indexs[7])){
        return 1;
    }
    else
        return 0;
}

void board(){
    printf("   |   |   \n");
    printf(" %c | %c | %c \n",indexs[1],indexs[2],indexs[3]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n",indexs[4],indexs[5],indexs[6]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n",indexs[7],indexs[8],indexs[9]);
    printf("   |   |   \n");
}
int game(){
    int running = 1,choice,count = 0;
    int player =1;
    char mark;

    while (running){
        if(player % 2)
            player = 2;
        else
            player = 1;

        if(player == 1)
            mark = 'X';
        else
            mark = 'O';

        printf("Enter any Number: ");
        scanf("%d", &choice);

        if(choice > 9){
            printf("Please Enter Number Between 1 - 9 \n");
        }
        else{
            indexs[choice] = mark;
            count += 1;
            if(count > 9){
                printf("The game is Draw \n");
                break;
            }

            board();
            if(gameWLCondi() == 1){
                printf("\n");
                printf("\n");
                printf("%c Player wins the game \n", mark);
                break;
            }
        }
    }
    return 0;
}

int main(){

    game();
    return 0;

}
