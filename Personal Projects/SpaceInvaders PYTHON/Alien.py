import pygame
from pygame.sprite import Sprite


class Alien(Sprite):
    def __init__(self,ai_settings,screen):
        super(Alien,self).__init__()
        self.screen=screen
        self.ai_settings=ai_settings
        #LOAD IMAGE
        self.image=pygame.image.load('images\enemy.bmp')
        self.rect=self.image.get_rect()
        self.rect.x=self.rect.width
        self.rect.y=self.rect.height
      #  self.alien_speed_factor=1

        self.x=float(self.rect.x)
    def blitme(self):#print
        self.screen.blit(self.image,self.rect)
    def update(self):
        self.x+=(self.ai_settings.alien_speed_factor*self.ai_settings.fleet_directions)# move alien right
        self.rect.x=self.x# #update sprite location
    def check_edges(self):
        screen_rect=self.screen.get_rect()
        if self.rect.right >=screen_rect.right or self.rect.left <=screen_rect.left:# if alien sprite is greater than the x axis for screen, or is less than 0, or the start of screen
            return True
        return False

    


