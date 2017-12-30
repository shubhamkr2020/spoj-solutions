def gcd(x, y):
    while y != 0:
        (x, y) = (y, x % y)
    return x


t = int(input())

while t>0:
    a,b = input().split()
    a,b = [int(a),int(b)]
    ans = gcd(a,b)
    print (ans)
    t=t-1
