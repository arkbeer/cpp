#pragma once
#include<random>
#include<limits>
#include<algorithm>
namespace ark {
	class Random {
		std::mt19937 mt;
	public:
		Random() {
			std::random_device rnd;
			mt = std::mt19937(rnd());
		}
        const double Rand(){
            int min=std::numeric_limits<int>::min();
            int max=std::numeric_limits<int>::max();
            std::uniform_int_distribution<> rand_(min,max);
            return static_cast<double>(rand_(mt))/max;
        }
		const int Range(const int x, const int y) {
			auto it = std::minmax(x, y);
			std::uniform_int_distribution<> rand_(it.first, it.second);
			return rand_(mt);
		}
	};
}