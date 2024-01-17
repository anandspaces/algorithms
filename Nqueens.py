# n queens
# still issue
def printSolution(a,n):
    for i in range(n):
        print("|")
        for j in range(n):
            print(f"{a[i][j]} ", end="")
        print("|\n")

def isSafe(a,row,col,n):
    i,j = 0,0
    while i < col:
        if a[row][i]:
            return False
        i += 1
    i,j = 0,0
    while i < row and j < col:
        if a[i][j]:
            return False
        i += 1
        j += 1
    i,j = n - 1,0
    while i > row and j < col:
        if a[i][j]:
            return False
        i -= 1
        j += 1
    return True

def solve(a,col,n):
    if col == n:
        # printSolution(a, n)
        return 1
    count = 0
    for row in range(n):
        if isSafe(a,row,col,n):
            a[row][col] = 1
            count += solve(a,col + 1,n)
            a[row][col] = 0  # backtrack
    return count

if __name__ == "__main__":
    n = 8
    a = [[0] * n for _ in range(n)]
    print(f"Total number of solutions = {solve(a, 0, n)}")
