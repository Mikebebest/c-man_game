#include <random>
using namespace std;


namespace Random
{
	random_device rd;
	mt19937 gen(rd());

	inline int get(int min, int max)
	{
		return uniform_int_distribution{ min,max }(gen);
	}
}