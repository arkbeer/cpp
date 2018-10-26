#include"vec3.hpp"
#include"ray.hpp"
#include<fstream>
const bool hit_sphere(const vec3& center, const double radius, const ray& r){
    const vec3 oc=r.origin()-center;
    const double a=dot(r.direction(),r.direction());
    const double b=2.0*dot(oc,r.direction());
    const double c=dot(oc,oc)-radius*radius;
    const double discriminant=b*b-4*a*c;
    return (discriminant>0);
}
const vec3 color(const ray& r){
    if(hit_sphere(vec3{{0,0,-1}},0.5,r))return vec3{{1,0,0}};
    vec3 unit_direction=r.direction().unit();
    double t=0.5*(unit_direction.y()+1.0);
    return (1.0-t)*vec3{{1.0,1.0,1.0}}+t*vec3{{0.5,0.7,1.0}};
}
std::ostream& make_header(std::ostream& ost,const int nx,const int ny,const int ncolor){
    ost<<"P3\n"<<nx<<" "<<ny<<"\n"<<ncolor<<std::endl;
    return ost;
}
const int nx=200,ny=100;
int main(){
    std::ofstream ofs("image.ppm");
    
    make_header(ofs,200,100,255);
    
    vec3 lower_left_corner{{-2.0,-1.0,-1.0}};
    vec3 horizontal{{4.0,0.0,0.0}};
    vec3 vertical{{0.0,2.0,0.0}};
    vec3 origin{{0.0,0.0,0.0}};
    
    for(int j=ny-1;j>=0;--j){
        for(int i=0;i<nx;++i){
            const double u=static_cast<double>(i)/nx;
            const double v=static_cast<double>(j)/ny;
            ray r(origin,lower_left_corner+u*horizontal+v*vertical);
            vec3 col=color(r);
            //vec3 col{{static_cast<double>(i)/nx,static_cast<double>(j)/ny,0.2}};
            ofs<<col<<std::endl;
        }
    }
    ofs.close();
    
    return 0;
}
