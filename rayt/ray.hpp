#pragma once
#include"vec3.h"

namespace rayt{
    class ray{
        vec3 _a,_b;
        public:
        ray(const vec3& a, const vec3& b):_a(a),_b(b){}
#define FUNC(FUCNAME,NAME) const vec3 FUNCNAME()const{return _##NAME;}
        FUNC(origin, a)
        FUNC(direction, b)
#undef FUNC
        const vec3 point_at_parameter(const float t){return A+t*B;}

    };
}