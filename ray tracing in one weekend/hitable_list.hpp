#pragma once
#include"hitable.hpp"
class hitable_list: public hitable{
    private:
        hitable **list;
        int list_size;
    public:
        hitable_list(){}
        hitable_list(hitable **l,int n):list(l),list_size(n){}
        virtual bool hit(const ray& r,const float t_min,const float t_max, hit_record& rec ) const;

};
bool hitable_list::hit(const ray& r,const float t_min,const float t_max, hit_record& rec ) const{
        hit_record tmp;
        bool hit_anything=false;
        double closet_so_far=t_max;
        for(int i=0;i<list_size;++i){
            if(list[i]->hit(r,t_min,closet_so_far,tmp)){
                hit_anything=true;
                closet_so_far=tmp.t;
                rec=tmp;
            }
        }
        return hit_anything;
}