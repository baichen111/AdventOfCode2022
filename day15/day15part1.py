cannot = set()
known = set()
Y = 2000000

intervals = []


with open("input.txt") as infile:
    for line in infile:
        input = line.splitlines()[0].split("\t")

        sx, sy, bx, by = int(input[0]), int(input[1]), int(input[2]), int(input[3])

        d = abs(sx - bx) + abs(sy - by)
        o = d - abs(sy - Y)

        if o < 0:
            continue

        lx = sx - o
        hx = sx + o

        for x in range(lx, hx + 1):
            cannot.add(x)

        if by == Y:
            known.add(bx)

print(len(cannot - known))  # part1: 4424278
