# Now, Dasher! Now, Dancer! Now, Prancer, and Vixen! On, Comet! On, Cupid! On,
# Donder and Blitzen! That's the order Santa wanted his reindeer...right?
# What do you mean he wants them in order by their last names!? Looks like we need your help!

# Write a function that accepts a sequence of Reindeer names,
# and returns a sequence with the Reindeer names sorted by their last names.

# Example
# for this input:
# [
  # "Dasher Tonoyan", 
  # "Dancer Moore", 
  # "Prancer Chua", 
  # "Vixen Hall", 
  # "Comet Karavani",        
  # "Cupid Foroutan", 
  # "Donder Jonker", 
  # "Blitzen Claus"
# ] 
# you should return this output:
# [
  # "Prancer Chua",
  # "Blitzen Claus",
  # "Cupid Foroutan", 
  # "Vixen Hall", 
  # "Donder Jonker", 
  # "Comet Karavani",
  # "Dancer Moore", 
  # "Dasher Tonoyan",
# ] 

# Tests
# sort_reindeer(['Kenjiro Mori', 'Susumu Tokugawa', 'Juzo Okita', 'Akira Sanada']),
# ['Kenjiro Mori', 'Juzo Okita', 'Akira Sanada', 'Susumu Tokugawa'])

# sort_reindeer(['Yasuo Kodai', 'Kenjiro Sado', 'Daisuke Aihara', 'Susumu Shima', 'Akira Sanada',
# 'Yoshikazu Okita', 'Shiro Yabu', 'Sukeharu Nanbu', 'Sakezo Yamamoto', 'Hikozaemon Ohta',
# 'Juzo Mori', 'Saburo Tokugawa']),
# ['Daisuke Aihara', 'Yasuo Kodai', 'Juzo Mori', 'Sukeharu Nanbu',
# 'Hikozaemon Ohta', 'Yoshikazu Okita', 'Kenjiro Sado', 'Akira Sanada',
# 'Susumu Shima', 'Saburo Tokugawa', 'Shiro Yabu', 'Sakezo Yamamoto'])

def sort_reindeer(reindeer : list) -> list:
    return sorted(reindeer, key=lambda x : x.split()[-1])

print(sort_reindeer([
  "Dasher Tonoyan", 
  "Dancer Moore", 
  "Prancer Chua", 
  "Vixen Hall", 
  "Comet Karavani",        
  "Cupid Foroutan", 
  "Donder Jonker", 
  "Blitzen Claus"
]))