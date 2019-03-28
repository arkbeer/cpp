#include<iostream>
#include<fstream>
#include<array>
#include<complex>
#include"vec3.hpp"
#include"ray.hpp"

bool hit_sphere(const rayt::vec3& center, const float radius, const rayt::ray& r){
    rayt::vec3 oc=r.origin()-center;
    const float a=dot(r.direction(), r.direction());
    const float b=2.0*dot(r.direction(), oc);
    const float c=dot(oc, oc)-radius*radius;
    const float d=b*b-4*a*c;
    return d>0;
}
rayt::vec3 color(const rayt::ray& r){
    if(hit_sphere(rayt::vec3(0,0,-1), 0.5 ,r))return rayt::vec3(1,0,0);
    const rayt::vec3 unit_direction=r.direction().unit();
    float t=0.5*(unit_direction.y()+1.0);
    return (1.0-t)*rayt::vec3(1.0,1.0,1.0)+t*rayt::vec3(0.5,0.7,1.0);
}

int main(){
    const int nx=200;
    const int ny=100;

    rayt::vec3 lower_left_corner(-2.0,-1.0,-1.0);
    rayt::vec3 horizontal(4,0,0);
    rayt::vec3 vertical(0,2,0);
    rayt::vec3 origin(0,0,0);

    std::ofstream ofs("data.ppm");

    ofs<<"P3\n"<<nx<<" "<<ny<<"\n255\n";
    for(int j=ny-1;j>=0;--j){
        for(int i=0;i<nx;++i){
            const float u=static_cast<float>(i)/nx;
            const float v=static_cast<float>(j)/ny;
            rayt::ray r(origin, lower_left_corner+u*horizontal+v*vertical);
            rayt::vec3 col=color(r);
            ofs<<col.r()<<" "<<col.g()<<" "<<col.b()<<"\n";
        }

    }
    return 0;
}