#!/usr/bin/python
#-*-coding:utf-8 -*-

"""Ce package contient les éléments de jeux pour construire un niveau."""

pawn_repr = {"Player":"$",\
             "Wall":"O",\
             "Door":"#",\
             "Exit":"@"}

class Pawn:
    """Cette classe représente un élément interactif sur la map."""

    def __init__(self, x, y): #TODO Peut etre pas besoin des coords
        self._x = x
        self._y = y


class Cell():
    """Cet élément représente une cellule de la carte"""

    def __init__(self, pawn=0):
        self._pawn = pawn
        self._solid = False

    def __str__(self):
        if self._pawn != 0:
            return pawn_repr[type(self._pawn).__name__]
        else:
            return pawn_repr.get(type(self).__name__, " ")


class Wall(Cell):
    """Cette classe représente un mur qui ne peut pas être
       traversé par le robot.
    """

    def __init__(self):
        Cell.__init__(self)
        self._solid = True
        

class Player(Pawn):
    """Cette classe représente le joueur."""

    def __init__(self, x, y):
        Pawn.__init__(self, x, y)
        

class Door(Pawn):
    """Cette classe représente une porte traversable."""

    def __init__(self, x, y):
        Pawn.__init__(self, x, y)


class Exit(Pawn):
    """Cette classe représente la sortie."""

    def __init__(self, x, y):
        Pawn.__init__(self, x, y)
