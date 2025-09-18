class Spreadsheet:

    def __init__(self, rows: int):
        self.excel = {}

    def setCell(self, cell: str, value: int) -> None:
        self.excel[cell] = value

    def resetCell(self, cell: str) -> None:
        self.excel[cell] = 0

    def getValue(self, formula: str) -> int:
        formula = formula.strip("=").split("+")
        for i in range(2):
            if formula[i][0] >= "A" and formula[i][1] <= "Z":
                formula[i] = self.excel.get(formula[i], 0)
            else:
                formula[i] = int(formula[i])
        return formula[0]+formula[1]

if __name__ == "__main__":
    rows = 3
    s = Spreadsheet(rows)
    op = ["getValue","setCell","getValue","setCell","getValue","resetCell","getValue"]
    num = [["=5+7"],["A1",10],["=A1+6"],["B2",15],["=A1+B2"],["A1"],["=A1+B2"]]
    for i in range(len(op)):
        if op[i] == "getValue":
            print(s.getValue(num[i][0]))
        if op[i] == "setCell":
            s.setCell(num[i][0], num[i][1])
        else:
            s.resetCell(num[i][0])
