#include"vec3.hpp"
#include"ray.hpp"
#include"sphere.hpp"
#include"hitable_list.hpp"
#include"camera.hpp"
#include<fstream>
const vec3 random_in_unit_sphere(){
    vec3 p;
    while(p.square_length()>=1){
        p=2.0*vec3{{drand48(),drand48(),drand48()}}-vec3{{1,1,1}};
    }
    return p;
}
const vec3 color(const ray& r,hitable *world){
    hit_record rec;
    if(world->hit(r,0.0,INT8_MAX,rec)){
        vec3 target=rec.p+rec.normal+random_in_unit_sphere();
        return 0.5*color(ray(rec.p,target-rec.p),world);
    }else{
        vec3 unit_direction=r.direction().unit();
        double t=0.5*(unit_direction.y()+1.0);
        return (1.0-t)*vec3{{1.0,1.0,1.0}}+t*vec3{{0.5,0.7,1.0}};
    }
}
std::ostream& make_header(std::ostream& ost,const int nx,const int ny,const int ncolor){
    ost<<"P3\n"<<nx<<" "<<ny<<"\n"<<ncolor<<std::endl;
    return ost;
}
const int nx=200,ny=100,ns=100;
int main(){
    std::ofstream ofs("image.ppm");
    
    make_header(ofs,200,100,255);
    
    hitable *list[2];
    list[0]=new sphere(vec3{{0,0,-1}},0.5);
    list[1]=new sphere(vec3{{0,-100.5,-1}},100);
    hitable *world= new hitable_list(list,2);
    camera cam;
    for(int j=ny-1;j>=0;--j){
        for(int i=0;i<nx;++i){
            vec3 col{{0,0,0}};
            for(int s=0;s<ns;++s){
                const double u=static_cast<double>(i+drand48())/nx;
                const double v=static_cast<double>(j+drand48())/ny;
                ray r=cam.get_ray(u,v);
                col+=color(r,world);
            }
            col/=double(ns);
            //vec3 col{{static_cast<double>(i)/nx,static_cast<double>(j)/ny,0.2}};
            ofs<<col<<std::endl;
        }
    }
    ofs.close();
    
    return 0;
}