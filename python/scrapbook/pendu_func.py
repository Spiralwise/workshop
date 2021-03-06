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
    
    current_player = name
    if current_player in scores:
        return False
    else:
        scores[current_player] = 0
        return True

def save_game():
    """Save the current player state."""
    global scores
    global current_player

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

def test_letter(hidden_word, current_word, letter, wildcard="*"):
    """Check if the letter is present in the current word.
    The hidden word and the current word must match in size and any
    discovered letters.

    Args:
    hidden_word (str): The word to guess with hidden letter by the wildcard.
    current_word (str): The word to guess. It must contain some wildcard to
    hide some letters.
    letter (str): The letter to test with.

    Returns:
    (return code, the hidden word with the input letter discovered)
    return code: -1 if an error occured. 0 if not guessed. 1 if well guessed.
    2 if already given.
    10 if the entire word is found.
    """
    if len(current_word) != len(hidden_word):
        print("Error: You put two words with different length. Function will return False.")
        return -1, hidden_word
    guessed = 0
    result_word = ""
    for idx, ltr in enumerate(hidden_word):
        if ltr != wildcard and ltr != current_word[idx]:
            print("Error: The input words don't match.")
            return -1, hidden_word
        if ltr == letter:
            return 2, hidden_word
        if ltr == wildcard and current_word[idx] == letter:
            result_word += letter
            guessed = 1
        else:
            result_word += ltr
    if wildcard not in result_word:
        guessed = 10
    return guessed, result_word

def get_player_score(player_name):
    """Return the player score. If doesn't exit, return -1."""
    return scores.get(player_name, -1)

def add_player_score(player_name, value):
    """Add value to the player score."""
    scores[player_name] += value

if __name__ == "__main__":
    generate_savefile(filepath_score)
