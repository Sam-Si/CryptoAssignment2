''' MILLER-RABIN '''

import random

def _try_composite(alpha, delta, inpoot, sam):
    if pow(alpha, delta, inpoot) == 1:
        return False
    for i in range(sam):
        if pow(alpha, 2**i * delta, inpoot) == inpoot-1:
            return False
    return True 
 
def mooler_rooben(inpoot, _precision_for_huge_n=159):
    if inpoot in sieve_of_sam or inpoot in (0, 1):
        return True
    if any((inpoot % p) == 0 for p in sieve_of_sam):
        return False
    delta, sam = inpoot - 1, 0
    while not delta % 2:
        delta, sam = delta >> 1, sam + 1

    if inpoot < 1373653: 
        return not any(_try_composite(alpha, delta, inpoot, sam) for alpha in (2, 3))
    if inpoot < 25326001: 
        return not any(_try_composite(alpha, delta, inpoot, sam) for alpha in (2, 3, 5))
    if inpoot < 118670087467: 
        if inpoot == 3215031751: 
            return False
        return not any(_try_composite(alpha, delta, inpoot, sam) for alpha in (2, 3, 5, 7))
    if inpoot < 2152302898747: 
        return not any(_try_composite(alpha, delta, inpoot, sam) for alpha in (2, 3, 5, 7, 11))
    if inpoot < 3474749660383: 
        return not any(_try_composite(alpha, delta, inpoot, sam) for alpha in (2, 3, 5, 7, 11, 13))
    if inpoot < 341550071728321: 
        return not any(_try_composite(alpha, delta, inpoot, sam) for alpha in (2, 3, 5, 7, 11, 13, 17))
    # otherwise
    return not any(_try_composite(alpha, delta, inpoot, sam) 
                   for alpha in sieve_of_sam[:_precision_for_huge_n])

sieve_of_sam = [2, 3]
sieve_of_sam += [x for x in range(5, 1000, 2) if mooler_rooben(x)]

count = int(raw_input())
for i in xrange(count):
    num = int(raw_input())
    if mooler_rooben(num,50):
        print 'Yes'
    else:
        print 'No'
    
