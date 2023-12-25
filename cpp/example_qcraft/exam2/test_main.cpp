//
// Created by Jinwen on 2023/12/18.
//

#include <iostream>
#include <vector>

#include "geometry.h"

/* 横向控制找点
 * Point FindMatchPoint(vector<Point>list, Point p)
 * Point = std::pair<x,y>;
 * 并且计算最小横向距离 */

// 找到match点，并返回最小横向距离
std::tuple<Point, float> FindMatchPoint(const std::vector<Point> &list, const Point &p) {

    // 如果点数小于2，则报错

    assert(list.size() >=2);
    float tmp_dist = std::numeric_limits<float>::max();
    int tmp_index = 0;
    for (int i = 0; i < list.size(); ++i) {
        auto dist = getDistance(list[i], p);
        if(dist < tmp_dist) {
            tmp_dist = dist;
            tmp_index = i;
        }
    }

    Line tmp_line;
    //TODO::具体规则，对于首尾，可能有其他更好的处理方式
    if (0 == tmp_index) { // 最近点为第一个点
        tmp_line.s = list[tmp_index];
        tmp_line.e = list[tmp_index+1];
    } else if ( tmp_index == list.size() - 1) {//最近点为最后一个点
        tmp_line.s = list[tmp_index-1];
        tmp_line.e = list[tmp_index];
    } else {    //最近点为中间某个点
        tmp_line.s = list[tmp_index];
        tmp_line.e = list[tmp_index+1];
    }

    // 找到垂足，也就是投影点
    auto match_point = pToLineProjection(p, tmp_line);
    // 计算p到垂足的距离，即为最小横向距离
    auto distance = getDistance(match_point, p);

    return std::make_tuple(match_point, distance);
}

int main() {
    std::cout << "C++: Hello World!" << std::endl;

    std::vector<Point> list = {{0,0}, {1,1}, {2,3}, {3,4}};
    Point p{2,1};
    auto [match_point, distance] = FindMatchPoint(list, p);
    std::cout << "match_point: ("
              << match_point.x
              << ","
              << match_point.y
              << ")"
              << std::endl;
    std::cout << "min lateral distance: "
              << distance
              << std::endl;
    return 0;
}