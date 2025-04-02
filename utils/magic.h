#ifndef MAGIC
#define MAGIC
#include "raylib.h"

enum MagicType {
    INPLACE,
    SHOOT,
    EXPLODE,
};

enum MagicState {
    SHOT,
    FORWARD,
    HIT
};

typedef struct {
    const char* title;
    const char* description;
    float speed;
    float cooldown;
    float cooldownCounter;
    Vector2 position;
    Texture shootTexture;
    Texture middleTexture;
    Texture hitTexture;
    const enum MagicType magicType;
} Magic;

Magic createMagic(char *title, char *description, enum MagicType magic_type,
                  const char *hit_texture, const char *middle_texture,
                  const char *shoot_texture, float speed, float cooldown);
void destroyMagic(Magic magic);

#endif
