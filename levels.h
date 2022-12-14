#include <stdlib.h>
#include <GLUT/glut.h>
#include <math.h>
#include <iostream>

/* Indexes

   1-3 - Normal Textures
   4   - Door
   5   - Normal Texture
   6   - Exit
   9   - Error Texture

 */

/* Map Variables */
int mapW[256];
int mapF[256];
int mapC[256];
int mapE[256];

 /* Error Map */
int errorW[]={
 9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
 9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
 9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
 9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
 9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
 9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
 9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
 9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
 9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
 9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
 9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
 9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
 9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
 9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
 9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,
 9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,};

int errorF[]={
 8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
 8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
 8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
 8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
 8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
 8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
 8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
 8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
 8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
 8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
 8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
 8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
 8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
 8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
 8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
 8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,};

int errorC[]={
 9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
 9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
 9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
 9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
 9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
 9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
 9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
 9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
 9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
 9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
 9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
 9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
 9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
 9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
 9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
 9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,};

 int errorE[]={
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};

 /* Level 1 */
int level1W[]={
 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
 1,0,0,0,4,0,0,0,0,0,0,0,0,0,6,1,
 1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,
 1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,
 1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,
 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};

int level1F[]={
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};

int level1C[]={
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};

 /* Level 2 */
int level2W[]={
 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
 1,0,0,0,2,0,0,0,0,0,0,0,0,0,0,1,
 1,0,0,0,2,0,0,0,0,0,0,0,0,0,0,1,
 1,0,0,6,2,0,0,0,0,0,0,0,0,0,0,1,
 1,2,4,2,2,0,0,0,0,0,0,0,0,0,0,1,
 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
 1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,};

int level2F[]={
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};

int level2C[]={
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};