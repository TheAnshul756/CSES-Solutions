# recursive function to solve the problem
def solve(number):
    if number == 1:
        print(number, end=' ')
        return

    print(number, end=' ')
    if(number % 2 == 0):
        solve(number//2)
    elif(number % 2 != 0):
        solve(number*3+1)


# driver code
n = int(input())
solve(n)
