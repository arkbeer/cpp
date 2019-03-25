#include<iostream>
#include<fstream>
#include<array>
#include<complex>
#include"vec3.hpp"
#include"ray.hpp"
rayt::vec3 color(const rayt::ray& r){
    const rayt::vec3 unit_direction=r.direction().unit();
    float t=0.5*(unit_direction.y()+1.0);
    return (1.0-t)*rayt::vec3(1.0,1.0,1.0)+t*vec3(0.5,0.7,1.0);
}

int main(){
    const int nx=200;
    const int ny=100;
    std::ofstream ofs("data.ppm");

    ofs<<"P3\n"<<nx<<" "<<ny<<"\n255\n";
    for(int j=ny-1;j>=0;--j){
        for(int i=0;i<nx;++i){
            rayt::vec3 col(static_cast<float>(i)/nx, static_cast<float>(j)/ny, 0.2);
            //rayt::ray r;
            //color(r);
            ofs<<col.r()<<" "<<col.g()<<" "<<col.b()<<"\n";
        }

    }
    return 0;
}