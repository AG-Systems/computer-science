vowelcounter = 0
s = 'azcbobobegghakl'
vowels_list = ["a", "e", "u", "i", "o"]
for x in s:
    if any(item.lower() == x for item in vowels_list):
        vowelcounter += 1
print vowelcounter
