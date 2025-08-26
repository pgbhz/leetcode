"""
Design a Least Recently Used cache.
That means, we should keep the last n accessed items.
The last accessed element should be on top.
The other elements should be siphoned down.
What kind of data-structure makes this easy?
A heap? Interesting, but what about the non-top elements?
Linked list, O(n) for accessing non top cache elements.
Array: O(n) for updating the array...
Key-Value, this is screaming hash map.
Key-Value-AccessTime.
So we could have a hash-map for key-values and...
an array of access times. Or maybe a max-heap...
   or simply a queue... I like the idea of a queue of keys.

   We then have O(2n) space complexity.
   We have O(1) for all operations. I guess.
"""

from collections import deque


class LRUCache:

    def __init__(self, capacity: int):
        self.key_queue = deque()
        self.cache = {}
        self.capacity = capacity

    def get(self, key: int) -> int:
        if key in self.cache.keys():
            self.key_queue.remove(key)
            self.key_queue.appendleft(key)
        return self.cache.get(key, -1)

    def put(self, key: int, value: int) -> None:
        if key not in self.cache.keys():
            if len(self.cache) == self.capacity:
                key_to_del = self.key_queue.pop()
                del self.cache[key_to_del]
                self.key_queue.appendleft(key)
                self.cache[key] = value
            else:
                self.cache[key] = value
                self.key_queue.appendleft(key)
        else:
            self.cache[key] = value
            self.key_queue.remove(key)
            self.key_queue.appendleft(key)


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
