#!/usr/bin/env python3
# -*- coding:utf-8 -*-
from PIL import Image

im = Image.open("kirsten.jpg")
im.rotate(45).show()
