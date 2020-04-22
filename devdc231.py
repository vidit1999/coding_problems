# A perfect power is a classification of positive integers:

# In mathematics, a perfect power is a positive integer that can be expressed as
# an integer power of another positive integer. More formally, n is a perfect power
# if there exist natural numbers m > 1, and k > 1 such that mk = n.

# Your task is to check whether a given integer is a perfect power. If it is a perfect power,
# return a pair m and k with mk = n as a proof.
# Otherwise return Nothing, Nil, null, NULL, None or your language's equivalent.

# Note: For a perfect power, there might be several pairs.
# For example 81 = 3^4 = 9^2, so (3,4) and (9,2) are valid solutions.
# If a number is a perfect power, return any pair that proves it.

# Examples
# isPP(4) => [2,2]
# isPP(9) => [3,2]
# isPP(5) => None

# Tests
# isPP(4)
# isPP(8)
# isPP(14)

import math

def isPP(number : int) -> tuple:
    if(number > 3):
        for i in range(2, int(math.sqrt(number))+1):
            power = round(math.log(number)/math.log(i), 4)
            if power.is_integer():
                return (i, int(power))

print(isPP(4)) # output -> (2, 2)
print(isPP(9)) # output -> (3, 2)
print(isPP(5)) # output -> None
print(isPP(4)) # output -> (2, 2)
print(isPP(8)) # output -> (2, 3)
print(isPP(14)) # output -> None
print(isPP(184528125)) # output -> (45, 5)