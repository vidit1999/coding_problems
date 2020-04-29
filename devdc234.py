# It can be really uncomfortable to talk about your age when you get older.
# Sometimes you just want to be twenty again! Well, with some math magic that's totally
# possible - just select the correct number base. For example, if they are turning 32, that's 20 in base 16!

# Translate the given age to the desired 20 or 21 years, and indicate the number base, in the format specified below.

# Note: input will be always > 21

# Examples:
# 32 --> "20, in base 16"
# 39 --> "21, in base 19"

# Tests:
# a, b; where a is the age of the person, b is the desired age.
# 50, 20
# 50, 21
# 43, 20
# 66, 21

# checks if age can be translated to 20 or 21
def isPossible(age : int, changedAge : int) -> bool:
    return age > 21 and age%2 == changedAge%2

# translates given age to 20 or 21 and prints the base
def translateAge(age : int):
    if(age > 21):
        return str(20 + age%2) + ", in base " + str(age//2)
    return "Not possible to translate"


print(translateAge(39)) # output -> 21, in base 19
print(translateAge(32)) # output -> 20, in base 16
print(translateAge(50)) # output -> 20, in base 25
print(translateAge(20)) # output -> Not possible to translate

print(isPossible(50, 20)) # output -> True
print(isPossible(50, 21)) # output -> False
print(isPossible(43, 20)) # output -> False
print(isPossible(66, 21)) # output -> False
