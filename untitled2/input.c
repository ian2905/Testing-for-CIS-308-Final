//
// Created by clousian000 on 4/29/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"


States checkInput(ActionStates actionState){
    if(c_kbhit()){
        char input = (char)c_getch();
        if(actionState == OutOfAction){
            if(input == 'w' || input == 'W'){
                return Jump;
            }
            else if(input == 's' || input == 'S'){
                return Duck;
            }
            else{
                return Idle;
            }
        }
    }
}
