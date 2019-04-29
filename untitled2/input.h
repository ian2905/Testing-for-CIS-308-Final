//
// Created by clousian000 on 4/29/2019.
//

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "lib\conio.h"

#ifndef UNTITLED2_INPUT_H
#define UNTITLED2_INPUT_H

typedef enum States{
    Idle,
    Jump,
    Duck,
    GameOver
}States;

typedef enum ActionStates{
    InAction,
    OutOfAction
}ActionStates;

typedef enum Bool{
    True,
    False
}Bool;

States checkInput(ActionStates actionState);

#endif //UNTITLED2_INPUT_H
