#pragma once
#include"vec3.hpp"
#include"ray.hpp"
namespace rayt{
    struct hitinfo{
        float t;
        vec3 p;
        vec3 normal;
    };
    class hitable{
    public:
        virtual bool hit(const ray& r, const float t_min, const float t_max, hitinfo& info) const=0;
    };
}