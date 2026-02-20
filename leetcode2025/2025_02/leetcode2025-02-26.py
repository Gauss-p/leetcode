class BrowserHistory:

    def __init__(self, homepage: str):
        self.ptr = 1
        self.web = [homepage]

    def visit(self, url: str) -> None:
        while len(self.web)>self.ptr:
            self.web.pop()
        # self.web = self.web[:self.ptr]
        self.web.append(url)
        self.ptr += 1

    def back(self, steps: int) -> str:
        self.ptr = max(1, self.ptr-steps)
        return self.web[self.ptr-1]

    def forward(self, steps: int) -> str:
        self.ptr = min(len(self.web), self.ptr+steps)
        return self.web[self.ptr-1]

if __name__ == "__main__":
    ops = ["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
    visits = ["leetcode.com","google.com","facebook.com","youtube.com","linkedin.com"]
    fb = [1,1,1,2,2,7]
    v,f = 0,0
    for op in ops:
        if op == "BrowserHistory":
            bh = BrowserHistory(visits[v])
            v += 1
        elif op == "visit":
            bh.visit(visits[v])
            v += 1
        elif op == "back":
            print(bh.back(fb[f]))
            f += 1
        else:
            print(bh.forward(fb[f]))
            f += 1

