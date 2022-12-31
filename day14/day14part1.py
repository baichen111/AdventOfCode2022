mat = [["."]*600 for _ in range(200)]  # 200 row x 600 col
# mat = [["."]*505 for _ in range(12)]  # for test

m = []
with open("c:/AOC2022/day14/input.txt") as infile:
    for line in infile:
        line = line.strip('\n').split("->")
        path = []
        for data in line:
            x, y = data.strip().split(",")
            path.append(int(x))
            path.append(int(y))
        m.append(path)

# Building walls
for ls in m:
    for i in range(2, len(ls), 2):
        start_x = ls[i-2]
        start_y = ls[i-1]
        end_x = ls[i]
        end_y = ls[i+1]
        if start_x == end_x:
            n = 1 if end_y - start_y > 0 else -1
            for y in range(start_y, end_y+n, n):
                mat[y][start_x] = "#"
        if start_y == end_y:
            n = 1 if end_x - start_x > 0 else -1
            for x in range(start_x, end_x+n, n):
                mat[start_y][x] = "#"
# Logic
c = 0
while True:
    row = 0
    col = 500
    while True:
        if row >= len(mat)-1 or col >= len(mat[0])-1:
            break
        # sand got blocked by "#" or "o" right below it
        if mat[row+1][col] == "#" or mat[row+1][col] == "o":
            if (mat[row+1][col-1] == "#" or mat[row+1][col-1] == "o") and (mat[row+1][col + 1] == "#" or mat[row+1][col+1] == "o"):  # stop condition
                mat[row][col] = "o"
                break
            elif mat[row+1][col-1] == ".":  # update row and col if sand moves to left lower
                row += 1
                col -= 1
            # update row and col if sand moves to right lower
            elif (mat[row+1][col-1] == "#" or mat[row+1][col-1] == "o") and mat[row+1][col+1] == ".":
                row += 1
                col += 1
        else:
            row += 1
    c += 1
    if row >= len(mat)-1 or col >= len(mat[0])-1:
        break

print("count: ", c-1)  # part1: 808
