class TextEditor:

    def __init__(self):
        self.string = ""
        self.ptr = 0

    def addText(self, text: str) -> None:
        self.string = self.string[:self.ptr]+text+self.string[self.ptr:]
        self.ptr += len(text)

    def deleteText(self, k: int) -> int:
        l = max(0, self.ptr-k)
        self.string = self.string[:l]+self.string[self.ptr:]
        res = self.ptr-l
        self.ptr = l
        return res

    def cursorLeft(self, k: int) -> str:
        self.ptr = max(0, self.ptr-k)
        return self.string[max(0, self.ptr-10):self.ptr]

    def cursorRight(self, k: int) -> str:
        self.ptr = min(len(self.string), self.ptr+k)
        return self.string[max(0, self.ptr-10):self.ptr]


if __name__ == "__main__":
    te = TextEditor()
    op = ["addText","deleteText","addText","cursorRight","cursorLeft","deleteText","cursorLeft","cursorRight"]
    adds = ["leetcode","practice"]
    nums = [4,3,8,10,2,6]
    a,n = 0,0
    for o in op:
        if o == "addText":
            te.addText(adds[a])
            a += 1
        elif o == "deleteText":
            print(te.deleteText(nums[n]))
            n += 1
        elif o == "cursorRight":
            print(te.cursorRight(nums[n]))
            n += 1
        else:
            print(te.cursorLeft(nums[n]))
            n += 1
