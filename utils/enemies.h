#ifndef ENEMIES
#define ENEMIES

#include "raylib.h"


typedef struct {
    float speed;
    float radius;
    Vector2 position;
    struct Enemy *next;
} Enemy;

typedef struct {
    Enemy *head;
    Enemy *tail;
} EnemyList;

Enemy *spawnEnemy();
void moveEnemyTowardsPlayer(Enemy *enemy, Vector2 playerPos);
#endif
