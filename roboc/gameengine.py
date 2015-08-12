#!/usr/bin/python
#-*-coding:utf-8 -*-

class GameEngine:
    """Cette classe contient le moteur du jeu.
       Cela inclut la gestion de la map et du joueur."""

    def __init__(self):
        self.game_on = True #TODO Utiliser des setters et getters!

    def loadMap(self, mapname="noname", filepath="/dev/null"):
        self._mapname = mapname
        # TODO

    def loadGame(self):
        # TODO
        pass
    
    def saveGame(self):
        # TODO
        pass

    def displayMap(self):
        #TODO
        pass
    
    def callStop(self):
        self.saveGame(self._mapname)
        self.game_on = False

    def execCommand(self, command):
        # TODO
        return True
