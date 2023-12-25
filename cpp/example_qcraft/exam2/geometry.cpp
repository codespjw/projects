#include "geometry.h"
#include <cmath>

//求两点之间的距离
float getDistance(const Point &p1, const Point &p2) {

    auto dx = p1.x - p2.x;
    auto dy = p1.y - p2.y;

    return sqrt(dx*dx + dy*dy);
}

// 两个点相加
Point add(const Point &p1, const Point &p2) {

    Point ret;

    ret.x = p1.x + p2.x;
    ret.y = p1.y + p2.y;

    return ret;
}

// 两个点相减
Point sub(const Point &p1, const Point &p2) {

    Point ret;

    ret.x = p1.x - p2.x;
    ret.y = p1.y - p2.y;

    return ret;
}

// 向量长度
float length(const Point &v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

// 向量除常数
Point div(const Point& v, double ratio) {
    Point ret;

    ret.x = v.x / ratio;
    ret.y = v.y / ratio;

    return ret;
}

// 向量乘常数
Point mul(const Point& v, double ratio) {
    Point ret;

    ret.x = v.x * ratio;
    ret.y = v.y * ratio;

    return ret;
}

//向量归一化
Point normalize(const Point &v) {
    Point ret;

    ret = div(v, length(v));

    return ret;
}

//向量点积
float dotProduct(const Point &v1, const Point &v2) {
    return(v1.x * v2.x + v1.y * v2.y);
}

//求点到直线的投影点
Point pToLineProjection(const Point &p, const Line &l) {
    Point line_vec = sub(l.e, l.s);
    Point point_vec = sub(p, l.s);
    Point unit_line_vec = normalize(line_vec);

    // 点在直线上的投影长度
    double project_length = dotProduct(point_vec, unit_line_vec);

    // 实际投影点，也就是垂足
    Point project_p = add(l.s,mul(unit_line_vec, project_length));

    return project_p;
}

