#include"vec3.hpp"
#include"ray.hpp"
#include<fstream>
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
            vec3 col=r.color();
            //vec3 col{{static_cast<double>(i)/nx,static_cast<double>(j)/ny,0.2}};
            ofs<<col<<std::endl;
        }
    }
    ofs.close();
    
    return 0;
}