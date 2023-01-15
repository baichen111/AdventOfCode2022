import numpy as np


class Rock:
    col_height = 0
    column = [[]] * 7

    def __init__(self, pattern: list) -> None:
        self.pattern = pattern
        self.width = len(self.pattern[0])
        self.height = len(self.pattern)

    def hit(self, x, y) -> bool:
        if x + self.width > 7 or x < 0 or y < 0:
            return True
        for row in range(len(self.pattern)):
            if y + row >= Rock.col_height:
                return False
            p = self.pattern[self.height - row - 1]
            for col in range(len(p)):
                if p[col] != "#":
                    continue
                if Rock.column[x + col][y + row] == "#":
                    return True
        return False

    def settle(self, x, y):
        new_height = y + self.height
        if Rock.col_height < new_height:
            for col in range(len(Rock.column)):
                Rock.column[col] = Rock.column[col] + ["."] * (
                    (new_height - Rock.col_height)
                )
            Rock.col_height = new_height
        for row in range(len(self.pattern)):
            p = self.pattern[self.height - row - 1]
            for col in range(len(p)):
                if p[col] != "#":
                    continue
                Rock.column[x + col][y + row] = "#"


with open("input.txt") as infile:
    gas = infile.readline()

nextGas = 0


def addRock(rock: Rock):
    x = 2
    y = Rock.col_height + 3
    global nextGas
    while True:
        dir = gas[nextGas]
        print("dir: ", dir)
        nextGas = (nextGas + 1) % len(gas)
        if dir == ">":
            if not rock.hit(x + 1, y):
                x += 1
        else:
            if not rock.hit(x - 1, y):
                x -= 1

        if rock.hit(x, y - 1):
            rock.settle(x, y)
            break
        y -= 1


def main():
    rock1 = Rock(["####"])
    rock2 = Rock([".#.", "###", ".#."])
    rock3 = Rock(["..#", "..#", "###"])
    rock4 = Rock(["#"] * 4)
    rock5 = Rock(["##", "##"])
    rocks = [rock1, rock2, rock3, rock4, rock5]
    rockNum = 0
    for i in range(2022):
        addRock(rocks[rockNum])
        # visualize the shape using numpy array
        print(np.rot90(np.array(Rock.column)))
        rockNum = (rockNum + 1) % len(rocks)
    print(Rock.col_height)  # part1: 3100

    # print(np.rot90(np.array(Rock.column)))
main()
