import pygame
from bullet import Bullet
from Alien import Alien

    
def check_events(screen,ai_settings,ship,bullets):
    for event in pygame.event.get():
        checkKeyDown(screen,ai_settings,event,ship,bullets)
        checkKeyUp(event,ship)
        if event.type==pygame.QUIT:
            sys.exit()


def update_screen(screen,color,ship,bullets,aliens):
    screen.fill(color)
    ship.blitme()
    for alien in aliens.sprites():
        alien.blitme()
    for bullet in bullets.sprites():
        bullet.draw_bullet()
    pygame.display.flip()
    pygame.display.update()


    
def checkKeyDown(screen,ai_settings,event,ship,bullets):#check  which key is pressed and does something relating to key
    if event.type == pygame.KEYDOWN:
            if event.key==pygame.K_RIGHT:
                ship.right=True
            elif event.key==pygame.K_LEFT:
                ship.left=True
            if event.key==pygame.K_UP:
                ship.up=True
            elif event.key==pygame.K_DOWN:
                ship.down=True
            if event.key==pygame.K_SPACE and ai_settings.bullets_allowed>len(bullets):
                new_bullet=Bullet(ai_settings,screen,ship)
                bullets.add(new_bullet)
            if event.key==pygame.K_q:
                sys.exit()

                    
def checkKeyUp(event,ship): #if a key is let go, it stops moving a direction
        if event.type == pygame.KEYUP:
            if event.key==pygame.K_RIGHT:
                ship.right=False
            if event.key==pygame.K_LEFT:
                ship.left=False
            if event.key==pygame.K_UP:
                ship.up=False
            if event.key==pygame.K_DOWN:
                ship.down=False
def update_bullets(bullets):
    bullets.update()
    for bullet in bullets.copy():
        if bullet.rect.bottom<=0:
            bullets.remove(bullet)

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

def create_fleet(ai_settings,screen,ship,aliens):# create rows of aliens
    alien=Alien(ai_settings,screen)
    alien_width,alien_height=alien.rect.size
    ship_height=ship.rect.height
    number_rows= get_number_rows(ai_settings,ship_height,alien_height)# find out how many rows they can print.
    number_aliens_x=get_number_aliens_x(ai_settings,alien.rect.width)# get how many aliens per row
    for row_number in range(number_rows): #create aliens in rows
        for alien_number in range(number_aliens_x):
            create_alien(ai_settings,screen,aliens,alien_number,row_number)    


