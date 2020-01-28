import pygame
import sys
class Settings():
    def __init__(self):
        #screen settings
        self.screen_width=1200
        self.screen_height=800
        self.bg_color=(230,230,230)
    

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
def check_events(ship):
    for event in pygame.event.get():
        checkKeyDown(event,ship)
        checkKeyUp(event,ship)
        if event.type==pygame.QUIT:
            sys.exit()

def update_screen(screen,color,ship):
    screen.fill(color)
    ship.blitme()
    pygame.display.flip()
    pygame.display.update()


def checkKeyDown(event,ship):
    if event.type == pygame.KEYDOWN:
            if event.key==pygame.K_RIGHT:
                ship.right=True
            if event.key==pygame.K_LEFT:
                ship.left=True
            if event.key==pygame.K_UP:
                ship.up=True
            if event.key==pygame.K_DOWN:
                ship.down=True


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
