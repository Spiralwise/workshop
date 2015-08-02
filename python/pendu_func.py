#-*- coding:utf-8 -*-
"""This module contains functions for the "pendu" game.
Launch this module to generate the score.dat file if not exists.
"""

from os.path import exists
from random import randrange
from words import *
import pickle

# Parameters
filepath_score = "score.dat"

# Data
scores = {}
current_player = "noname"
current_score = -1

# Functions
def generate_savefile(filepath):
    """Generate a save file if it's not exist already.

    Args:
    filepath (str): The filepath name to the save file.
    """
    if not exists(filepath):
        with open(filepath, "wb") as filehandler_score:
            pickler_score = pickle.Pickler(filehandler_score)
            empty_save = {}
            pickler_score.dump(empty_save)
            print("{} file has been generated.".format(filepath))
    else:
        print("{} already exists.".format(filepath))

def init_game(filepath):
    """"Initialize the game. Must be called first.

    Generate a save file if it's not exist already.

    Args:
    filepath (str): The filepath name to the save file.
    """
    global scores

    if not exists(filepath):
        generate_savefile(filepath)
    with open(filepath, "rb") as score_file:
        file_reader = pickle.Unpickler(score_file)
        scores = file_reader.load()

def init_player(name):
    """Initialize the player.

    It loads the current player state if already exists.
    Otherwise it creates a new one.

    Args:
    name (str): The player name.

    Returns:
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
    with open(filepath_score, "wb") as score_file:
        file_writer = pickle.Pickler(score_file)
        file_writer.dump(scores)

def select_word():
    """Select randomly a word from words.py list.

    Returns:
    str: A random word from words.py list.
    """
    return words[randrange(len(words))]

def hide_word(number_of_letters, wildcard="*"):
    """Create a hidden word.

    Args:
    number_of_letters (int): The number of letters that composes the word.
    wildcard (str): A character used to hide the letters.

    Returns:
    The word hidden by the wildcard character.
    """
    return str(wildcard * number_of_letters)

def test_letter(current_word, hidden_word, letter):
    if len(current_word) != len(hidden_word):
        print("Warning: You put two words with different length. Function will return False.")
        return False, current_word
    for l in 

if __name__ == "__main__":
    generate_savefile(filepath_score)
