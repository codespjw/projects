//定义点
struct Point {
    float x;
    float y;
};

//求两点之间的距离
float getDistance(const Point &p1, const Point &p2);

// 两个点相加
Point add(const Point &p1, const Point &p2);

// 两个点相减
Point sub(const Point &p1, const Point &p2);

// 向量长度
float length(const Point &v);

// 向量除常数
Point div(const Point& v, double ratio);

// 向量乘常数
Point mul(const Point& v, double ratio);

//向量归一化
Point normalize(const Point &v);

//定义直线
struct Line {
    Point s;
    Point e;
};

//向量点积
float dotProduct(const Point &v1, const Point &v2);

//求点到直线的投影点
Point pToLineProjection(const Point &p, const Line &l);
