#include "raylib.h"
#include <stdlib.h>
float getPt( float n1 , float n2 , float perc )
{
    float diff = n2 - n1;

    return n1 + ( diff * perc );
}    

unsigned int calc_arrays_count(unsigned int size){
    unsigned int size_foo = size - 1;
    unsigned int i = 0;
    while (size_foo >= 2) {
        i++;
        size_foo--;
    }
    return i;
}

void get_curve(Vector2 *pts, unsigned int size){
    unsigned int size_foo = size;
    unsigned int arrays_count = calc_arrays_count(size);
    Vector2 **arrays = calloc(arrays_count, sizeof(Vector2 *));
    size_foo--;
    unsigned int index = 0;
    while(index < arrays_count){
        arrays[index] = calloc(size_foo, sizeof(Vector2));
        size_foo--;
        index++;
    }
        
for( float i = 0 ; i < 1 ; i += 0.0001 )
{   
    size_foo = size-1;
     
    unsigned int j = 0;
    while(j < size_foo){//2
        arrays[0][j].x = getPt( pts[j].x , pts[j+1].x , i );
        arrays[0][j].y = getPt( pts[j].y , pts[j+1].y , i );
        j++; 
    }
    size_foo--;
    index = 1;
    while(index < arrays_count){
        j = 0;
        while(j<size_foo){
            arrays[index][j].x = getPt( arrays[index-1][j].x , arrays[index-1][j+1].x , i );
            arrays[index][j].y = getPt( arrays[index-1][j].y , arrays[index-1][j+1].y , i );
            j++; 
        }
        size_foo--;
        index++;
    }
    index--;
    float x = getPt( arrays[index][0].x , arrays[index][1].x , i );
    float y = getPt( arrays[index][0].y , arrays[index][1].y , i );
            
    DrawPixelV((Vector2){x, y}, RED);
  /*
      // The Green Lines
    xa = getPt( x1 , x2 , i );
    ya = getPt( y1 , y2 , i );
    xb = getPt( x2 , x3 , i );
    yb = getPt( y2 , y3 , i );
    xc = getPt( x3 , x4 , i );
    yc = getPt( y3 , y4 , i );

    // The Blue Line
    xm = getPt( xa , xb , i );
    ym = getPt( ya , yb , i );
    xn = getPt( xb , xc , i );
    yn = getPt( yb , yc , i );

    // The Black Dot
    x = getPt( xm , xn , i );
    y = getPt( ym , yn , i );

    drawPixel( x , y , COLOR_RED );
*/
}
}
