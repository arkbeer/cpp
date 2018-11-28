#pragma once
#include"vec3.hpp"

class ray{
    vec3 A,B;
    public:
    ray(const vec3&a, const vec3& b):A(a),B(b){}
    ray(){}
    const auto origin() const {return A;}
    const auto direction() const {return B;}
    const auto point_at_param(const double t) const {return A+t*B;}
};