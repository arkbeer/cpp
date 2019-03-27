#pragma once
namespace rayt{
    class vec3{
        float _x,_y,_z;
        int _r,_g,_b;
        public:
        vec3(const float x, const float y, const float z):_x(x),_y(y),_z(z){
            _r=static_cast<int>(_x*255.99);
            _g=static_cast<int>(_y*255.99);
            _b=static_cast<int>(_z*255.99);
        }
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
#define FUNC(TYPE, NAME, I) const TYPE NAME()const{return _##NAME;}
        FUNC(float, x, 0);
        FUNC(float, y, 1);
        FUNC(float, z, 2);
        FUNC(int, r, 3);
        FUNC(int, g, 4);
        FUNC(int, b, 5);
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