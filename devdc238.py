# The range of vision of a digit is equal to its own value.
# 1 can see one digit to the left and one digit to the right,
# 2 can see two digits, and so on.

# Thus, the loneliness of a digit is the sum of the digits which it can see.

# Given a non-negative integer, your function
# must determine the loneliest number in the string.

# Example
# number = 34315
# digit   can see on the left     can see on the right    loneliness
# 3         -                     4, 3, 1            4 + 3 + 1 = 8
# 4         3                     3, 1, 5            3 + 3 + 1 + 5 = 12
# 3         3, 4                  1, 5                   3 + 4 + 1 + 5 = 13
# 1         3                       5                3 + 5 = 8
# 5        3431                    -                 3 + 4 + 3 + 1 = 11
# 1 is the loneliest number, since it has the least friends and the lowest score.

# Tests
# lonelyNum(23456)
# lonelyNum(42435)

def lonelyNum(number : int) -> int:
    digits = list(map(int, str(number)))
    loneliest = digits[0]
    min_loneliness = min_friends = float('inf')

    for i in range(len(digits)):
        left_friends = digits[max(0,i-digits[i]):i]
        right_friends = digits[i+1:min(len(digits),i+1+digits[i])]

        loneliness = sum(left_friends+right_friends)
        friend_count = len(left_friends+right_friends)

        if(loneliness < min_loneliness):
            loneliest = digits[i]
            min_loneliness = loneliness
            min_friends = friend_count
        elif(loneliness == min_loneliness and friend_count < min_friends):
            loneliest = digits[i]
            min_friends = friend_count
    
    return loneliest


print(lonelyNum(34315)) # output -> 1
print(lonelyNum(23456)) # output -> 2
print(lonelyNum(42435)) # output -> 2