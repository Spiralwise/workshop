#!/usr/bin/python3.4
#-*- coding:utf-8 -*-

class Odict:
    """Ordered dictonnary."""

    def __init__(self, **words):
        self._keys = []
        self._words = []
        for key, word in words.items():
            self._keys.append(key)
            self._words.append(word)

    def __getitem__(self, key):
        if key in self._keys:
            return self._words[self._keys.index(key)]
        raise KeyError("There is no entry with the key {}.".format(key))

    def __setitem__(self, key, value):
        if key in self._keys:
            self._words[self._keys.index(key)] = value
        else:
            self._keys.append(key)
            self._words.append(value)
            
    def __delitem__(self, key):
        if key in self._keys:
            del self._words[self._keys.index(key)]
            self._keys.remove(key)
        else:
            raise KeyError("Can't remove this item. \
            There is no entry with the key {}.".format(key))

    def __contains__(self, key):
        if key in self._keys:
            return True
        return False

    def __str__(self):
        buffer = "{"
        last_idx = len(self._keys)-1
        for key, word in zip(self._keys, self._words):
            idx = self._keys.index(key)
            buffer += "'" + key + "': " + str(word)
            if idx != last_idx:
                buffer += ", "
        buffer += "}"
        return buffer

    def __repr__(self):
        return str(self)
    
    def sort(self):
        self._words = [w for (k,w) in sorted(zip(self._keys, self._words))]
        self._keys.sort()

    def reverse(self):
        self._words = [w for (k,w) in sorted(zip(self._keys, self._words), reverse=True)]
        self._keys.sort(reverse=True)

    def __iter__(self):
        self._iter_idx = 0
        return self

    def __next__(self):
        if self._iter_idx < len(self._keys)-1:
            self._iter_idx += 1
            return (self._keys[self._iter_idx], self._words[self._iter_idx])
        raise StopIteration

    def keys(self):
        return self._keys;

    def values(self):
        return self._words;

    def items(self):
        return zip(self._keys, self._words)

    def __len__(self):
        return len(self._keys)

    def __add__(self, other):
        self._keys += other._keys
        self._words += other._words
        return self;


if __name__ == "__main__":
    fruits = Odict()
    print("Create a new odict: ", fruits)
    fruits["pomme"] = 52
    fruits["poire"] = 34
    fruits["prune"] = 128
    fruits["melon"] = 15
    print("Add some fruits: ", fruits)
    print("Show prune: ", fruits['prune'])
    fruits.sort()
    print("Sort: ", fruits)
    legumes = Odict(carotte = 26, haricot = 48)
    print("Create a new odict: ", legumes)
    print("Number of elements: ", len(legumes))
    legumes.reverse()
    print("Reverse: ", legumes)
    fruits = fruits + legumes
    print("Merge odicts: ", fruits)
    print("Haricot here?", "haricot" in fruits)
    del fruits['haricot']
    print("Del haricot:", "haricot" in fruits)
    fruits['poire'] = 96;
    print("Poire=", fruits['poire'])
    for k in legumes:
        print(k)
    print(legumes.keys())
    print(legumes.values())
    for n, q in legumes.items():
        print("{} ({})".format(n, q))
