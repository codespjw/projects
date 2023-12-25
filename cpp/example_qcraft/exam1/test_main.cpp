#include <iostream>
#include <vector>

struct Point {
    double x;
    double y;
};

// 通过叉积计算向量方向
double crossProduct(const Point& p1, const Point& p2, const Point& p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

bool isConvexPolygon(const std::vector<Point>& vertices) {
    int numVertices = vertices.size();
    if (numVertices < 3) {
        return false;
    }

    bool isPositive = false;
    for (int i = 0; i < numVertices; ++i) {
        double crossProductResult = crossProduct(vertices[i], vertices[(i + 1) % numVertices], vertices[(i + 2) % numVertices]);

        if (crossProductResult == 0) {
            continue;  // 忽略共线的顶点
        }

        if (isPositive == false) {
            isPositive = (crossProductResult > 0);
        } else {
            if ((crossProductResult > 0 && isPositive == false) || (crossProductResult < 0 && isPositive == true)) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    std::vector<Point> polygon = { {0, 0}, {1, 1}, {2, 0}, {1, -1} };

    if (isConvexPolygon(polygon)) {
        std::cout << "Convex Polygon" << std::endl;
    } else {
        std::cout << "Concave Polygon" << std::endl;
    }

    return 0;
}