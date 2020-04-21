# Let's pretend your company just hired your friend from college and
# paid you a referral bonus. Awesome! To celebrate, you're taking your team
# out to the terrible dive bar next door and using the referral bonus
# to buy, and build, the largest three-dimensional beer can pyramid you can.
# And then probably drink those beers, because let's pretend it's Friday too.

# A beer can pyramid will square the number of cans in each level - 1 can
# in the top level, 4 in the second, 9 in the next, 16, 25...

# Complete the beeramid function to return the number of complete levels of a
# beer can pyramid you can make, given the parameters of:

# 1) your referral bonus, and
# 2) the price of a beer can


# For example:
# beeramid(1500, 2); // should === 12
# beeramid(5000, 3); // should === 16

# Tests:
# beeramid(9, 2)
# beeramid(21, 1.5)
# beeramid(-1, 4)

def beeramid(bonus, price):
    canCount = int(bonus/price)
    level = 0
    
    while((level+1)**2 <= canCount):
        level += 1
        canCount -= level*level

    return level


print(beeramid(1500, 2)) # output -> 12
print(beeramid(5000, 3)) # output -> 16
print(beeramid(9, 2)) # output -> 1
print(beeramid(21, 1.5)) # output -> 3
print(beeramid(-1, 4)) # output -> 0
