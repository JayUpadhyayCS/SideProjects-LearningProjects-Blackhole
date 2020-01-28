import pygame
import sys
from bullet import *
class Settings():
    def __init__(self):
        #screen settings
        self.screen_width=1200
        self.screen_height=800
        self.bg_color=(230,230,230)
        #Bullet settings
        self.bullet_speed_factor=2
        self.bullet_width=3
        self.bullet_height=15
        self.bullet_color=(60,60,60)
        self.bullets_allowed=3
    

class Ship():
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
    def update(self):
        if self.right and self.rect.right<self.screen_rect.right:#1176
            self.rect.centerx+=self.speed+1
        if self.left and self.rect.left>self.screen_rect.left:
            self.rect.centerx-=self.speed
        if self.up and self.rect.top>self.screen_rect.top:
            self.rect.bottom-=self.speed
        if self.down and self.rect.bottom <self.screen_rect.bottom:
            self.rect.bottom+=self.speed+1


    def blitme(self):
        self.screen.blit(self.image,self.rect)
def check_events(screen,ai_settings,ship,bullets):
    for event in pygame.event.get():
        checkKeyDown(screen,ai_settings,event,ship,bullets)
        checkKeyUp(event,ship)
        if event.type==pygame.QUIT:
            sys.exit()

def update_screen(screen,color,ship,bullets):
    screen.fill(color)
    ship.blitme()
    for bullet in bullets.sprites():
        bullet.draw_bullet()
    pygame.display.flip()
    pygame.display.update()


def checkKeyDown(screen,ai_settings,event,ship,bullets):
    if event.type == pygame.KEYDOWN:
            if event.key==pygame.K_RIGHT:
                ship.right=True
            if event.key==pygame.K_LEFT:
                ship.left=True
            if event.key==pygame.K_UP:
                ship.up=True
            if event.key==pygame.K_DOWN:
                ship.down=True
            if event.key==pygame.K_SPACE and ai_settings.bullets_allowed>len(bullets):
                new_bullet=Bullet(ai_settings,screen,ship)
                bullets.add(new_bullet)


def checkKeyUp(event,ship):
     if event.type == pygame.KEYUP:
            if event.key==pygame.K_RIGHT:
                ship.right=False
            if event.key==pygame.K_LEFT:
                ship.left=False
            if event.key==pygame.K_UP:
                ship.up=False
            if event.key==pygame.K_DOWN:
                ship.down=False

