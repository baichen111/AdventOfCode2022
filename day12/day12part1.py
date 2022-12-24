from string import ascii_lowercase

with open("input.txt") as infile:
    lines = infile.read().strip().split()

inputs = [list(line) for line in lines]
row = len(inputs)
col = len(inputs[0])

for i in range(row):
    for j in range(col):
        c = inputs[i][j]
        if c == "S":
            start = i, j
        if c == "E":
            end = i, j


def idx(char):
    if char in ascii_lowercase:
        return ascii_lowercase.index(char)
    if char == "S":
        return 0
    if char == "E":
        return 25


# neighbors
def besides(i, j):
    for ni, nj in [[1, 0], [-1, 0], [0, 1], [0, -1]]:
        ii = i + ni
        jj = j + nj
        if not (0 <= ii < row and 0 <= jj < col):
            continue
        if idx(inputs[ii][jj]) <= idx(inputs[i][j]) + 1:
            yield ii, jj


# Dijkstra's algo
visited = [[False] * col for _ in range(row)]
q = [(0, start[0], start[1])]

while True:
    steps, i, j = q.pop(0)

    if visited[i][j]:
        continue
    visited[i][j] = True

    if (i, j) == end:
        print(steps)  # part1: 391
        break

    for ii, jj in besides(i, j):
        q.append((steps + 1, ii, jj))
