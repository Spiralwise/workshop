#!/usr/bin/python3.4
#-*- coding:utf-8 -*-
from pendu_func import *

# Intro
print("Démarrage...")
init_game()

name = input("Entrez votre nom > ")
if init_player(name):
    print("Tiens donc, un nouveau parmi nous !")
else:
    print("Salut {} ! Content de te revoir !".format(name))

# Game loop
game_on = True
while game_on:
    # Start
    selected_word = select_word()
    hidden_word = hide_word(len(hidden_word))

    # Play
    lifes = 9
    guessed = False
    while lifes > 0 or not guessed:
        print(hidden_word)
        letter = input(" > ")
        guessed, hidden_word = test_letter(hidden_word, selected_word, letter[0])
        lifes -= 1

    # End
    if lifes == 0:
        print("Dommage ! Vous avez perdu... Le mot était {}.".format(selected_word))
    else:
        print("Félictations ! Vous avez devinez le mot ! Vous gagnez {} point(s) !".format(str(lifes)))
        add_playe_score(name, lifes)
    print("Score actuel : ", get_player_score(name))
    
    # Try again?
    player_input = "z"
    while player_input.lower() != "n" and player_input.lower() != "o"
        player_input = input("Voulez-vous rejouez ? (O/N) > ")
        if player_input.lower() == "n":
            game_on = False
        else if player_input.lower() == "o"
            print("C'est reparti ! Cette fois, c'est la bonne !")
        else
            print("Mmh... Mais encore ?")
        

# Extro
save_game()
print("A plus !")
