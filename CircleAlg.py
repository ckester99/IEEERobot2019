def make_pi():
    q, r, t, k, m, x = 1, 0, 1, 1, 3, 3
    for j in range(1000):
        if 4 * q + r - t < m * t:
            yield m
            q, r, t, k, m, x = 10*q, 10*(r-m*t), t, k, (10*(3*q+r))//t - 10*m, x
        else:
            q, r, t, k, m, x = q*k, (2*q+r)*x, t*x, k+1, (q*(7*k+2)+r*x)//(t*x), x+2

def getDist(carosel,PIarr,i):
	fwd = abs(carosel.index(PIarr[i+1]) - carosel.index(PIarr[i]))
	bwd = 10-fwd
	if fwd > bwd:
		return fwd
	else:
		return bwd
			
def permutation(lst):
  
    # If lst is empty then there are no permutations 
    if len(lst) == 0: 
        return [] 
  
    # If there is only one element in lst then, only 
    # one permuatation is possible 
    if len(lst) == 1: 
        return [lst] 
  
    # Find the permutations for lst if there are 
    # more than 1 characters 
  
    l = [] # empty list that will store current permutation
    
  
    # Iterate the input(lst) and calculate the permutation 
    for i in range(len(lst)): 
       m = lst[i] 
  
       # Extract lst[i] or m from the list.  remLst is 
       # remaining list 
       remLst = lst[:i] + lst[i+1:] 
  
       # Generating all permutations where m is first 
       # element 
       for p in permutation(remLst): 
           l.append([m] + p) 
    return l 
			
PIarr = []

for i in make_pi():
    PIarr.append(int(i))

#first 233 digits
caroselArr = []

for i in permutation([0,1,2,3,4,5,6,7,8,9]):
    caroselArr.append(i)
    

blocks = 60
distances = []

for i in range(len(caroselArr)):
	dist = 0
	for j in range(blocks-1):
		dist += getDist(caroselArr[i],PIarr,j)
	distances.append(dist)

print(caroselArr[distances.index(min(distances))])




