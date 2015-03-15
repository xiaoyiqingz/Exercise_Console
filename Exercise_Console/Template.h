
/************************************************************************/
/*  ģ���� ��ģ�庯�� ��������ʵ����ö����� .h ��  �������ʱ�����                                                                    */
/************************************************************************/

namespace test{

/*-----ģ�庯������------*/
template <class T>
T min(T a, T b)   //T ��ʾ������������ͬ ͬint��ͬdouble
{
	return (a < b) ? a:b;
}

template <class I , class D>
D min(I a, D b)
{
	return (a < b) ? a : b;
}	
/*-------------------*/

/*-----ģ�������-------*/
template <class T>
class OperateGraph
{
public:
	OperateGraph(T graph);
	~OperateGraph();
	void ShowPos();

private: 
	T graph_;
};

template <class T>
test::OperateGraph<T>::OperateGraph(T graph)
	: graph_(graph)
{
}


template <class T>
test::OperateGraph<T>::~OperateGraph()
{
}

template <class T>
void test::OperateGraph<T>::ShowPos()
{
	graph_.ShowPos();

	// if you only use Line in main(), it will ok , but if you use point, it will tell you point doesn't have ShowLine()
	//graph_.ShowLine(); 
	//graph_.Hehe();   // both complile and link is ok, but when you use OperationGraph, it will show error
}

class Point
{
friend class Line;
public: 
	Point() : x_(0), y_(0) {};
	Point(int x, int y) : x_(x), y_(y) {};
	~Point(){};
	void ShowPos();
	void ShowPoint();

private:
	int x_;
	int y_;
};


class Line
{
public:
	Line(){};
	Line(const Point& begin, const Point& end) : begin_(begin), end_(end){};
	~Line(){};
	void ShowPos();
	void ShowLine();

private:
	Point begin_;
	Point end_;
};
/*--------------------*/

} //namespace test