def power(x,n):
    result = 1
    while n>0:
        if n%2==1:
            result = result*x
        x=x*x
        n=n//2
    return result

if __name__=='__main__':
    ret = power(2,10)
    print('2 power 10 equal to:',ret)
    
