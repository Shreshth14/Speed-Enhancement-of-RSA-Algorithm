import math
import time
st=time.time()
n=1000004416000376623
for i in range(2,math.ceil(math.sqrt(n))):
    if(n%i==0):
        print(i,n/i)
        break
print(time.time()-st)

