#include "magic.h"
#include "../player.h"
#include "raylib.h"

Magic createMagic(char *title, char *description, enum MagicType magic_type,
                  const char *hit_texture, const char *middle_texture,
                  const char *shoot_texture, float speed, float cooldown) {

  Texture loaded_hit_texture = LoadTexture(hit_texture);
  Texture loaded_middle_texture = LoadTexture(middle_texture);
  Texture loaded_shoot_texture = LoadTexture(shoot_texture);

  Magic magic = {.title = title,
                 .magicType = magic_type,
                 .description = description,
                 .hitTexture = loaded_hit_texture,
                 .middleTexture = loaded_middle_texture,
                 .shootTexture = loaded_shoot_texture,
                 .speed = speed,
                 .cooldown = cooldown,
                 .cooldownCounter = cooldown,
                 .position = (Vector2){0, 0}};
  return magic;
}

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

void handleMagicAfterShoot(Magic *magic, int is_hit) {
  {
    // TODO: get enemy position and go towards them
    // TODO: this all is if magic is shootable

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
