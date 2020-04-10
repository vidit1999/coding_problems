# We recommend you drink 1 glass of water per drink so you're not hungover tomorrow morning.
# Your fellow coders have bought you several drinks tonight in the form of strings.
# Return a string suggesting how many glasses of water you should drink to not be hungover.

# If you would like to keep things simple, you can consider any "numbered thing" in
# the string to be a drink.
# Even "1 bear" => "1 glass of water" or "1 chainsaw and 2 pools" => "3 glasses of water".

# Example Pairs

# Input 0:
# "1 beer"
# Output 0:
# "1 glass of water"

# Input 1:
# "1 shot, 5 beers, 2 shots, 1 glass of wine, 1 beer"
# Output 1:
# "10 glasses of water"

# Tests
# hydrate("1 beer")
# hydrate("2 glasses of wine and 1 shot")
# hydrate("1 shot, 5 beers, 2 shots, 1 glass of wine, 1 beer")

import re

def hydrate(drinks: str) -> str:
    drinkCount = sum(map(int, re.findall("\d+", drinks))) # total number of drinks
    # this will also work, drinkCount = sum([int(num) for num in drinks.split(" ") if num.isdigit()])
    
    return str(drinkCount) + " glass" + ("es" if drinkCount > 1 else "") + " of water"


print(hydrate("1 beer")) # output -> 1 glass of water
print(hydrate("2 glasses of wine and 1 shot")) # output -> 3 glasses of water
print(hydrate("1 shot, 5 beers, 2 shots, 1 glass of wine, 1 beer")) # output -> 10 glasses of water
