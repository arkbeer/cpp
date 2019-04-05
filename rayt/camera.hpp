#pragma once

#include"ray.hpp"

namespace rayt{
    class camera{
        rayt::vec3 _lower_left_corner;
        rayt::vec3 _horizontal;
        rayt::vec3 _vertical;
        rayt::vec3 _origin;
    public:
        camera(vec3 lower_left_corner, vec3 horizontal, vec3 vertical, vec3 origin): _lower_left_corner(lower_left_corner), _horizontal(horizontal), _vertical(vertical), _origin(origin){}
        camera():camera(vec3(-2.0,-1.0,-1.0), vec3(4,0,0), vec3(0,2,0), vec3(0,0,0)){}
        ray get_ray(const float u, const float v){return ray(_origin, _lower_left_corner+u*_horizontal+v*_vertical);}
    };
}