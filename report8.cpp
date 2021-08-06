#include<iostream>
#include<cmath>
#include<array>
#include<string>

template<typename T, int N>
struct autodif{
    T v;
    std::array<T,N> d;
    autodif(){
        d.fill(0);
        v=0;
    }
    autodif(const T _v, const std::array<T,N> _d):v(_v), d(_d){
    }
    autodif<T,N>& sqrt(){
        v=std::sqrt(v);
        for(int i=0;i<N;++i){
            d.at(i)=d.at(i)/(2*v);
        }
        return *this;
    }
};
template<typename T, int N>
autodif<T,N> operator+(const autodif<T,N>& left, const T right){
    autodif<T,N> tmp;
    tmp.v=left.v+right;
    tmp.d=left.d;
    return tmp;
}
template<typename T, int N>
autodif<T,N> operator+(const T left, const autodif<T,N>& right){
    return right+left;
}
template<typename T, int N>
autodif<T,N> operator+(const autodif<T,N>& left, const autodif<T,N>& right){
    autodif<T,N> tmp;
    tmp.v=left.v+right.v;
    for(int i=0;i<N;++i){
        tmp.d.at(i)=left.d.at(i)+right.d.at(i);
    }
    return tmp;
}
template<typename T, int N>
autodif<T,N> operator-(const autodif<T,N>& left, const T right){
    autodif<T,N> tmp;
    tmp.v=left.v-right;
    tmp.d=left.d;
    return tmp;
}
template<typename T, int N>
autodif<T,N> operator-(const T left, const autodif<T,N>& right){
    autodif<T,N> tmp;
    tmp.v=left-right.v;
    tmp.d=-right.d;
    return tmp;
}
template<typename T, int N>
autodif<T,N> operator-(const autodif<T,N>& left, const autodif<T,N>& right){
    autodif<T,N> tmp;
    tmp.v=left.v-right.v;
    for(int i=0;i<N;++i){
        tmp.d.at(i)=left.d.at(i)-right.d.at(i);
    }
    return tmp;
}
template<typename T, int N>
autodif<T,N> operator*(const autodif<T,N>& left, const T right){
    autodif<T,N> tmp;
    tmp.v=left.v*right;
    for(int i=0;i<N;++i){
        tmp.d.at(i)=right*left.d.at(i);
    }
    return tmp;
}
template<typename T, int N>
autodif<T,N> operator*(const T left, const autodif<T,N>& right){
    return right*left;
}
template<typename T, int N>
autodif<T,N> operator*(const autodif<T,N>& left, const autodif<T,N>& right){
    autodif<T,N> tmp;
    tmp.v=left.v*right.v;
    for(int i=0;i<N;++i){
        tmp.d.at(i)=right.v*left.d.at(i)+left.v*right.d.at(i);
    }
    return tmp;
}
template<typename T, int N>
autodif<T,N> operator/(const autodif<T,N>& left, const T right){
    autodif<T,N> tmp;
    tmp.v=left.v/right;
    for(int i=0;i<N;++i){
        tmp.d.at(i)=left.d.at(i)/right;
    }
    return tmp;
}
template<typename T, int N>
autodif<T,N> operator/(const T left, const autodif<T,N>& right){
    autodif<T,N> tmp;
    tmp.v=left/right.v;
    for(int i=0;i<N;++i){
        tmp.d.at(i)=right.d.at(i)*(-left/(right.v*right.v));
    }
    return tmp;
}
template<typename T, int N>
autodif<T,N> operator/(const autodif<T,N>& left, const autodif<T,N>& right){
    autodif<T,N> tmp;
    tmp.v=left.v+right.v;
    for(int i=0;i<N;++i){
        tmp.d.at(i) = left.d.at(i) / right.v + right.d.at(i) * (-left.v/(right.v*right.v));
        tmp.d.at(i)=left.d.at(i)+right.d.at(i);
    }
    return tmp;
}
int main(){
    autodif<double, 2> f,x(2,{1,0}),y(1,{0,1});
    f=(x-y)*(x*x+y)+x*y;
    std::cout<<f.v<<" "<<f.d.at(0)<<" "<<f.d.at(1)<<std::endl;
    return 0;
}