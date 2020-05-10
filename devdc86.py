# This challenge is for all those times your mouth said something your brain didn't tell it to.

# Write a function that will find a misspoken word in your speech using the following words:

# are - aren't
# can - can't
# could - couldn't
# did - didn't
# do - don't
# had - hadn't
# has - hasn't
# have - haven't
# is - isn't
# might - mightn't
# must - mustn't
# should - shouldn't
# was - wasn't
# were - weren't
# would - wouldn't

# Add or remove the suffix n't where needed. Beware of the word "can" and extra suffixes like 've.

# speech:
# I do like pizza.
# I haven't seen you wearing that hat before.
# I could see why you would say that.
# I didn't say it! It wasn't me!
# YES, WE CAN

def bidirectional_mapper() -> dict:
    words = {
    'are' : "aren't",
    'can' : "can't",
    'could' : "couldn't",
    'did' : "didn't",
    'do' : "don't",
    'had' : "hadn't",
    'has' : "hasn't",
    'have' : "haven't",
    'is' : "isn't",
    'might' : "mightn't",
    'must' : "mustn't",
    'should' : "shouldn't",
    'was' : "wasn't",
    'were' : "weren't",
    'would' : "wouldn't"
    }
    bidict = {}
    for k, v in words.items():
        bidict[k] = v
        bidict[v] = k
    return bidict

def misspoken(speech : str) -> str:
    words = speech.split()
    bidict = bidirectional_mapper()
    for i in range(len(words)):
        if words[i].lower() in bidict:
            words[i] = (str.upper if words[i].isupper() else str.lower)(bidict[words[i].lower()])
    return ' '.join(words)

print(misspoken("I do like pizza."))
print(misspoken("I haven't seen you wearing that hat before."))
print(misspoken("I could see why you would say that."))
print(misspoken("I didn't say it! It wasn't me!"))
print(misspoken("YES, WE CAN"))