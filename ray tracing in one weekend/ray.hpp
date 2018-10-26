#include"vec3.hpp"

class ray{
    vec3 A,B;
    public:
    ray(const vec3&a, const vec3& b):A(a),B(b){}
    ray(){}
    const auto orgin() const {return A;}
    const auto direction() const {return B;}
    const auto point_at_param(const double t) const {return A+t*B;}
    const vec3 color(){
        vec3 unit_direction=B.unit();
        double t=0.5*(unit_direction.y()+1.0);
        return (1.0-t)*vec3{{1.0,1.0,1.0}}+t*vec3{{0.5,0.7,1.0}};
    }
};