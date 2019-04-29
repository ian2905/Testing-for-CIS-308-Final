#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "lib\conio.h"
#include "input.h"
#if defined(_WIN32) || defined(_WIN64)
#define OS_WINDOWS
#endif
#define CYCLE .5
#define JUMP_HEIGHT 3

void updatePlayer();

int main() {
    States state = Idle;
    ActionStates actionState = OutOfAction;
    Bool gameOver = False;


    clock_t gameTime;
    clock_t actionTime;
    clock_t time = clock();

    while(gameOver == False){
        gameTime = clock();
        if((gameTime - time)/CLOCKS_PER_SEC > CYCLE){
            time = gameTime;
            updatePlayer();
        }
        if(actionTime != NULL && ((gameTime - actionTime)/CLOCKS_PER_SEC > CYCLE*JUMP_HEIGHT*2))
        state = checkInput(actionState);

        switch(state){
            case Idle:
                break;
            case Jump:
                actionTime = clock();
                actionState = InAction;
                Jump();
                break;
            case Duck:
                actionTime = clock();
                actionState = InAction;
                Duck();
                break;
            case GameOver:
                gameOver = True;
                break;
            default:
                break;
        }
    }
}


void updatePlayer(){

}