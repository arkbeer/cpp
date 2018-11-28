#pragma once
#include"vec3.hpp"
struct hit_record{
    float t;
    vec3 p;
    vec3 normal;
};
class hitable{
    public:
    virtual bool hit(const ray& r,const float t_min,const float t_max, hit_record& rec ) const =0;
};