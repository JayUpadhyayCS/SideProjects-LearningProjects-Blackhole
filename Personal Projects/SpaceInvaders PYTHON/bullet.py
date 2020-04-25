import pygame
from pygame.sprite import Sprite

class Bullet(Sprite):
    def __init__(self,ai_settings,screen,ship):
        #Bullet object at the ship position
        super(Bullet,self).__init__()
        self.screen=screen
        #Bullet rect at 0,0 then set positioniop
        self.rect=pygame.Rect(0,0,ai_settings.bullet_width, ai_settings.bullet_height)
        self.rect.centerx=ship.rect.centerx
        self.rect.top=ship.rect.top

        #store bullet position
        self.y=float(self.rect.y)

        self.color=ai_settings.bullet_color
        self.speed_factor=ai_settings.bullet_speed_factor



    def update(self):
        #Move bullet up screen
        self.y-=self.speed_factor
        self.rect.y=self.y

    def draw_bullet(self):
        pygame.draw.rect(self.screen,self.color,self.rect)




    