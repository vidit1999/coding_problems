# You work for a bank, which has recently purchased an
# ingenious machine to assist in reading letters and faxes sent in by branch offices.

# The machine scans the paper documents, and produces
# a string with a bank account that looks like this:

#     _  _     _  _  _  _  _
#   | _| _||_||_ |_   ||_||_|
#   ||_  _|  | _||_|  ||_| _|
# ... why did we buy this machine?

# Anyway, your task is to write a function that can
# take bank account string and parse it into actual account numbers.

# Example

#  _  _  _  _  _  _  _  _  _ 
# | | _| _|| ||_ |_   ||_||_|     => 23056789
# |_||_  _||_| _||_|  ||_| _|

# Tests
#  _  _  _  _  _  _  _  _  _ 
# |_| _| _||_||_ |_ |_||_||_| 
# |_||_  _||_| _||_| _||_| _|

#   _  _     _  _  _  _  _
# | _| _||_||_ |_   ||_||_|
# ||_  _|  | _||_|  ||_| _|


# stores the modified string representation of a digit
digitStringDict = {
    " _ | ||_|" : "0",
    "     |  |" : "1",
    " _  _||_ " : "2",
    " _  _| _|" : "3",
    "   |_|  |" : "4",
    " _ |_  _|" : "5",
    " _ |_ |_|" : "6",
    " _   |  |" : "7",
    " _ |_||_|" : "8",
    " _ |_| _|" : "9"
}

# takes a multiline string as input
# outputs the int representation of that
def stringToAccountNumber(account: str) -> int:
    account = account.strip("\n")
    parts = account.split("\n") # split the actual string into three strings based on new-line chracter
    numberStr = "" # stores the string representation of the number
    
    for i in range(0,len(parts[0]),3):
        numberStr += digitStringDict[parts[0][i:i+3]+parts[1][i:i+3]+parts[2][i:i+3]]
    
    return int(numberStr)


test1 = '''
 _  _  _  _  _  _  _  _  _ 
|_| _| _||_||_ |_ |_||_||_|
|_||_  _||_| _||_| _||_| _|

'''

test2 = '''
    _  _     _  _  _  _  _ 
  | _| _||_||_ |_   ||_||_|
  ||_  _|  | _||_|  ||_| _|

'''

test3 = '''
 _  _  _  _  _  _  _  _  _ 
| | _| _|| ||_ |_   ||_||_|
|_||_  _||_| _||_|  ||_| _|

'''


print(stringToAccountNumber(test1)) # output -> 823856989
print(stringToAccountNumber(test2)) # output -> 123456789
print(stringToAccountNumber(test3)) # output -> 23056789
