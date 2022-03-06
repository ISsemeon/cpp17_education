#include <iostream>

using namespace std;


// Aggregate initialization of classes with base classes
namespace ex1
{
	struct point2d
	{
		int x{0};
		int y{0};
	};

	struct point3d : point2d
	{
		int z{0};
	};

	void foo()
	{
		point3d p_a{ {1,2}, 3 };  // x = 1, y = 2, z = 3

		point3d p_b{ {}, 3 };     // x = 0, y = 0, z = 3

		point3d p_c{ {1}, 3 };    // x = 1, y = 0, z = 3
	}
}

namespace ex2
{
	struct point2d
	{
		int x{0};
		int y{0};
	};

	struct point3d : point2d
	{
		int z{0};
	};

	struct point4d : point3d
	{
		int time{0};
	};

	void foo()
	{
		point4d p_a{ {{1, 2}, 3}, 100};  // x = 1, y = 2, z = 3  time = 100
		point4d p_b{ {{}, 3}, 200 };     // x = 0, y = 0, z = 3 time = 200
		point4d p_c{ {{1}, 3}, 300 };    // x = 1, y = 0, z = 3 time = 300
	}
}

namespace ex3
{
	struct point2d
	{
		int x{0};
		int y{0};
	};

	struct point3d
	{
		int z{0};
	};

	struct point4d : point2d, point3d
	{
	};

	void foo()
	{
		point4d p_a{{1,2}, {3}};  // x = 1, y = 2, z = 3
		point4d p_b{{}, {3} };     // x = 0, y = 0, z = 3
		point4d p_c{{1}, {3} };    // x = 1, y = 0, z = 3
	}
}

namespace ex4
{
	struct base
	{
		int id;
	};

	struct derived : base
	{
		void print()
		{
			cout << id << endl;
		}
		int val;
	};

	void foo()
	{
		derived a{1};
		derived b{ {1} };
		derived c{ {1} ,2};
		derived d{1, 2};
		derived e{ {}, 2};
	}
}

int main()
{

	ex1::foo();
	ex2::foo();
	ex3::foo();
	ex4::foo();

	struct Base
	{
		Base():id(0)
		{

		}
		int id{100};
	};

	struct Derived : Base
	{
		void print()
		{
			cout << id << endl;
		}
		int val;
	};

	Derived d{{}, 2};

	return 0;
}