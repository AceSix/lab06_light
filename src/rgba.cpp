#include "rgba.h"

RGBA RGBA::operator+(const RGBA &that) const {
    return RGBA(this->r + that.r, this->g + that.g, this->b + that.b, this->a + that.a);
}

RGBA RGBA::operator-(const RGBA &that) const {
    return RGBA(this->r - that.r, this->g - that.g, this->b - that.b, this->a - that.a);
}

RGBA RGBA::operator*(const RGBA &that) const {
    return RGBA(this->r * that.r, this->g * that.g, this->b * that.b, this->a * that.a);
}

RGBA RGBA::operator/(const RGBA &that) const {
    return RGBA(this->r / that.r, this->g / that.g, this->b / that.b, this->a / that.a);
}

RGBA RGBA::operator+(const float &coef) const {
    return RGBA(this->r + coef, this->g + coef, this->b + coef, this->a + coef);
}

RGBA RGBA::operator-(const float &coef) const {
    return RGBA(this->r - coef, this->g - coef, this->b - coef, this->a - coef);
}

RGBA RGBA::operator*(const float &coef) const {
    return RGBA(this->r * coef, this->g * coef, this->b * coef, this->a * coef);
}

RGBA RGBA::operator/(const float &coef) const {
    return RGBA(this->r / coef, this->g / coef, this->b / coef, this->a / coef);
}

bool operator==(const RGBA &c1, const RGBA &c2) {
    return (c1.r == c2.r) && (c1.g == c2.g) && (c1.b == c2.b) && (c1.a == c2.a);
}

bool operator!=(const RGBA &c1, const RGBA &c2) {
    return !operator==(c1, c2);
}

QRgb RGBA::convertQt()
{
    return qRgba(r, g, b, a);
}
