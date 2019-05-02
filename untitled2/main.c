#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "lib\conio.h"
#include "input.h"
#if defined(_WIN32) || defined(_WIN64)
#define OS_WINDOWS
#endif
#define CYCLE .5
#define JUMP_HEIGHT 3
#define WIDTH 150
#define HEIGHT 12

void updatePlayer(States state, int height);
void clear();

int main() {
    States state = Idle;
    ActionStates actionState = OutOfAction;
    Bool gameOver = False;


    clock_t gameTime;
    clock_t actionTime;
    clock_t time = clock();
    int jumpHeight = 0;

    while(gameOver == False){
        gameTime = clock();
        if((double)(gameTime - time)/CLOCKS_PER_SEC > CYCLE){
            time = gameTime;
            int cycles = (int)(gameTime - actionTime)/(CLOCKS_PER_SEC*2);
            if(cycles <= 3){
                jumpHeight = cycles;
            }
            else{
                jumpHeight = 6 - cycles;
            }
            updatePlayer(state, cycles);
        }
        if(actionTime == NULL && ((double)(gameTime - actionTime)/CLOCKS_PER_SEC > CYCLE*JUMP_HEIGHT*2)){
            state = checkInput(actionState);
        }

        switch(state){
            case Idle:
                break;
            case Jump:
                actionTime = clock();
                actionState = InAction;
                //Jump();
                break;
            case Duck:
                actionTime = clock();
                actionState = InAction;
                //Duck();
                break;
            case GameOver:
                gameOver = True;
                break;
            default:
                break;
        }
    }
}


void updatePlayer(States state, int height){
    clear();
    for(int i = 0; i < WIDTH; i++){
        printf("#");
    }
    printf("\n");
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            if(j == 2) {
                if(j == (HEIGHT - 1) - height){
                    printf(0);
                }
            }
        }
        printf("\n");
    }
    for(int i = 0; i < WIDTH; i++){
        printf("#");
    }
    printf("\n");
}

void clear(){
#ifdef OS_Windows
    system("cls");
#else
    system("clear");
#endif
}