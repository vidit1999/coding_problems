# Alcuin of York was an English clergyman and scholar who wrote,
# among other things, recreational mathematical problems.

# One of them goes as follows: A merchant wanted to buy 100 pigs for 100 pence.
# He told his servant to go and buy them, paying 10 pence for a boar,
# 5 pence for a sow and 1 penny for two piglets. He also told him to buy at least one of each.
# How many boars, sows, and piglets must there have been for him to have paid exactly 100 pence for the 100 animals?

# In this challenge, you are going to create a function buyPigs that takes two arguments.

# amount: both the amount of money to buy animals and the number of animals that must be bought.
# specs an object indicating how much the merchant is willing to pay for each kind of animal.
# It will always have the following structure:
#   boar: { price: Number, qty: Number },
#   sow: { price: Number, qty: Number },
#   piglet: { price: Number, qty: Number },
# The function will find a combination of pigs such that:

# There is at least one of each kind of pig
# The amount of pigs equals the amount of pennies It will return an object
# indicating the amount of pigs of each kind that the servant bought.
# If there is no way to solve it, it will instead return
# the object { error: 'Purchase not possible' }
# If there are more than one ways to resolve it, it only needs to return one.

# Examples:

# const pigs = {
#   boar: { price: 10, qty: 1 },
#   sow: { price: 5, qty: 1 },
#   piglet: { price: 1, qty: 2},
# }

# buyPigs(100, pigs) => { boar: 1, sow: 9, piglet: 90 }
# buyPigs(150, pigs) => { error: 'Purchase not possible' }
# buyPigs(300, pigs) => { boar: 3, sow: 27, piglet: 270 }
# const pigs2 = {
#   boar: { price: 5, qty: 1 },
#   sow: { price: 1, qty: 1 },
#   piglet: { price: 1, qty: 8 },
# }

# buyPigs(100, pigs2) => { boar: 7, sow: 61, piglet: 32 }
# buyPigs(41, pigs2) => { boar: 7, sow: 2, piglets: 32 }


# amount : amount of pennies
# pigs : dict according to the structure of specs
#       Example:
#       pigs = {
#           'boar': { 'price': 10, 'qty': 1 },
#           'sow': { 'price': 5, 'qty': 1 },
#           'piglet': { 'price': 1, 'qty': 2}
#       }
def buyPigs(amount: int, pigs: dict) -> dict:
    oneBoarPrice = pigs['boar']['price'] / pigs['boar']['qty']
    oneSowPrice = pigs['sow']['price'] / pigs['sow']['qty']
    onePigletPrice = pigs['piglet']['price'] / pigs['piglet']['qty']

    # i : number of boar he can buy
    # j : number of sow he can buy
    # k : number of piglet he can buy
    for i in range(1, int(min(amount-2, amount/oneBoarPrice))):
        for j in range(1, int(min(amount-2, amount/oneSowPrice))):
            for k in range(1, int(min(amount-2, amount/onePigletPrice))):
                # Given that, the amount of pigs equals the amount of pennies
                # so (i+j+k) == amount
                # And, calculated total price == amount
                if i+j+k == amount == (oneBoarPrice*i + oneSowPrice*j + onePigletPrice*k):
                    return {'boar': i, 'sow': j, 'piglet': k}
    
    # if no case found then return this
    return {'error': 'Purchase not possible'}



pigs = {
    'boar': { 'price': 10, 'qty': 1 },
    'sow': { 'price': 5, 'qty': 1 },
    'piglet': { 'price': 1, 'qty': 2}
}

pigs2 = {
  'boar': { 'price': 5, 'qty': 1 },
  'sow': { 'price': 1, 'qty': 1 },
  'piglet': { 'price': 1, 'qty': 8 }
}

print(buyPigs(100, pigs)) # output -> {'boar': 1, 'sow': 9, 'piglet': 90}
print(buyPigs(150, pigs)) # output -> {'boar': 6, 'sow': 4, 'piglet': 140}
print(buyPigs(300, pigs)) # output -> {'boar': 3, 'sow': 27, 'piglet': 270}

print(buyPigs(100, pigs2)) # output -> {'boar': 7, 'sow': 61, 'piglet': 32}
print(buyPigs(41, pigs2)) # output -> {'boar': 7, 'sow': 2, 'piglet': 32}