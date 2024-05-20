def power(x,n):
    if n==0:
        return 1
    elif n%2==0:
        half=power(x,n//2)
        return half*half
    else:
        half=power(x,(n-1)//2)
        return half*half*x

if __name__=='__main__':
    ret = power(2,10)
    print('my ret',ret)