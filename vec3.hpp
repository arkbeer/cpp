#include<iostream>
#include<array>
#include<complex>
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
    const vec3 operator-(){
        return vec3{{-e.at(0),-e.at(1),-e.at(2)}};
    }
    double operator[](int i) const{return e.at(i);}
    double& operator[](int i){return e.at(i);}
        
    vec3& operator+=(const vec3& v2){
        this->e.at(0)+=v2.e.at(0);
        this->e.at(1)+=v2.e.at(1);
        this->e.at(2)+=v2.e.at(2);
        return *this;
    }
    vec3& operator-=(const vec3& v2){
        this->e.at(0)-=v2.e.at(0);
        this->e.at(1)-=v2.e.at(1);
        this->e.at(2)-=v2.e.at(2);
        return *this;
    }
    vec3& operator*=(const vec3& v2){
        this->e.at(0)*=v2.e.at(0);
        this->e.at(1)*=v2.e.at(1);
        this->e.at(2)*=v2.e.at(2);
        return *this;
    }
    vec3& operator/=(const vec3& v2){
        this->e.at(0)/=v2.e.at(0);
        this->e.at(1)/=v2.e.at(1);
        this->e.at(2)/=v2.e.at(2);
        return *this;
    }
    vec3& operator*=(const double t){
        this->e.at(0)*=t;
        this->e.at(1)*=t;
        this->e.at(2)*=t;
        return *this;
    }
    vec3& operator/=(const double t){
        this->e.at(0)/=t;
        this->e.at(1)/=t;
        this->e.at(2)/=t;
        return *this;
    }
    friend std::ostream& operator<<(std::ostream&, const vec3&);
    friend std::istream& operator>>(std::istream&, vec3&);
    friend vec3 operator+(const vec3&, const vec3&);
    friend vec3 operator-(const vec3&, const vec3&);
    friend vec3 operator*(const vec3&, const vec3&);
    friend vec3 operator/(const vec3&, const vec3&);
    friend vec3 operator*(const vec3&, const double);
    friend vec3 operator/(const vec3&, const double);
    double square_length()const{
        return e.at(0)*e.at(0)+e.at(1)*e.at(1)+e.at(2)*e.at(2);
    }
    double length()const {
        return std::sqrt(square_length());
    }
    vec3 unit(){
        return *this/length();
    }
};
std::ostream& operator<<(std::ostream& os, const vec3& v){
    os<<v.e.at(0)<<" "<<v.e.at(1)<<" "<<v.e.at(2);
    return os;
}
std::istream& operator>>(std::istream& is, vec3& v){
    is>>v.e.at(0)>>v.e.at(1)>>v.e.at(2);
    return is;
}
vec3 operator+(const vec3& v1, const vec3& v2){
    return vec3{{v1.e.at(0)+v2.e.at(0),v1.e.at(1)+v2.e.at(1),v1.e.at(2)+v2.e.at(2)}};
}
vec3 operator-(const vec3& v1, const vec3& v2){
    return vec3{{v1.e.at(0)-v2.e.at(0),v1.e.at(1)-v2.e.at(1),v1.e.at(2)-v2.e.at(2)}};
}
vec3 operator*(const vec3& v1, const vec3& v2){
    return vec3{{v1.e.at(0)*v2.e.at(0),v1.e.at(1)*v2.e.at(1),v1.e.at(2)*v2.e.at(2)}};
}
vec3 operator/(const vec3& v1, const vec3& v2){
    return vec3{{v1.e.at(0)/v2.e.at(0),v1.e.at(1)/v2.e.at(1),v1.e.at(2)/v2.e.at(2)}};
}
vec3 operator*(const vec3& v1, const double t){
    return vec3{{v1.e.at(0)*t,v1.e.at(1)*t,v1.e.at(2)*t}};
}
vec3 operator/(const vec3& v1, const double t){
    return vec3{{v1.e.at(0)/t,v1.e.at(1)/t,v1.e.at(2)/t}};
}