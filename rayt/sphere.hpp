#include"hitable.hpp"
#include<complex>
namespace rayt{
    class sphere :public hitable{
        vec3 _center;
        float _radius;
    public:
        sphere(const vec3& center, const float radius):_center(center), _radius(radius){}
        sphere():sphere(vec3(),1){}
        virtual bool hit(const ray& r, const float t_min, const float t_max, hitinfo& info) const;
    };
    bool sphere::hit(const ray& r, const float t_min, const float t_max, hitinfo& info)const {
        rayt::vec3 oc=r.origin()-_center;
        const float a=dot(r.direction(), r.direction());
        const float b=dot(r.direction(), oc);
        const float c=dot(oc, oc)-_radius*_radius;
        const float d=b*b-a*c;
        if(d>0){
            float t=(-b-std::sqrt(d))/a;
            if(t_min<t && t<t_max){
                info.t=t;
                info.p=r.point_at_parameter(info.t);
                info.normal=(info.p-_center)/_radius;
                return true;
            }
            t=(-b+std::sqrt(d))/a;
            if(t_min<t && t<t_max){
                info.t=t;
                info.p=r.point_at_parameter(info.t);
                info.normal=(info.p-_center)/_radius;
                return true;
            }
        }
        return false;
    }
}