#pragma once
namespace rayt{
    class vec3{
        float _x,_y,_z;
        public:
        vec3(const float x, const float y, const float z):_x(x),_y(y),_z(z){}
        vec3():vec3(0,0,0){}
        ~vec3(){}
                const float square()const{
            return _x*_x+_y*_y+_z*_z;
        }
        const float length()const{
            return std::sqrt(square());
        }
        const vec3 unit()const{
            return *this/length();
        }
#define FUNC(TYPE, NAME) const TYPE NAME()const{return _##NAME;}
        FUNC(float, x);
        FUNC(float, y);
        FUNC(float, z);
#undef FUNC
#define FUNC(TYPE, NAME, COORD) const TYPE NAME()const{return static_cast<int>(_##COORD*255.99);}
        FUNC(int, r, x);
        FUNC(int, g, y);
        FUNC(int, b, z);
#undef FUNC
#define FRIEND_OPERATOR(OPENAME) friend vec3 operator OPENAME(const vec3&, const vec3&);
        FRIEND_OPERATOR(+)
        FRIEND_OPERATOR(-)
        FRIEND_OPERATOR(*)
        FRIEND_OPERATOR(/)
#undef FRIEND_OPERATOR
#define FRIEND_OPERATOR(OPENAME) friend vec3 operator OPENAME(const vec3&, const float);
        FRIEND_OPERATOR(*)
        FRIEND_OPERATOR(/)
#undef FRIEND_OPERATOR
    };
const float dot(const vec3& v1, const vec3& v2){
    return v1.x()*v2.x()+v1.y()*v2.y()+v1.z()*v2.z();
}
#define OPERATOR(OPENAME) vec3 operator OPENAME(const vec3& v1, const vec3& v2){return vec3(v1.x() OPENAME v2.x(), v1.y() OPENAME v2.y(), v1.z() OPENAME v2.z());}
    OPERATOR(+)
    OPERATOR(-)
    OPERATOR(*)
    OPERATOR(/)
#undef OPERATOR
#define OPERATOR(OPENAME) vec3 operator OPENAME(const vec3& v, const float t){return vec3(v.x() OPENAME t, v.y() OPENAME t, v.z() OPENAME t);}
    OPERATOR(*)
    OPERATOR(/)
#undef OPERATOR
#define OPERATOR(OPENAME) vec3 operator OPENAME(const float t, const vec3& v){return v*t;}
    OPERATOR(*)
#undef OPERATOR
}