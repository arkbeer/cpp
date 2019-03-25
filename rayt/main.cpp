#include<iostream>
#include<fstream>
#include<array>
#include"vec3.hpp"
int main(){
    const int nx=200;
    const int ny=100;
    std::ofstream ofs("data.ppm");

    ofs<<"P3\n"<<nx<<" "<<ny<<"\n255\n";
    for(int j=ny-1;j>=0;--j){
        for(int i=0;i<nx;++i){
            rayt::vec3 col(static_cast<float>(i)/nx, static_cast<float>(j)/ny, 0.2);

            ofs<<col.r()<<" "<<col.g()<<" "<<col.b()<<"\n";
        }

    }
    return 0;
}