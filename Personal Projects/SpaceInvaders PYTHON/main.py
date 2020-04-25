from Alien import Alien
import pygame
import importlib
from aisettings import *
from pygame.sprite import Group
from bullet import *
from Ship import Ship
import GF
def run_game():
    pygame.init()
    ai_settings=Settings()
    
    #Set screen
    screen=pygame.display.set_mode((ai_settings.screen_width,ai_settings.screen_height))
    #Set ship
    ship=Ship(screen)
    #Set bullet
    bullets=Group()
    #set aliens
    aliens=Group()
    GF.create_fleet(ai_settings,screen,ship,aliens)#create fleet of aliens on top of screen

    
    
    pygame.display.set_caption("Alien Invasion")# set screen name to alien invasion
    while True: #continue running game until X is clicked.
        GF.check_events(screen,ai_settings,ship,bullets)#check if buttons are clicked.
        if(ship.update(aliens)):#update ship position based on button pressed and prevent offscreen ship
            GF.game_over(ship,aliens)
            run_game()
            break
           
        GF.update_bullets(bullets,aliens)#update bullet movements, if offscreen delete sprite
        GF.update_aliens(ai_settings,aliens)#update aliens movements
        
        GF.update_screen(screen,ai_settings.bg_color,ship,bullets,aliens)# prints to screen

    
    
run_game()
