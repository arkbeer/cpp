#pragma once
#include"hitable.hpp"


class sphere : public hitable{
    vec3 center;
    float radius;
    
    public:
    sphere(vec3&& cen, double r):center(cen),radius(r){};
    virtual bool hit(const ray& r,const float t_min,const float t_max, hit_record& rec ) const;
    
    
};


bool sphere::hit(const ray& r,const float t_min,const float t_max, hit_record& rec ) const{
    const vec3 oc=r.origin()-center;
    const double a=dot(r.direction(),r.direction());
    const double b=2.0*dot(oc,r.direction());
    const double c=dot(oc,oc)-radius*radius;
    const double discriminant=b*b-4*a*c;
    if(discriminant>0){
        double tmp=(-b-sqrt(discriminant))/(2*a);
        if(tmp<t_max && tmp>t_min){
            rec.t=tmp;
            rec.p=r.point_at_param(rec.t);
            rec.normal=(rec.p-center)/radius;
            return true;
        }
        tmp=(-b+sqrt(discriminant))/a;
        if(tmp<t_max && tmp>t_min){
            rec.t=tmp;
            rec.p=r.point_at_param(rec.t);
            rec.normal=(rec.p-center)/radius;
            return true;
        }
    }
    return false;
}