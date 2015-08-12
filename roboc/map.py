#!/usr/bin/python
#-*-coding:utf-8 -*-

class Map:
    """Cette classe représente un labyrinthe.
       Elle contient la position des éléments
       et définit la représentation des objets."""

    def __init__(self, robot_repr="$", wall_repr="X", door_repr="O",
                 exit_repr="@"):
        self.robot_repr = robot_repr
        self.wall_repr = wall_reper
        self.door_repr = door_repr
        self.exit_repr = exit_repr
        self.map = []

    def readFile(self, filepath):
        # TODO: Here's we get a file

    def display(self):
        # TODO: Here's where the map is displayed
