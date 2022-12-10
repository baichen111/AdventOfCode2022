import sys

infile = sys.argv[1] if len(sys.argv) > 1 else "input.txt"
data = open(infile).read().strip()
lines = [x for x in data.split("\n")]


G = [["?" for _ in range(40)] for _ in range(6)]
x = 1
t = 0


def handle_tick(t, x):
    global G
    t1 = t - 1
    G[t1 // 40][t1 % 40] = "#" if abs(x - (t1 % 40)) <= 1 else " "


for line in lines:
    words = line.split()
    if words[0] == "noop":
        t += 1
        handle_tick(t, x)
    elif words[0] == "addx":
        t += 1
        handle_tick(t, x)
        t += 1
        handle_tick(t, x)
        x += int(words[1])

for r in range(6):
    print("".join(G[r]))  # part2: ZKGRKGRK
