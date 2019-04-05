#include<iostream>
#include<fstream>
#include<array>
#include<complex>
#include<vector>
#include<memory>
#include<limits>

#include"random.hpp"

#include"vec3.hpp"
#include"ray.hpp"
#include"sphere.hpp"
#include"camera.hpp"

namespace rayt{
    class hitable_list: public hitable{
        public:
        std::vector<std::shared_ptr<hitable>> list;
        virtual bool hit(const ray& r, const float t_min, const float t_max, hitinfo& info)const;
    };
    bool hitable_list::hit(const ray& r, const float t_min, const float t_max, hitinfo& info)const{
        hitinfo tmp;
        bool hit_anything=false;
        float closet_so_far=t_max;
        for(const auto& v:list){
            if(v->hit(r, t_min, closet_so_far, tmp)){
                hit_anything=true;
                closet_so_far=tmp.t;
                info=tmp;
            }
        }
        return hit_anything;
    }
}

rayt::vec3 color(const rayt::ray& r, const std::shared_ptr<rayt::hitable>& world){
    rayt::hitinfo info;
    if(world->hit(r, 0.0, std::numeric_limits<float>::max(), info)){
        return 0.5*rayt::vec3(info.normal.x()+1, info.normal.y()+1, info.normal.z()+1);
    }else{
        const rayt::vec3 unit_direction=r.direction().unit();
        float t=0.5*(unit_direction.y()+1.0);
        return (1.0-t)*rayt::vec3(1.0,1.0,1.0)+t*rayt::vec3(0.5,0.7,1.0);
    }
}

int main(){
    const int nx=200;
    const int ny=100;
    const int ns=100;
    rayt::vec3 lower_left_corner(-2.0,-1.0,-1.0);
    rayt::vec3 horizontal(4,0,0);
    rayt::vec3 vertical(0,2,0);
    rayt::vec3 origin(0,0,0);
    ark::Random rnd;


    const rayt::vec3 center(0,0,-1);
    rayt::hitable_list li;
    li.list.push_back(std::make_shared<rayt::sphere>(center, 0.5));
    li.list.push_back(std::make_shared<rayt::sphere>(rayt::vec3(0,-100.5,-1), 100));
    std::shared_ptr<rayt::hitable_list> world=std::make_shared<rayt::hitable_list>(li);

    std::ofstream ofs("data.ppm");
    rayt::camera cam;
    ofs<<"P3\n"<<nx<<" "<<ny<<"\n255\n";
    for(int j=ny-1;j>=0;--j){
        for(int i=0;i<nx;++i){
            rayt::vec3 col;
            for(int s=0;s<ns;++s){
                const float u=static_cast<float>(i+rnd.Rand())/nx;
                const float v=static_cast<float>(j+rnd.Rand())/ny;
                rayt::ray r=cam.get_ray(u,v);
                col+=color(r,world);
            }
            col/=ns;
            ofs<<col.r()<<" "<<col.g()<<" "<<col.b()<<"\n";
        }
    }
    return 0;
}
