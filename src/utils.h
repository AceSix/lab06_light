#ifndef UTILS_H
#define UTILS_H

#include "glm.hpp"
#include "rgba.h"

const float ka = 0.5;
const float kd = 0.5;
const float ks = 0.5;


const float c1 = 1;
const float c2 = 3;
const float c3 = 10;

struct Material
{
    glm::vec4 diffuse;
    glm::vec4 ambient;
    glm::vec4 specular;
    int shininess;
};

struct LightInfo
{
    glm::vec4 color;
    glm::vec3 source;
};

float inct_sphere(glm::vec3 pos, glm::vec3 dir);

#endif // UTILS_H
