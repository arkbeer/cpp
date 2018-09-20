#include"vec3.hpp"
std::ostream& make_header(std::ostream& ost,const int nx,const int ny,const int ncolor){
    ost<<"P3\n"<<nx<<" "<<ny<<"\n"<<ncolor<<std::endl;
    return ost;
}
int main(){
    make_header(std::cout,200,100,255);
    return 0;
}