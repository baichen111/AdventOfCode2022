class Monkey:
    def __init__(self, items: list, op: str, opNum: int, divNum: int):
        self.items = items
        self.op = op
        self.opNum = opNum
        self.divNum = divNum
        self.v = []

    def operation(self, item):
        if self.op == "+":
            if self.opNum == -1:
                return item + item
            return item + self.opNum
        else:
            if self.opNum == -1:
                return item * item
            return item * self.opNum

    def test(self, m1, m2):
        if len(self.items) == 0:
            return
        while not len(self.items) == 0:
            item = self.items.pop(0)
            self.v.append(item)
            d = int(self.operation(item) / 3)
            if d % self.divNum == 0:
                m1.items.append(d)
            else:
                m2.items.append(d)

m0 = Monkey([89, 84, 88, 78, 70], "*", 5, 7)
m1 = Monkey([76, 62, 61, 54, 69, 60, 85], "+", 1, 17)
m2 = Monkey([83, 89, 53], "+", 8, 11)
m3 = Monkey([95, 94, 85, 57], "+", 4, 13)
m4 = Monkey([82, 98], "+", 7, 19)
m5 = Monkey([69], "+", 2, 2)
m6 = Monkey([82, 70, 58, 87, 59, 99, 92, 65], "*", 11, 5)
m7 = Monkey([91, 53, 96, 98, 68, 82], "*", -1, 3)
for i in range(20):
    m0.test(m6, m7)
    m1.test(m0, m6)
    m2.test(m5, m3)
    m3.test(m0, m1)
    m4.test(m5, m2)
    m5.test(m1, m3)
    m6.test(m7, m4)
    m7.test(m4, m2)
print(len(m0.v))
print(len(m1.v))
print(len(m2.v))
print(len(m3.v))
print(len(m4.v))
print(len(m5.v))
print(len(m6.v))
print(len(m7.v))
# part1: 238 * 235 = 55930
