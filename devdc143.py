# Doing arithmetic with big numbers is impossible to do with regular integer types.
# In JavaScript (which represents numbers as 64-bit floats), anything beyond 253-1
# becomes increasingly less accurate.

# Write a two functions (bigAdd and bigSub) to accurately represent these large integers as strings.
# They will both take two arguments: either a valid representation of an integer as a string,
# or a regular number. They will return the correct answer as a string. bigAdd will sum, bigSub will subtract.

# For example:
# bigAdd(1, "123456789012345678901234567890") === "123456789012345678901234567891";
# bigSub("123456789012345678901234567890", 1) === "123456789012345678901234567889";

# Remember, the values could be negative, and so the calculations should be made accordingly.
# bigAdd(-1, "123456789012345678901234567890") === "123456789012345678901234567889";
# bigSub("123456789012345678901234567890", -1) === "123456789012345678901234567891";

def bigAdd(num1, num2):
    return str(int(num1) + int(num2))

def bigSub(num1, num2):
    return str(int(num1) - int(num2))

print(bigAdd(1, "123456789012345678901234567890"))
print(bigSub("123456789012345678901234567890", 1))
print(bigAdd(-1, "123456789012345678901234567890"))
print(bigSub("123456789012345678901234567890", -1))