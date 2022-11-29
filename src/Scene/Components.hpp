#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <string>

struct TagComponent {
  std::string tag;
};

struct TransformComponent {
  int posX;
  int posY;
  // glm::vec2 position;
  // glm::vec2 scale;
};

struct MovementComponent {
  int velX;
  int velY;
  // glm::vec2 velocity;
};


struct SpriteComponent {
  int x = 0;
  int y = 0;
  int size = 32;
  SDL_Texture* texture;
};

#endif
