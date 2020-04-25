import pygame
import sys
from bullet import *
from Alien import *
class Settings():
    def __init__(self):
        #screen settings
        self.screen_width=1200
        self.screen_height=800
        self.bg_color=(230,230,230)
        #Bullet settings
        self.bullet_speed_factor=2
        self.bullet_width=3
        self.bullet_height=15
        self.bullet_color=(60,60,60)
        self.bullets_allowed=3
        #Alien settings
        self.alien_speed_factor=1
        self.fleet_drop_speed=10#how quickly fleet drops y axis
        self.fleet_direction=1#1 is right, -1 is left




