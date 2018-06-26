#/usr/bin/python
#-*- coding:utf-8 -*-

import random
import sys
import time
from threading import Thread, RLock

my_lock = RLock()

class Afficheur(Thread):
    def __init__(self, mot):
        Thread.__init__(self)
        self.mot = mot

    def run(self):
        i = 0
        while i < 5:
            with my_lock:
                for letter in self.mot:
                    sys.stdout.write(letter)
                    sys.stdout.flush()
                    attente = 0.1
                    attente += random.randint(1, 40) / 100
                    time.sleep(attente)
                i += 1

if __name__ == "__main__":
    thread_1 = Afficheur("Flore")
    thread_2 = Afficheur("Avelin")

    thread_1.start()
    thread_2.start()

    thread_1.join()
    thread_2.join()
