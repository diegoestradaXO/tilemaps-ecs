#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <string>

struct TagComponent {
  std::string tag;
};

struct TransformComponent {
  int posX;
  int posY;
  int scaleX;
  int scaleY;
  // glm::vec2 position;
  // glm::vec2 scale;
  double rotation;
};

struct MovementComponent {
  int velX;
  int velY;
  // glm::vec2 velocity;
};

struct ColliderComponent {
    int w;
    int h;
  // glm::vec2 size;
};

#endif