#include<iostream>
#include<array>
#include<complex>
int main(){
    class vec3{
        std::array<double,3> e;
        public:
        vec3(const std::array<double,3>& _e):e(_e){}
        vec3():vec3({0,0,0}){}
        const auto x(){return e.at(0);}
        const auto y(){return e.at(1);}
        const auto z(){return e.at(2);}
        const auto r(){return e.at(0);}
        const auto g(){return e.at(1);}
        const auto b(){return e.at(2);}
        const vec3& operator+(){return *this;}
        const vec3& operator-(){
            return vec3(std::array<double,3>{-e.at(0),-e.at(1),-e.at(2)});
        }
        double operator[](int i) const{return e.at(i);}
        double& operator[](int i){return e.at(i);}
        
        vec3& operator+=(const vec3& v2);
        vec3& operator-=(const vec3& v2);
        vec3& operator*=(const vec3& v2);
        vec3& operator/=(const vec3& v2);
        vec3& operator*=(const double t);
        vec3& operator/=(const double t);
        
        const double length()const {
            return std::sqrt(e.at(0)*e.at(0)+e.at(1)*e.at(1)+e.at(2)*e.at(2));
        }
        
    };
    
    vec3 v{{1,1,1}};
    std::cout<<v.length()<<std::endl;
    return 0;
}
