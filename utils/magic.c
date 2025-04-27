#include "magic.h"
#include "../player.h"
#include "raylib.h"
#include <stdlib.h>

void destroyMagic(Magic magic) {
  UnloadTexture(magic.shootTexture);
  UnloadTexture(magic.middleTexture);
  UnloadTexture(magic.hitTexture);
}

void handleMagicShoot(Magic *magic_stack[], PlayerState player,
                      int magic_count) {
  for (int i = 0; i < magic_count; i++) {
    Magic *magic = magic_stack[i];
    if (magic->cooldownCounter == 0) {
      DrawTextureV(magic->shootTexture, player.playerPos, WHITE);
      magic->cooldownCounter = magic->cooldown;
      magic->position = player.playerPos;
    }
    magic->cooldownCounter -= 1.f / GetFPS();
  }
}

Magic *createMagic(char *title, char *description, float speed, float cooldown,
                   float cooldownCounter) {
  // TODO: add shoot texture after functionality is complete
  Magic *magic = malloc(sizeof(Magic));
  magic->title = title;
  magic->description = description;
  magic->speed = speed;
  magic->cooldown = cooldown;
  magic->cooldownCounter = cooldownCounter;
  return magic;
}

void handleShootMagic(Magic *magic, int is_hit) {
  {
    float targetX = magic->speed * GetFrameTime();
    float targetY = magic->speed * GetFrameTime();

    magic->position.x += targetX;
    magic->position.y += targetY;
  }

  if (is_hit == 0) {
    DrawTextureV(magic->middleTexture, magic->position, WHITE);
  } else {
    DrawTextureV(magic->hitTexture, magic->position, WHITE);
  }
}
