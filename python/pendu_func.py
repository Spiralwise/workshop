#-*- coding:utf-8 -*-
"""This module contains functions for the "pendu" game."""
from words import *
import pickle

scores = {}
current_player = "noname"
current_score = -1

def init_game():
    """"Initialize the game. Must be called first.""""
    global scores
    
    with open("score.dat", "rb") as score_file:
        file_reader = pickle.Unpickler(score_file)
        scores = file_reader.load()

def init_player(name):
    """Initialize the player.

    It loads the current player state if already exists.
    Otherwise it creates a new one.

    Args:
    name (str): The player name.

    Retruns:
    bool: True if the player is a new one. False if already exists.
    """
    global scores
    global current_player
    global current_score
    
    current_player = name
    if current_player in scores:
        current_score = scores[current_player]
        return False
    else:
        current_score = 0
        return True

def save_game():
    """Save the current player state."""
    global scores
    global current_player
    global current_score

    scores[current_player] = current_score
    with open("score.dat", "wb") as score_file:
        file_writer = pickle.Pickler(score_file)
        file_writer.dump(scores)
