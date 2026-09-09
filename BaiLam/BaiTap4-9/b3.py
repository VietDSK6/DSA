T = int(input())

for _ in range(T):
    N = int(input())
    A = list(map(int, input().split()))
    
    A.sort()
    a = ""
    b = ""
    for x in A:
        if x == 0:
            continue
        if len(a) < len(b):
            a += str(x)
        else:
            b += str(x)
            
    print(int(a) + int(b))