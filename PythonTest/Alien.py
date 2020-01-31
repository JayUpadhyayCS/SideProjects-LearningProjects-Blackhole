import pygame
from pygame.sprite import Sprite


class Alien(Sprite):
    def __init__(self,ai_settings,screen):
        super(Alien,self).__init__()
        self.screen=screen
        self.ai_settings=ai_settings
        #LOAD IMAGE
        self.image=pygame.image.load('E:\SideProjects\PythonTest\images\enemy.bmp')
        self.rect=self.image.get_rect()
        self.rect.x=self.rect.width
        self.rect.y=self.rect.height

        self.x=float(self.rect.x)
    def blitme(self):
        self.screen.blit(self.image,self.rect)
def create_fleet(ai_settings,screen,aliens):
    alien=Alien(ai_settings,screen)
    alien_width=alien.rect.width
    
    number_aliens_x=get_number_aliens_x(ai_settings,alien.rect.width)
    for alien_number in range(number_aliens_x):
        create_alien(ai_settings,screen,aliens,alien_number)
    
def get_number_aliens_x(ai_settings,alien_width):
    available_space_x=ai_settings.screen_width-2*alien_width
    return int(available_space_x/(2*alien_width))

def create_alien(ai_settings,screen,aliens,alien_number):
        alien=Alien(ai_settings,screen)
        alien_width=alien.rect.width
        alien.x=alien_width +2*alien_width*alien_number
        alien.rect.x=alien.x
        aliens.add(alien)
def get_number_rows(ai_settings,ship_height,alien_height):
    available_space_y=(ai_settings.screen_height)-(3*alien_height)-ship_height
    number_rows=int(available_space_y/(2*alien_height))
    return number_rows
