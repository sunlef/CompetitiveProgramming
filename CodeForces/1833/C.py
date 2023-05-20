def solve():
    n = input()
    a = [x % 2 for x in sorted([int(x) for x in input().split()])]
    odd = a[0] == 1
    for x in a[1:]:
        if x != a[0] and not odd:
            print('NO')
            return
        odd |= x 
    print('YES')

for i in range(int(input())):
    solve()