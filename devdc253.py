# Given a standard English sentence passed as a string, write a method that will return
# that sentence but with the words sorted by first letter.

# All words that begin with a lower case letter should be at the beginning of the sorted sentence,
# and sorted in ascending order. All words that begin with an upper case letter should come after that,
# and should be sorted in descending order.

# If a word appears multiple times in the sentence, it should be returned multiple times.
# Any punctuation can be discarded.

# Example
# input: "Land of the Old Thirteen! Massachusetts land! land of Vermont and Connecticut!"
# return: "and land land of of the Vermont Thirteen Old Massachusetts Land Connecticut"
# Lower case letters are sorted a -> l -> l -> o -> o -> t
# Upper case letters are sorted V -> T -> O -> M -> L -> C.

# Tests
# sort("take up the task eternal, and the burden and the lesson")
# sort("Pioneers, O Pioneers!")

from string import punctuation

def sort(s):
    lowerStart = []
    upperStart = []

    for word in ''.join(c for c in s if c not in punctuation).split():
        if(word[0].islower()):
            lowerStart.append(word)
        elif(word[0].isupper()):
            upperStart.append(word)

    return ' '.join(sorted(lowerStart) + sorted(upperStart, reverse=True))

print(sort("Land of the Old Thirteen! Massachusetts land! land of Vermont and Connecticut!")) # output -> 'and land land of of the Vermont Thirteen Old Massachusetts Land Connecticut'
print(sort("take up the task eternal, and the burden and the lesson")) # output -> 'and and burden eternal lesson take task the the the up'
print(sort("Pioneers, O Pioneers!")) # output -> 'Pioneers Pioneers O'
