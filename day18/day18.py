
data = []
with open("input.txt") as infile:
    lines = infile.readlines()
    for line in lines:
        data.append([int(x) for x in line.strip().split(',')])

sides = dict()
dir = [(0, 0, .5), (0, .5, 0), (.5, 0, 0),
       (0, 0, -.5), (0, -.5, 0), (-.5, 0, 0)]
for x, y, z in data:
    for dx, dy, dz in dir:
        s = (x+dx, y+dy, z+dz)
        if s not in sides:
            sides[s] = 0
        sides[s] += 1
print(list(sides.values()).count(1))  # part1: 4288
