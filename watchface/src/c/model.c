#include "model.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
static const int16_t SINE[91]={0,286,572,857,1143,1428,1713,1997,2280,2563,2845,3126,3406,3686,3964,4240,4516,4790,5063,5334,5604,5872,6138,6402,6664,6924,7182,7438,7692,7943,8192,8438,8682,8923,9162,9397,9630,9860,10087,10311,10531,10749,10963,11174,11381,11585,11786,11982,12176,12365,12551,12733,12911,13085,13255,13421,13583,13741,13894,14044,14189,14330,14466,14598,14726,14849,14968,15082,15191,15296,15396,15491,15582,15668,15749,15826,15897,15964,16026,16083,16135,16182,16225,16262,16294,16322,16344,16362,16374,16382,16384};
int t_sin(int angle){
 angle%=3600;if(angle<0)angle+=3600;
 int sign=1;if(angle>=1800){sign=-1;angle-=1800;}if(angle>900)angle=1800-angle;
 int degree=angle/10,part=angle%10;
 return sign*(SINE[degree]+(degree<90?(SINE[degree+1]-SINE[degree])*part/10:0));
}
static int rounded(int value){return value>=0?(value+8192)/16384:-((-value+8192)/16384);}
TPoint t_point(TPoint p,int radius,int angle){TPoint q={p.x+rounded(radius*t_sin(angle)),p.y-rounded(radius*t_sin(angle+900))};return q;}
bool t_24(int mode,bool system24){return mode==2 || (mode==0 && system24);}
int t_hour(int hour,int mode,bool system24){return t_24(mode,system24)?hour:(hour%12?hour%12:12);}
void t_date(int year,int month,int day,int mode,char *out,int n){
 if(mode==1)snprintf(out,n,"%04d-%02d-%02d",year,month,day);
 else if(mode==2)snprintf(out,n,"%02d/%02d/%04d",month,day,year);
 else if(mode==3)snprintf(out,n,"%02d/%02d/%04d",day,month,year);
 else if(n>0)out[0]=0;
}
void t_layout(int width,int height,int hour,int minute,int mode,bool system24,TLayout *out){
 (void)height;memset(out,0,sizeof(*out));bool round=width==260;
 out->center[0]=(TPoint){round?93:70,round?96:82};out->center[1]=(TPoint){round?164:128,round?169:145};
 out->radius[0]=round?62:50;out->radius[1]=round?58:47;
 out->marker_radius[0]=round?10:9;out->marker_radius[1]=round?7:6;
 out->angle[0]=(hour%12)*300+minute*5;out->angle[1]=minute*60;
 out->value[0]=t_hour(hour,mode,system24);out->value[1]=minute;
 for(int i=0;i<2;i++){
  out->marker[i]=t_point(out->center[i],out->radius[i],out->angle[i]);
  int count=i?60:12;
  for(int n=0;n<count;n++){int length=i?(n%5?2:6):5;out->tick[i][n][0]=t_point(out->center[i],out->radius[i]-length,n*(i?60:300));out->tick[i][n][1]=t_point(out->center[i],out->radius[i],n*(i?60:300));}
 }
}
static bool inside(int w,int h,int x,int y){
 if(x<0||x>=w||y<0||y>=h)return false;
 if(w==260){int dx=2*x-259,dy=2*y-259;if(dx*dx+dy*dy>258*258)return false;}
 return true;
}
bool t_bounds(int w,int h,const TLayout *l){
 for(int i=0;i<2;i++){
  for(int a=0;a<3600;a+=100){TPoint p=t_point(l->marker[i],l->marker_radius[i]+2,a);if(!inside(w,h,p.x,p.y))return false;}
  for(int n=0;n<(i?60:12);n++)for(int j=0;j<2;j++)if(!inside(w,h,l->tick[i][n][j].x,l->tick[i][n][j].y))return false;
 }
 return true;
}
