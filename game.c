
#include "player.h"
#include "raylib.h"
#include "utils/enemies.h"
#include "utils/movement.h"

#define SPACE_BLACK CLITERAL(Color){14, 15, 20, 255}

Vector2 CENTER = {SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f};

PlayerState playerState = {
    .playerPos = {SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f},
    .targetPos = {0, 0},
    .playerSpeed = 50.0f,
    .rotationSpeed = 100.0f};

const int enemy_cooldown = 1000000; // SEC

int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "game");
  SetTargetFPS(60);
  float enemycooldowncounter = enemy_cooldown;

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(GRAY);

    handleMovement(&playerState);
    DrawCircleV(playerState.playerPos, 10, RAYWHITE);

    if (enemycooldowncounter <= 0) {
      spawnEnemy();
      enemycooldowncounter = enemy_cooldown;
    }

    enemycooldowncounter -= 1.0f / GetFPS();

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
