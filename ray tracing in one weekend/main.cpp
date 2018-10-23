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
    for(int j=ny-1;j>=0;--j){
        for(int i=0;i<nx;++i){
            vec3 col{{static_cast<double>(i)/nx,static_cast<double>(j)/ny,0.2}};
            ofs<<col<<std::endl;
        }
    }
    ofs.close();
    
    return 0;
}
