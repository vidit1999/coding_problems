# This rgb function is incomplete. Complete it so that passing in RGB decimal
# values will result in a hexadecimal representation being returned.
# Valid decimal values for RGB are 0 - 255.
# Any values that fall out of that range must be rounded to the closest valid value.

# The following are examples of expected output values:

# rgb(255, 255, 255) # returns FFFFFF
# rgb(255, 255, 300) # returns FFFFFF
# rgb(0,0,0) # returns 000000
# rgb(148, 0, 211) # returns 9400D3

# Tests:
# rgb(-20,275,125)
# rgb(255,255,255)

def rgb(r, g, b):
    return ('{:02x}'*3).format(*map(lambda x : max(0, min(255, x)), (r, g, b))).upper()


print(rgb(255, 255, 300)) # output -> FFFFFF
print(rgb(0,0,0)) # output -> 000000
print(rgb(148, 0, 211)) # output -> 9400D3
print(rgb(-20,275,125)) # output -> 00FF7D
print(rgb(255, 255, 255)) # output -> FFFFFF
