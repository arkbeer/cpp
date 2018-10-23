#include"vec3.hpp"
std::ostream& make_header(std::ostream& ost,const int nx,const int ny,const int ncolor){
    ost<<"P3\n"<<nx<<" "<<ny<<"\n"<<ncolor<<std::endl;
    return ost;
}
const int nx=200,ny=100;
int main(){
    make_header(std::cout,200,100,255);
    for(int j=ny-1;j>=0;--j){
        for(int i=0;i<nx;++i){
            vec3 col{{static_cast<double>(i)/nx,static_cast<double>(j)/ny,0.2}};
            std::cout<<col<<std::endl;
            
        }
    }
    
    return 0;
}
