#!/usr/bin/python3.4
#-*- coding:utf-8 -*-
from pendu_func import *

print("Démarrage...")
init_game()

name = input("Entrez votre nom > ")
init_player(name)

save_game()
print("A plus !")
