from math import factorial

def calc(n):
    sum_val = 0
    for i in range(1, n + 1):
        if i % 2 == 1:
            sum_val += factorial(i)
        else:
            sum_val -= factorial(i)
    return sum_val

def main():
    n = int(input())
    print(calc(n))

if __name__ == "__main__":
    main()
