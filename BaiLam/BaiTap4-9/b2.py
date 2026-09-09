T = 1

for _ in range(T):
   A, B = input().split()
   minA = A.replace('6', '5')
   minB = B.replace('6', '5')

   maxA = A.replace('5', '6')
   maxB = B.replace('5', '6')

   print(int(minA) + int(minB), int(maxA) + int(maxB))