#!/usr/bin/python3.4
#-*-coding:Utf-8 -*
from random import randrange
from math import ceil

# Constants
TEXT_RPG = "\033[3;96m"
TEXT_END = "\033[0m"

# Variables
game_on = True
initial_value = 20
wallet = initial_value
combo = 0
easter_egg = True

# Functions
def checkAmount(amount):
	global wallet
	if amount > wallet:
		print(TEXT_RPG, "Vous regardez votre porte-monnaie et constatez que vous n'avez pas assez. C'est triste.", TEXT_END)
		return False
	else:
		print(TEXT_RPG, "Vous déposez énergiquement $", amount, " en monnaie sur la table de jeu.", TEXT_END)
		wallet -= amount
		return True

def gainAmount(amount):
	global wallet
	wallet += amount
	print(TEXT_RPG, "Vous recevez $", amount, ". Vous avez maintenant $", wallet, " en poche.", TEXT_END)

# Game loop
while game_on:
	# Player gives numero
	numero = -1
	while not isinstance(numero, int) or numero < 0 or numero > 49:
		numero = input("Choisissez un numéro (0~49) > ")
		try:
			numero = int(numero)
		except ValueError:
			print("Non, je demande un simple numéro allant de 0 à 49.")
			continue
		if numero < 0 or numero > 49:
			print("J'ai demandé un numéro entre 0 et 49.")

	# Player gives mise
	mise = ""
	mise_ok = False
	while not isinstance(mise, int) or not mise_ok:
		mise = input("Misez une somme > ")
		try:
			mise = int(mise)
		except ValueError:
			print("Mais ! Ce n'est pas un nombre ! Recommencez...")
			continue
		if checkAmount(mise):
			mise_ok = True
		else:
			print("Il semblerait bien que vous n'avez pas assez...")

	# Play
	print("C'est parti...")
	roulette = randrange(50)
	print("Et le numéro gagnant est", roulette, " !")
	if roulette == mise:
		print("Félicitation ! Et voici votre gain !")
		gainAmount(mise*3)
		combo += 1
	elif (roulette % 2) == (numero % 2):
		print("Bravo. Vous n'avez pas tout perdu !")
		gainAmount(ceil(mise/2))
		combo +=1
	else:
		print("Dommage.")
		combo = 0
	if combo == 3 and easter_egg:
		print(TEXT_RPG, "Chef Pocatello vous regarde d'un air suspicieux. Ces deux gorilles se tiennent à côté de lui, les bras croisés. Derrière leurs lunettes noires, vous devinez leur regard se poser lourdement sur vous.", TEXT_END)
		easter_egg = False

	# Continue ?
	if not wallet:
		print("On dirait bien que vous n'avez plus d'argent. Je vais vous demander de bien vouloir quitter le casino. Merci.")
		game_on = False
	else:
		print(TEXT_RPG, "Il vous reste encore $", wallet, ".", TEXT_END)
		command = ""
		while command is not "o" and command is not "O":
			command = input("Voulez-vous rejouer ? (o/n) > ")
			if command is "n" or command is "N":
				game_on = False
				command = "o"

print("Bonne journée !")
if wallet > initial_value:
	print(TEXT_RPG, "Vous regardez votre porte-monnaie et souriez, vous avez fait un joli gain et vous marchez en chantonnant !", TEXT_END)
else:
	print(TEXT_RPG, "Vous avez perdu de l'argent dans cette aventure. Définitivement, vous vous dites que les jeux du hasard c'est nul.", TEXT_END)

