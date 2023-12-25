import numpy as np


def is_convex_polygon(vertices):
    num_vertices = len(vertices)
    if num_vertices < 3:
        return False

    is_positive = None
    for i in range(num_vertices):
        vector1 = vertices[(i + 1) % num_vertices] - vertices[i]
        vector2 = vertices[(i + 2) % num_vertices] - vertices[(i + 1) % num_vertices]
        cross_product = np.cross(vector1, vector2)

        if is_positive is None:
            if cross_product > 0:
                is_positive = True
            elif cross_product < 0:
                is_positive = False
        else:
            if (cross_product > 0 and not is_positive) or (cross_product < 0 and is_positive):
                return False

    return True


if __name__ == '__main__':
    # 凸多边形测试用例
    convex_polygon = np.array([[0, 0], [1, 1], [2, 0], [1, -1]])
    print(is_convex_polygon(convex_polygon))  # 输出: True

    # 凹多边形测试用例
    concave_polygon = np.array([[0, 0], [1, 1], [2, 0], [1, 1]])
    print(is_convex_polygon(concave_polygon))  # 输出: False

    # 单点或线段测试用例
    point = np.array([[0, 0]])
    print(is_convex_polygon(point))  # 输出: False

    line_segment = np.array([[0, 0], [1, 1]])
    print(is_convex_polygon(line_segment))  # 输出: False
