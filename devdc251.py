# In a six digit (or larger) number, locate the greatest sequence
# of five consecutive digits found within the number given.

# Example
# In the following 10 digit number:
# 1234567890
# 67890 is the greatest sequence of 5 consecutive digits.

# Tests
# digit5(7316717)
# digit5(1234567898765)

def digit5(number : str) -> int:
    return max(int(number[i:i+5]) for i in range(len(number)-4))   

print(digit5("1234567890")) # output -> 67890
print(digit5("7316717")) # output -> 73167
print(digit5("123456")) # output -> 23456
print(digit5("1234567898765")) # output -> 98765