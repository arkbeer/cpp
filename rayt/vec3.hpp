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
        ~vec3(){}
#define FUNC(TYPE, NAME, I) const TYPE NAME()const{return _##NAME;}
        FUNC(float, x, 0);
        FUNC(float, y, 1);
        FUNC(float, z, 2);
        FUNC(int, r, 3);
        FUNC(int, g, 4);
        FUNC(int, b, 5);
#undef FUNC
#define FRIEND(OPENAME) friend vec3 operator OPENAME(const vec3&, const vec3&);
        FRIEND(+)
        FRIEND(-)
        FRIEND(*)
        FRIEND(/)
#undef FRIEND
    };
}

#define FRIEND(OPENAME) rayt::vec3 operator OPENAME(const rayt::vec3& v1, const rayt::vec3& v2){return rayt::vec3(v1.x() OPENAME v2.x(), v1.y() OPENAME v2.y(), v1.z() OPENAME v2.z());}
FRIEND(+)
FRIEND(-)
FRIEND(*)
FRIEND(/)
#undef FRIEND