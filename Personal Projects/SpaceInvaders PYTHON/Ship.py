import pygame
from pygame.sprite import Sprite

class Ship(Sprite):
    def __init__(self,screen):
        self.screen=screen;
        self.image=pygame.image.load('images\ship.bmp')
        self.rect=self.image.get_rect()
        self.screen_rect=screen.get_rect()
        self.right=False
        self.left=False
        self.up=False
        self.down=False
        self.rect.centerx=float(self.screen_rect.centerx)
        self.rect.bottom=self.screen_rect.bottom
        self.speed=1.5
    def update(self,aliens):
        
        if pygame.sprite.spritecollideany(self,aliens) or len(aliens)==0:
            print("Ship Hit")
            return True
        if self.right and self.rect.right<self.screen_rect.right:#1176
            self.rect.centerx+=self.speed+1
        if self.left and self.rect.left>self.screen_rect.left:
            self.rect.centerx-=self.speed
        if self.up and self.rect.top>self.screen_rect.top:
            self.rect.bottom-=self.speed
        if self.down and self.rect.bottom <self.screen_rect.bottom:
            self.rect.bottom+=self.speed+1
        return False
    def blitme(self):
        self.screen.blit(self.image,self.rect)
