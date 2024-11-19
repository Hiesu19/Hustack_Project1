# // Nguyen Thai Hieu - Project1 - 2024.1
# // Week 3 - WATER JUGS
# // WATERJUG	Accept		100	PYTHON3	5 / 5

import math


def solve(a, b, c):
    # Điều kiện c
    if c > max(a, b) or c % math.gcd(a, b) != 0:
        return -1

    queue = [(0, 0, 0)]  # (x, y, steps)
    visited = set()  # theo dõi các trạng thái đã duyệt
    visited.add((0, 0)) # Thêm trạng thai ban đầu

    while queue:
        x, y, steps = queue.pop(0) # lấy vào đầu tiên queue

        # Nếu một trong hai bình có đúng c lít nước
        if x == c or y == c:
            return steps

        # Sinh các trạng thái tiếp theo
        nextStates = [
            (a, y),    # Đổ đầy bình A
            (x, b),    # Đổ đầy bình B
            (0, y),    # Làm rỗng bình A
            (x, 0),    # Làm rỗng bình B
            (max(0, x - (b - y)), min(b, x + y)),  # Đổ từ A sang B
            (min(a, x + y), max(0, y - (a - x)))   # Đổ từ B sang A
        ]
        
        # Duyệt qua nextStates
        for nx, ny in nextStates:
            if (nx, ny) not in visited: # nếu chưa gặp qua
                visited.add((nx, ny))
                queue.append((nx, ny, steps + 1))

    # Nếu không tìm thấy kết quả
    return -1

# Đọc dữ liệu đầu vào
a, b, c = map(int, input().split())
print(solve(a, b, c))
