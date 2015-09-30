#!/usr/bin/python
#-*-coding:utf-8 -*-

from pawn import *
from map import Map

class GameEngine:
    """Cette classe contient le moteur du jeu.
       Cela inclut la gestion de la map et du joueur."""

    def __init__(self):
        self._game_on = True
        self._map = Map()

    def _get_game_on(self):
        return self._game_on
    
    gameOn = property(_get_game_on)

    def loadMap(self, mapname, filepath,\
                robot_repr, wall_repr, door_repr, exit_repr):
        self._mapname = mapname
        self._map.readFile(filepath,\
                           robot_repr, wall_repr, door_repr, exit_repr)

    def loadGame(self):
        # TODO
        pass
    
    def saveGame(self):
        # TODO
        pass

    def displayMap(self):
        frame_buffer = "";
        for line in self._map:
            for c in line:
                frame_buffer += str(c)
            frame_buffer += "\n"
        print(frame_buffer)
    
    def callStop(self):
        #self.saveGame(self._mapname)
        self._game_on = False

    def execCommand(self, command):
        # TODO
        return True
