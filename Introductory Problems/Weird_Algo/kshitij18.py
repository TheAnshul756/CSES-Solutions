# recursive function to solve the problem
def solve(number):
    # base condition when the number hits 1
    if number == 1:
        print(number, end=' ')
        return

    # printing the current number
    print(number, end=' ')

    # if the number is even
    if(number % 2 == 0):
        solve(number//2)

    # if the number is odd
    elif(number % 2 != 0):
        solve(number*3+1)


# driver code
n = int(input())
solve(n)
