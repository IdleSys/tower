#include "../player.h"

void handleMovement(PlayerState *player_state) {

  Vector2 targetpos = player_state->targetPos;

  if (IsKeyDown(KEY_W)) {
    targetpos.y -= player_state->playerSpeed * GetFrameTime();
  }
  if (IsKeyDown(KEY_D)) {
    targetpos.x += player_state->playerSpeed * GetFrameTime();
  }
  if (IsKeyDown(KEY_S)) {
    targetpos.y += player_state->playerSpeed * GetFrameTime();
  }
  if (IsKeyDown(KEY_A)) {
    targetpos.x -= player_state->playerSpeed * GetFrameTime();
  }

  player_state->playerPos.x += targetpos.x;
  player_state->playerPos.y += targetpos.y;

  targetpos = (Vector2){0, 0};
}
