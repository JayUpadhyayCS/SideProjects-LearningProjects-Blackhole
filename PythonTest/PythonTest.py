
import pygame
import importlib
from aisettings import *
from pygame.sprite import Group
 
def run_game():
    pygame.init()
    ai_settings=Settings()
    
    
    #Set screen
    screen=pygame.display.set_mode((ai_settings.screen_width,ai_settings.screen_height))
    #Set ship
    ship=Ship(screen)
    #Set bullet
    bullets=Group()
    pygame.display.set_caption("Alien Invasion")
    while True:
        check_events(screen,ai_settings,ship,bullets)
        ship.update()
        bullets.update()
        update_screen(screen,ai_settings.bg_color,ship,bullets)
            
    
run_game()
