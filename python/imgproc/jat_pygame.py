#!/usr/bin/env python3
# -*- coding:utf-8 -*-
import pygame

pygame.init()
window = pygame.display.set_mode((640, 480))

coords = []

run = True
while run:
	for event in pygame.event.get():
		if event.type == pygame.KEYDOWN:
			run = False
		if event.type == pygame.MOUSEMOTION:
			coords.append(pygame.mouse.get_pos())

	window.fill((0,0,0))
	if len(coords) > 1:
		pygame.draw.lines(window, (192,192,255), False, coords)
	pygame.display.update()

pygame.quit()
