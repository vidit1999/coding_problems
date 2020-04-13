# Write a quick password validator to make sure that the people that visit your site use appropriate passwords.

# Respond with "VALID" if the string meets the requirements or "INVALID" if it does not.

# Requirements:
# More than 3 characters but less than 20.
# Must contain only alphanumeric characters.
# Must contain letters and numbers.

# Examples
# 'Username123!' => INVALID
# '123' => INVALID
# 'Username123' => VALID

# Tests
# 'Username'
# 'IsThisPasswordTooLong'
# 'DEVCommunity'

def passwordValidator(password : str) -> str:
    if(3 < len(password) < 20):
        if(password.isalnum()):
            if(any(map(str.isdigit, password)) and any(map(str.isalpha, password))):
                return "VALID"
    return "INVALID"

print(passwordValidator('Username123!')) # output -> INVALID
print(passwordValidator('123')) # output -> INVALID
print(passwordValidator('Username123')) # output -> VALID
print(passwordValidator('Username')) # output -> INVALID
print(passwordValidator('IsThisPasswordTooLong')) # output -> INVALID
print(passwordValidator('DEVCommunity')) # output -> INVALID