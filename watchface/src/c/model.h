#pragma once
#include <stdint.h>
#include <stdbool.h>
typedef struct {int16_t x,y;} TPoint;
typedef struct {
 TPoint center[2],marker[2],tick[2][60][2];
 int radius[2],marker_radius[2],angle[2],value[2];
} TLayout;
int t_sin(int angle);
TPoint t_point(TPoint p,int radius,int angle);
bool t_24(int mode,bool system24);
int t_hour(int hour,int mode,bool system24);
void t_date(int year,int month,int day,int mode,char *out,int n);
void t_layout(int width,int height,int hour,int minute,int mode,bool system24,TLayout *out);
bool t_bounds(int width,int height,const TLayout *out);
