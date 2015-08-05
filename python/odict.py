#!/usr/bin/python3.4
#-*- coding:utf-8 -*-

class Ordict:
    """Ordered dictonnary."""

    def __init__(self, **words):
        self._keys = []
        self._words = []
        for key, word in words:
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
        for key in self._keys:
            idx = self._keys.index(key)
            last_idx = len(self._keys)-1 
            buffer += key + ": " + self._words[idx]
            if idx != last_idx:
                buffer += ","
        buffer += "}"

    def sort(self):
        # TO CONTINUE
