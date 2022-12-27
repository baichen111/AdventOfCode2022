inputs = []
with open("input.txt") as infile:
    lines = infile.readlines()
    for line in lines:
        if line == "\n":
            continue
        inputs.append(eval(line.strip()))


def CompareList(left, right):
    if isinstance(left, int) and isinstance(right, int):
        if left < right:
            return 1
        if left == right:
            return 0
        return -1
    if isinstance(left, int) and isinstance(right, list):
        left = [left]
    if isinstance(left, list) and isinstance(right, int):
        right = [right]

    if isinstance(left, list) and isinstance(right, list):
        i = 0
        while i < len(left) and i < len(right):
            if CompareList(left[i], right[i]) == 1:
                return 1
            if CompareList(left[i], right[i]) == -1:
                return -1
            i += 1
        if i == len(left) and len(left) == len(right):
            return 0
        if i == len(left):
            return 1
        return -1


c = 0
idx = 0
for i in range(0, len(inputs), 2):
    left_list = inputs[i]
    right_list = inputs[i + 1]
    idx += 1
    if CompareList(left_list, right_list) == 1:
        c += idx
print(c)  # part1: 5003
