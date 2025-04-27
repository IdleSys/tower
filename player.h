#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

extern Vector2 CENTER;

#define SCREEN_WIDTH (850)
#define SCREEN_HEIGHT (450)

typedef struct {
    Vector2 playerPos;
    Vector2 targetPos;
    float playerSpeed;
    float playerAngle;
    float rotationSpeed;
    float shootRange;
} PlayerState;

#endif
