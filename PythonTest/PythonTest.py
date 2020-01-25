
import pygame
import importlib
from aisettings import *

def run_game():
    pygame.init()
    ai_settings=Settings()
    


    screen=pygame.display.set_mode((ai_settings.screen_width,ai_settings.screen_height))
    ship=Ship(screen)
    
    pygame.display.set_caption("Alien Invasion")
    while True:
        check_events(ship)
        ship.update()
        update_screen(screen,ai_settings.bg_color,ship)
            
    
run_game()
