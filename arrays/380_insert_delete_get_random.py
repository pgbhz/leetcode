"""
which data structure gives us random access to it's members ? idk
this smells like a linked list ... my nose keeps tricking me

ok so we basically can generate a random number
the trick is then to have two data structures coexisting:
a hashmap
and a list of keys

but how do we have quick access to the key to be deleted ? i mean, how we quickly update the list after key removal ?
we swap the key with the last element of the list, but how do we find the key quickly ? i guess this would take linear traversal ...

we need to keep track of the keys...
"""

from random import randint


class RandomizedSet:

    def __init__(self):
        self.values = {}
        self.keys = []

    def insert(self, val: int) -> bool:
        if val in self.values:
            return False
        self.values[val] = len(self.keys)
        self.keys.append(val)
        return True

    def remove(self, val: int) -> bool:
        if val not in self.values:
            return False
        index = self.values[val]
        last_val = self.keys[-1]

        self.keys[index], self.keys[-1] = self.keys[-1], self.keys[index]
        self.values[last_val] = index
        self.keys.pop()

        del self.values[val]
        return True

    def getRandom(self) -> int:
        rand_idx = randint(0, len(self.keys) - 1)
        return self.keys[rand_idx]


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
