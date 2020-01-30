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
    available_space_x=ai_settings.screen_width-2*alien_width
    number_aliens_x=int(available_space_x/(2*alien_width))
    for alien_number in range(number_aliens_x):
        alien=Alien(ai_settings,screen)
        alien.x=alien_width +2*alien_width*alien_number
        alien.rect.x=alien.x
        aliens.add(alien)
