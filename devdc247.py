# The function is not returning the correct values. Can you figure out why?
# def get_planet_name(id):
    # This doesn't work; Fix it!
    # name=""
    # switch id:
        # case 1: name = "Mercury"
        # case 2: name = "Venus"
        # case 3: name = "Earth"
        # case 4: name = "Mars"
        # case 5: name = "Jupiter"
        # case 6: name = "Saturn"
        # case 7: name = "Uranus"  
        # case 8: name = "Neptune"
    # return name
# Example
# get_planet_name(3) # should return 'Earth'

# Tests
# get_planet_name(3)
# get_planet_name(8)
# get_planet_name(1)
# get_planet_name(5)

def get_planet_name(id):
    return (
        {
            1: "Mercury",
            2: "Venus",
            3: "Earth",
            4: "Mars",
            5: "Jupiter",
            6: "Saturn",
            7: "Uranus"  ,
            8: "Neptune"
        }
    ).get(id, "Not valid id")

print(get_planet_name(3)) # output -> Earth
print(get_planet_name(8)) # output -> Neptune
print(get_planet_name(1)) # output -> Mercury
print(get_planet_name(0)) # output -> Not valid id