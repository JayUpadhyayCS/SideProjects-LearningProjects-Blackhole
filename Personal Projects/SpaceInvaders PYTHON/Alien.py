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
        self.x+=self.ai_settings.alien_speed_factor# move alien right
        self.rect.x=self.x# #update sprite location



    def create_fleet(ai_settings,screen,ship,aliens):# create rows of aliens
        alien=Alien(ai_settings,screen)
        alien_width,alien_height=alien.rect.size
        ship_height=ship.rect.height

        number_rows=get_number_rows(ai_settings,ship_height,alien_height)# find out how many rows they can print.
        number_aliens_x=get_number_aliens_x(ai_settings,alien.rect.width)# get how many aliens per row
        for row_number in range(number_rows): #create aliens in rows
            for alien_number in range(number_aliens_x):
                create_alien(ai_settings,screen,aliens,alien_number,row_number)

    
def get_number_aliens_x(ai_settings,alien_width):# get how many aliens per row
    available_space_x=ai_settings.screen_width-2*alien_width
    return int(available_space_x/(2*alien_width))

def create_alien(ai_settings,screen,aliens,alien_number,row_number): #print alien in different position based on their number, and row number
        alien=Alien(ai_settings,screen)
        alien_width=alien.rect.width
        alien.rect.y= alien.rect.height+2*alien.rect.height*row_number
        alien.x=alien_width +2*alien_width*alien_number
        alien.rect.x=alien.x
        aliens.add(alien)
def get_number_rows(ai_settings,ship_height,alien_height):# find out how many rows they can print.
    available_space_y=(ai_settings.screen_height)-(3*alien_height)-ship_height
    number_rows=int(available_space_y/(2*alien_height))
    return number_rows

def update_aliens(aliens):
    aliens.update()

