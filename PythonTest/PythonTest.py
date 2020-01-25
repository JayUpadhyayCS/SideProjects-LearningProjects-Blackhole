import sys
import pygame
import importlib
from aisettings import Settings
def run_game():
    pygame.init()
    ai_settings=Settings()

    screen=pygame.display.set_mode((ai_settings.screen_width,800))
    bg_color=(230,230,230)
    pygame.display.set_caption("Alien Invasion")
    while True:
        for event in pygame.event.get():
            screen.fill(bg_color)
            pygame.display.update()
            if event.type==pygame.QUIT:
                sys.exit()
    pygame.display.flip()
run_game()
