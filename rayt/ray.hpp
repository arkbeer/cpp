#pragma once
#include"vec3.hpp"

namespace rayt{
    class ray{
        vec3 _a,_b;
        public:
        ray(const vec3& a, const vec3& b):_a(a),_b(b){}
        ray():ray(vec3(),vec3()){}
#define FUNC(FUNCNAME,NAME) const vec3 FUNCNAME()const{return _##NAME;}
        FUNC(origin, a)
        FUNC(direction, b)
#undef FUNC
        const vec3 point_at_parameter(const float t){return _a+t*_b;}

    };
}