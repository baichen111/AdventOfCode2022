lines = []
with open("input.txt") as infile:
    for line in infile:
        input = line.splitlines()[0].split("\t")
        lines.append([int(input[0]), int(input[1]), int(input[2]), int(input[3])])
N = 4000000

for Y in range(N + 1):
    xlines = []
    for sx, sy, bx, by in lines:
        d = abs(sx - bx) + abs(sy - by)
        o = d - abs(sy - Y)

        if o < 0:
            continue

        lx = sx - o
        hx = sx + o

        xlines.append((lx, hx))

    xlines.sort()

    ls = []  # to store non-overlapping x positions

    for low, high in xlines:
        if not ls:
            ls.append([low, high])
            continue
        _, hi = ls[-1]
        if low > hi + 1:
            ls.append([low, high])
            continue
        ls[-1][1] = max(hi, high)
    x = 0
    for low, high in ls:
        if x < low:
            print(x * N + Y)  # part2: 10382630753392
            exit(0)
        x = max(x, high + 1)
        if x > N:
            break
    # print(ls)
