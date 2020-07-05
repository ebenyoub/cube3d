    #include "../includes/cub3d.h"
    
    //    // avance si aucun mur n'est devant toi
    //  if (keyDown (SDLK_UP))
    // {
    //   if (worldMap [int (posX + dirX * moveSpeed)] [int (posY)] == false) posX + = dirX * moveSpeed;
    //   if (worldMap [int (posX)] [int (posY + dirY * moveSpeed)] == false) posY + = dirY * moveSpeed;
    // }
    // // recule si aucun mur n'est derrière toi
    //  if (keyDown (SDLK_DOWN))
    // {
    //   if (worldMap [int (posX - dirX * moveSpeed)] [int (posY)] == false) posX - = dirX * moveSpeed;
    //   if (worldMap [int (posX)] [int (posY - dirY * moveSpeed)] == false) posY - = dirY * moveSpeed;
    // }
    // // tourne vers la droite
    //  si (keyDown (SDLK_RIGHT))
    // {
    //   // la direction et le plan de la caméra doivent être tournés
    //    double oldDirX = dirX;
    //   dirX = dirX * cos (-rotSpeed) - dirY * sin (-rotSpeed);
    //   dirY = oldDirX * sin (-rotSpeed) + dirY * cos (-rotSpeed);
    //   double oldPlaneX = planeX;
    //   planeX = planeX * cos (-rotSpeed) - planeY * sin (-rotSpeed);
    //   planeY = oldPlaneX * sin (-rotSpeed) + planeY * cos (-rotSpeed);
    // }
    // // tourne vers la gauche
    //  si (keyDown (SDLK_LEFT))
    // {
    //   // la direction et le plan de la caméra doivent être tournés
    //    double oldDirX = dirX;
    //   dirX = dirX * cos (rotSpeed) - dirY * sin (rotSpeed);
    //   dirY = oldDirX * sin (rotSpeed) + dirY * cos (rotSpeed);
    //   double oldPlaneX = planeX;
    //   planeX = planeX * cos (rotSpeed) - planeY * sin (rotSpeed);
    //   planeY = oldPlaneX * sin (rotSpeed) + planeY * cos (rotSpeed);
    // }