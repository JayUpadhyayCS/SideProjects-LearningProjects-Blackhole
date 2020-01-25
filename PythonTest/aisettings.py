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
        self.rect.centerx=self.screen_rect.centerx
        self.rect.bottom=self.screen_rect.bottom
        self.speed=1
    def update(self):
        if self.right==True and self.rect.centerx<=1176:
            self.rect.centerx+=self.speed
        if self.left==True and self.rect.centerx>=24:
            self.rect.centerx-=self.speed
        if self.up==True and self.rect.bottom>54:
            self.rect.bottom-=self.speed
        if self.down==True and self.rect.bottom <796:
            self.rect.bottom+=self.speed


    def blitme(self):
        self.screen.blit(self.image,self.rect)
def check_events(ship):
    for event in pygame.event.get():
        if event.type == pygame.KEYDOWN:
            if event.key==pygame.K_RIGHT:
                ship.right=True
            elif event.key==pygame.K_LEFT:
                ship.left=True
            if event.key==pygame.K_UP:
                ship.up=True
            elif event.key==pygame.K_DOWN:
                ship.down=True
        elif event.type == pygame.KEYUP:
            if event.key==pygame.K_RIGHT:
                ship.right=False
            if event.key==pygame.K_LEFT:
                ship.left=False
            if event.key==pygame.K_UP:
                ship.up=False
            if event.key==pygame.K_DOWN:
                ship.down=False
        elif event.type==pygame.QUIT:
            sys.exit()

def update_screen(screen,color,ship):
    screen.fill(color)
    ship.blitme()
    pygame.display.flip()
    pygame.display.update()