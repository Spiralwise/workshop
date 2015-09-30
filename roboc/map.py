#!/usr/bin/python
#-*-coding:utf-8 -*-

from pawn import *

class Map:
    """Cette classe représente un labyrinthe.
       Elle contient la position des éléments
       et définit la représentation des objets."""

    def __init__(self, ):
        self.map = []

    def readFile(self, filepath, robot_repr, wall_repr, door_repr, exit_repr):
        self.robot_repr = robot_repr
        self.wall_repr = wall_repr
        self.door_repr = door_repr
        self.exit_repr = exit_repr
        with open(filepath, "r") as file:
            file_content = file.readlines()
        buffer_map = []
        for lines in file_content:
            buffer_map.append([c for c in lines if c != "\n"])
        for y, line in enumerate(buffer_map):
            self.map.append([])
            for x, c in enumerate(line):
                if c == self.robot_repr:
                    self.map[y].append(Cell(Player(x, y)))
                elif c == self.wall_repr:
                    self.map[y].append(Wall())
                elif c == self.door_repr:
                    self.map[y].append(Cell(Door(x, y)))
                elif c == self.exit_repr:
                    self.map[y].append(Cell(Exit(x, y)))
                else:
                    self.map[y].append(Cell())

    def __iter__(self):
        return self.map.__iter__()
