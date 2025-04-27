#include "enemies.h"
#include "../player.h"
#include "raylib.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

Vector2 getRandomEdgePosition() {
  Vector2 position = {0};

  int edge = GetRandomValue(0, 3);

  // Edge 0 = top, 1 = right, 2 = bottom, 3 = left
  switch (edge) {
  case 0:
    position.x = GetRandomValue(0, SCREEN_WIDTH);
    position.y = 0;
    break;
  case 1:
    position.x = SCREEN_WIDTH;
    position.y = GetRandomValue(0, SCREEN_HEIGHT);
    break;
  case 2:
    position.x = GetRandomValue(0, SCREEN_WIDTH);
    position.y = SCREEN_HEIGHT;
    break;
  case 3:
    position.x = 0;
    position.y = GetRandomValue(0, SCREEN_HEIGHT);
    break;
  }

  return position;
}

Enemy *spawnEnemy() {
  Enemy *enemy = malloc(sizeof(Enemy));
  if (!enemy) {
    fprintf(stderr, "Failed to allocate memory for enemy\n");
    return NULL;
  }

  enemy->position = getRandomEdgePosition();
  enemy->speed = 10;
  enemy->radius = 5;

  return enemy;
}

void moveEnemyTowardsPlayer(Enemy *enemy, Vector2 playerPos) {
  Vector2 direction = {playerPos.x - enemy->position.x,
                       playerPos.y - enemy->position.y};
  float distance = sqrtf(direction.x * direction.x + direction.y * direction.y);

  if (distance != 0) {
    direction.x /= distance;
    direction.y /= distance;

    enemy->position.x += direction.x * enemy->speed * GetFrameTime();
    enemy->position.y += direction.y * enemy->speed * GetFrameTime();
  }

  DrawCircleV(enemy->position, 3, BLACK);
}

float getDistanceWithPlayer(Vector2 enemyPos, Vector2 playerPos) {
  return fabs(sqrtf(pow(enemyPos.x - playerPos.x, 2) +
                    pow(enemyPos.y - playerPos.y, 2)));
}
