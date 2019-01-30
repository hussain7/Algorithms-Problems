
# fiboacci series using bottom up dynamic programming

def bottom_up(n):
    if n == 1 or n==2:
        return 1
    # array
    bottom_arr =[None]*(n+1)
    bottom_arr[1]=1
    bottom_arr[2]=1
    
    for i in range(3, n+1):
        bottom_arr[i] = bottom_arr[i-1] + bottom_arr[i-2]
    
    return bottom_arr[n]
    
print(bottom_up(8))
