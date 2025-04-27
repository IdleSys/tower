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

typedef struct EnemyState {
    Vector2 position;
    Vector2 direction;

} EnemyState;

typedef struct {
    const char* title;
    const char* description;
    float speed;
    float cooldown;
    int amount;
    int amountCounter;
    float cooldownCounter;
    Texture shootTexture;
    Texture middleTexture;
    Texture hitTexture;
    const enum MagicType magicType;
} Magic;

Magic *createMagic(char *title, char *description, float speed, float cooldown,
                   float cooldownCounter);
void destroyMagic(Magic magic);

#endif
