#include "model.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static double dist(TPoint a,TPoint b){return hypot(a.x-b.x,a.y-b.y);}
static void inside(int w,int h,int x,int y){assert(x>=0 && x<w && y>=0 && y<h);if(w==260)assert(hypot(x-129.5,y-129.5)<129);}
static double rect_distance(TPoint p,TPoint c,int rx,int ry){int dx=abs(p.x-c.x)-rx,dy=abs(p.y-c.y)-ry;return hypot(dx>0?dx:0,dy>0?dy:0);}
int main(void){
 double pi=acos(-1.0);
 for(int platform=0;platform<2;platform++){
  int w=platform?260:200,h=platform?260:228;double closest=10000;int pose=0;
  for(int mode=1;mode<=2;mode++)for(int t=0;t<1440;t++){
   int hour=t/60,minute=t%60;TLayout a;t_layout(w,h,hour,minute,mode,false,&a);assert(t_bounds(w,h,&a));
   assert(dist(a.center[0],a.center[1])<a.radius[0]+a.radius[1]);
   for(int i=0;i<2;i++){
    double angle=(i?minute*6:(hour%12)*30+minute*.5)*pi/180;
    assert(abs(a.marker[i].x-(int)lround(a.center[i].x+a.radius[i]*sin(angle)))<=1);assert(abs(a.marker[i].y-(int)lround(a.center[i].y-a.radius[i]*cos(angle)))<=1);
    int rr=a.marker_radius[i]+2;for(int y=-rr;y<=rr;y++)for(int x=-rr;x<=rr;x++)if(x*x+y*y<=rr*rr)inside(w,h,a.marker[i].x+x,a.marker[i].y+y);
    for(int j=0;j<2;j++){
     TPoint number={a.center[j].x,a.center[j].y+3},legend={a.center[j].x,a.center[j].y-17};
     assert(rect_distance(a.marker[i],number,13,10)>rr+1);assert(rect_distance(a.marker[i],legend,j?9:12,4)>rr+1);
    }
    assert(a.value[i]==(i?minute:mode==2?hour:hour%12?hour%12:12));
   }
   for(int i=0;i<2;i++)for(int n=0;n<(i?60:12);n++)for(int j=0;j<2;j++)inside(w,h,a.tick[i][n][j].x,a.tick[i][n][j].y);
   double d=dist(a.marker[0],a.marker[1]);if(d<closest){closest=d;pose=t;}
   TLayout b;t_layout(w,h,(t+1)%1440/60,(t+1)%60,mode,false,&b);assert(dist(a.marker[0],b.marker[0])<3);assert(dist(a.marker[1],b.marker[1])<8);
  }
  printf("PASS: %dx%d full-day geometry/formats/bounds/label-clearance/rollover; closest crossing %02d:%02d distance%.1f\n",w,h,pose/60,pose%60,closest);
 }
 assert(t_hour(0,1,true)==12);assert(t_hour(0,2,false)==0);assert(t_hour(13,0,true)==13);assert(t_hour(13,0,false)==1);assert(t_hour(23,2,false)==23);assert(t_hour(12,1,false)==12);
 char date[20];t_date(2026,11,8,0,date,20);assert(!strcmp(date,""));t_date(2026,11,8,1,date,20);assert(!strcmp(date,"2026-11-08"));t_date(2026,11,8,2,date,20);assert(!strcmp(date,"11/08/2026"));t_date(2026,11,8,3,date,20);assert(!strcmp(date,"08/11/2026"));
 return 0;
}
