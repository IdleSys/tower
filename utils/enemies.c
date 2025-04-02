#include "../player.h"
#include "raylib.h"

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

void spawnEnemy() { DrawCircleV(getRandomEdgePosition(), 3, BLACK); }
