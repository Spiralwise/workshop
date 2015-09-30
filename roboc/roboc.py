#!/usr/bin/python
#-*-coding:utf-8 -*-

################################
#  "Executable" du jeu Roboc   #
#                              #
# Spiralwise for OpenClassroom #
# ------- Aug 14, 2015 ------- #
################################

import os
from gameengine import GameEngine

# Intro
game = GameEngine()
print("---- ROBOC ----\n")

# Sélection d'une map
print(":: Maps ::")
maps = []
idx = 1
for filename in os.listdir("maps"):
    if filename.endswith(".txt"):
        filepath = os.path.join("maps", filename)
        mapname = filename[:-4].lower()
        maps.append({"mapname": mapname, "filepath":filepath})
        print("{} - {}".format(idx, mapname))
        idx += 1
idx = -1
while idx == -1:
    idx = input("Sélectionnez une map > ")
    try:
        idx = int(idx)
    except ValueError:
        print("Ceci n'est pas un nombre !")
        idx = -1
        continue
    if idx < 1 or idx > len(maps):
        print("Non, je n'ai pas ce numéro dans ma liste. Réessayez !")
        idx = -1
    else:
        idx -= 1
        print("Chargement de la map {}...".format(maps[idx]["mapname"]))
        game.loadMap(robot_repr="X", wall_repr="O",\
                     door_repr=".", exit_repr="U", **maps[idx])

# Game Loop
while game.gameOn:
    game.displayMap()
    
    # Exécution des commandes
    command = input("> ")
    print(command)
    if command == "help":
        print("Ok, je devrais afficher une vraie aide ici...") #TODO
    ## Quitter le jeu
    elif command == "quit":
        game.callStop()
    ## Envoyer la commande au Game Engine
    else:
        if not game.execCommand(command):
            print("Mmh... Je crois que je n'ai pas compris.")

# Extro
print("Goodbye !")
