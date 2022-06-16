#include "lightmodel.h"
#include <math.h>


RGBA phong(glm::vec3 p, glm::vec3 n, glm::vec3 c, Material m, LightInfo l)
{
    glm::vec4 illumination(0,0,0,0);
    glm::vec3 light_dir = p - l.source;
    float distance = glm::length(light_dir);
    light_dir = glm::normalize(light_dir);
    float atten = std::max(1.f, 1.f/(c1 + c2*distance + c3*distance*distance));
//    atten = 1;

    // ambient
    illumination += m.ambient*ka;
    // diffuse
    float cos = -glm::dot(n, light_dir);
    cos = std::clamp(cos, 0.f, 1.f);
    illumination += l.color*m.diffuse*kd*cos*atten;
    // specular
    glm::vec3 eyesight = glm::normalize(c - p);
    glm::vec3 reflect = 2.f*cos*n + light_dir;
    float cos2 = glm::dot(eyesight, reflect);
    cos2 = std::clamp(cos2, 0.f, 1.f);
    illumination += l.color*m.specular*ks*(float)pow(cos2, m.shininess)*atten;

    RGBA out(0,0,0,0);
    out.r = glm::clamp(illumination.r, 0.f, 1.f)*255.f;
    out.g = glm::clamp(illumination.g, 0.f, 1.f)*255.f;
    out.b = glm::clamp(illumination.b, 0.f, 1.f)*255.f;
    out.a = glm::clamp(illumination.a, 0.f, 1.f)*255.f;
    return out;
}
