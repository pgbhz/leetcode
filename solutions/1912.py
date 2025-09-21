import collections
import heapq
from typing import List


class MovieRentingSystem:

    def __init__(self, n: int, entries: List[List[int]]):
        self.catalog = collections.defaultdict(list)  # movie -> [(price, shop), ...]
        self.prices = {}  # (shop, movie) -> price
        for shop, movie, price in entries:
            self.catalog[movie].append((price, shop))
            self.prices[(shop, movie)] = price

        for movie in self.catalog:
            self.catalog[movie].sort()

        self.rented_set = set()  # (shop, movie)
        self.rented_heap = []  # (price, shop, movie)

    def search(self, movie: int) -> List[int]:
        result = []
        for _, shop in self.catalog.get(movie, []):
            if (shop, movie) not in self.rented_set:
                result.append(shop)
            if len(result) == 5:
                break
        return result

    def rent(self, shop: int, movie: int) -> None:
        self.rented_set.add((shop, movie))
        price = self.prices[(shop, movie)]
        heapq.heappush(self.rented_heap, (price, shop, movie))

    def drop(self, shop: int, movie: int) -> None:
        self.rented_set.discard((shop, movie))

    def report(self) -> List[List[int]]:
        result = []
        temp_storage = []
        added_to_this_report = set()

        while self.rented_heap and len(result) < 5:
            price, shop, movie = heapq.heappop(self.rented_heap)

            if (shop, movie) in self.rented_set:
                # Avoid ghost heap entries.
                if (shop, movie) not in added_to_this_report:
                    result.append([shop, movie])
                    added_to_this_report.add((shop, movie))
                    temp_storage.append((price, shop, movie))

        # Add the valid, non-ghost items back to the heap for the next report.
        for item in temp_storage:
            heapq.heappush(self.rented_heap, item)

        return result
