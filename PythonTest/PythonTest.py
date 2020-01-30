from Alien import Alien
import pygame
import importlib
from aisettings import *
from pygame.sprite import Group
from bullet import *
def run_game():
    pygame.init()
    ai_settings=Settings()
    
    
    #Set screen
    screen=pygame.display.set_mode((ai_settings.screen_width,ai_settings.screen_height))
    #Set ship
    ship=Ship(screen)
    #Set bullet
    bullets=Group()
    aliens=Group()
    create_fleet(ai_settings,screen,aliens)

    
    
    pygame.display.set_caption("Alien Invasion")
    while True:
        check_events(screen,ai_settings,ship,bullets)
        ship.update()
        update_bullets(bullets)
        
        
        update_screen(screen,ai_settings.bg_color,ship,bullets,aliens)
            
    
run_game()
