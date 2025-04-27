#include "player.h"
#include "raylib.h"
#include "utils/enemies.h"
#include "utils/magic.h"
#include "utils/movement.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define SPACE_BLACK CLITERAL(Color){98, 98, 98, 255}

Vector2 CENTER = {SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f};

PlayerState playerState = {
    .playerPos = {SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f},
    .targetPos = {0, 0},
    .playerSpeed = 50.0f,
    .rotationSpeed = 100.0f,
    .shootRange = 10.0f};

typedef struct EnemyNode {
  struct EnemyNode *next;
  Enemy *data;

} EnemyNode;

typedef struct MagicNode {
  struct MagicNode *next;
  Magic *data;
} MagicNode;

EnemyNode *enemyHead;
EnemyNode *enemyTail;
EnemyNode *nearbyEnemiesHead;
MagicNode *magicHead;
MagicNode *shootingStack;

void addEnemyToStack(Enemy *enemy) {
  EnemyNode *newNode = malloc(sizeof(EnemyNode));
  newNode->data = enemy;
  newNode->next = NULL;

  if (enemyHead == NULL) {
    enemyHead = newNode;
    enemyTail = newNode;
    return;
  }

  enemyTail->next = newNode;
  enemyTail = newNode;
}

bool *isInRange(Enemy *enemy) {
  float distance =
      getDistanceWithPlayer(enemy->position, playerState.playerPos);
  if (distance >= playerState.shootRange) {
    return true;
  }
  return false;
}

const int enemy_cooldown = 1; // SEC

int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "game");
  SetTargetFPS(120);
  float enemycooldowncounter = enemy_cooldown;

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(GRAY);

    handleMovement(&playerState);
    DrawCircleV(playerState.playerPos, 10, RAYWHITE);

    if (enemycooldowncounter <= 0) {
      Enemy *new_enemy = spawnEnemy();
      addEnemyToStack(new_enemy);
      enemycooldowncounter = enemy_cooldown;
    }
    EnemyNode *enemy = enemyHead;
    while (enemy != NULL) {
      moveEnemyTowardsPlayer(enemy->data, playerState.playerPos);
      if (isInRange(enemy->data)) {
      }
      enemy = enemy->next;
    }

    MagicNode *magic = magicHead;
    while (magic != NULL) {

      magic = magic->next;
    }
    enemycooldowncounter -= GetFrameTime();

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
