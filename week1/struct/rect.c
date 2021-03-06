/*
 * @ File name: rect.c
 * @ Author: unknowntpo at 2020.2.24 (Mon)
 * @ Title: Check whether a point is in rectangle or not.
 * @ Short description:
 *      Make two point to form a rectangle called 'screen',   
 *      and count the middle point.
 *      then, use ptinrect(middle, screen) function to check that
 *      middle point is in the rectangle.
 * @ K&R_6.2: structures and functions   
 */     

#define XMAX 10 
#define YMAX 10
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

#include <stdio.h>

/**
 * anonymous struct - create a point
 * @x: x-coordinate of a point.
 * @y: y-coordinate of a point.
 */
typedef struct {
    int x;
    int y;
}point;

/**
 * anonymous struct - create a rectangle
 * @pt1: first point to describe a rectangle.
 * @pt2: second point to describe a rectangle.
 */
typedef struct {
    point pt1;
    point pt2;  
} rect;

/**
 * @func: makepoint() - make a point
 * @x: specify the x-axis of a point
 * @y: specify the y-axis of a point
 * 
 * Return: the structure whose type is point
 *      @point: a typedef of struct  
 */
point makepoint(int x, int y)
{
    point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

/**
 * @func: addpoint() - add two points
 * @p1: a point
 *     -datatype: point (typedef)
 * @p2: another point
 *     -datatype: point (typedef)
 * Return: the adding result (stored in p1)
 */
point addpoint(point p1, point p2)
{
   p1.x += p2.x;
   p1.y += p2.y;
   return p1;
}

/* 
 * @func: ptinrect() - check if point is in rectangle
 * @p: a point
 *      -datatype: point (typedef)
 * @r: a rectangle
 *      -datatype: point (typedef)
 * Return 1 if the point is in rectangle, 0 if not.
 */
int ptinrect(point p, rect r)
{
    return (p.x >= r.pt1.x) && (p.x < r.pt2.x)
        && (p.y >= r.pt1.y) && (p.y < r.pt2.y);
}

/** 
 * func: canonrect() - canonicalize coordinates of rectangle
 * @Description
 *     used to make sure that 
 *         pt1 is at bottom - left corner,
 *         pt2 is at top - right corner.
 * @r: a rect which data type is 'struct rect'
 * Return: a rect which data type is 'struct rect'.
 */
rect cononrect (rect r)
{
    rect temp = {{0, 0}, {0, 0}};
    temp.pt1.x = min(r.pt1.x, r.pt2.x);
    temp.pt1.y = min(r.pt1.y, r.pt2.y);
    temp.pt2.x = max(r.pt1.x, r.pt2.x);        
    temp.pt2.y = max(r.pt1.y, r.pt2.y);    
    return temp;
}

int main()
{
    /* Declare a rect called screen */
    rect screen;
    /* Declare a point middle */
    point middle;
    point makepoint(int ,int);
    /* assign value to pt1 and pt2 and middle with makepoint func. */
    screen.pt2 = makepoint(0, 0);
    screen.pt1 = makepoint(XMAX, YMAX);
    middle = makepoint((screen.pt1.x + screen.pt2.x)/2,
                       (screen.pt1.y + screen.pt2.y)/2);
    screen = cononrect(screen);
    int inrect;
    inrect = ptinrect(middle, screen);
    if (inrect) {
         printf("point (%d,%d) is in the rectangle.\n", middle.x, middle.y);
    }else {
         printf("point (%d,%d) is not in the rectangle.\n", middle.x, middle.y);
    }
     
}


