# You might already be familiar with many smartphones that allow you to use a geometric pattern as a security measure.
# To unlock the device, you need to connect a sequence of dots/points in a grid by swiping your finger without lifting
# it as you trace the pattern through the screen.
# The image below has an example pattern of 7 dots/points: [A, B, I, E, D, G, C].

# lockscreen

# Your job is to implement the function countPatternsFrom(firstPoint, length);
# where firstPoint is a single-character string corresponding to the point
# in the grid (i.e.: 'A') and length is an integer indicating the length of the pattern.
# The function must return the number of combinations starting from the given point, that have the given length.

# Take into account that dots can only be connected with straight directed lines either:

# horizontally (like A to B)
# vertically (like D to G),
# diagonally (like I and E, as well as B and I), or
# passing over a point that has already been 'used' like (G and C passing over E).

# Examples
# countPatternsFrom('B', 1), 1
# countPatternsFrom('C', 2), 5

# Tests
# countPatternsFrom('D', 3)
# countPatternsFrom('E', 4)
# countPatternsFrom('E', 8)

from collections import defaultdict

notDirect = defaultdict(lambda : False)

notDirect[('A', 'C')] = notDirect[('A', 'C')] = 'B'
notDirect[('A', 'G')] = notDirect[('G', 'A')] = 'D'
notDirect[('G', 'I')] = notDirect[('I', 'G')] = 'H'
notDirect[('C', 'I')] = notDirect[('I', 'C')] = 'F'


notDirect[('A', 'I')] = notDirect[('I', 'A')] = \
notDirect[('B', 'H')] = notDirect[('H', 'B')] = \
notDirect[('C', 'G')] = notDirect[('G', 'C')] = \
notDirect[('D', 'F')] = notDirect[('F', 'D')] = 'E'

def countPatternsFromHelper(visit: defaultdict, pos: str, length: int) -> int:
    if(length <= 0):
        return (1 if length == 0 else 0)
    ways = 0
    visit[pos] = True

    for c in ['A','B','C','D','E','F','G','H','I']:
        if(not visit[c] and (notDirect[(c, pos)] == False or visit[notDirect[(c, pos)]])):
            ways += countPatternsFromHelper(visit, c, length - 1)
    return ways

def countPatternsFrom(pos: str, length: int) -> int:
    visit = defaultdict(lambda : False)
    return countPatternsFromHelper(visit, pos, length-1)

print(countPatternsFrom('B', 1))
print(countPatternsFrom('C', 2))
print(countPatternsFrom('D', 3))
print(countPatternsFrom('E', 4))
print(countPatternsFrom('E', 8))
