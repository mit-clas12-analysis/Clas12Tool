//***********************************************************************
//***********************************************************************
//    ____  ____  _____  _______     ___      ______       __
//   |_   ||   _||_   _||_   __ \  .'   `.   / ____ `.    /  |
//     | |__| |    | |    | |__) |/  .-.  \  `'  __) |    `| |
//     |  __  |    | |    |  ___/ | |   | |  _  |__ '.     | |
//    _| |  | |_  _| |_  _| |_    \  `-'  / | \____) | _  _| |_
//   |____||____||_____||_____|    `.___.'   \______.'(_)|_____|
//
//=======================================================================
// Autogenerated code by HIPO 3.1 io library
// Modify the main loop to suite your needs
// Date: 07/17/2018
// Author: G.Gavalian
//***********************************************************************
#include <cstdlib>
#include <iostream>
#include "cfortran.h"
using namespace std;
#include "packlib.h"

#define PAWC_SIZE 500000

typedef struct { float PAW[PAWC_SIZE]; } PAWC_DEF;
#define PAWC COMMON_BLOCK(PAWC,pawc)
COMMON_BLOCK_DEF(PAWC_DEF,PAWC);
PAWC_DEF PAWC;

typedef struct {float CBPART[PAWC_SIZE]; } CBPART_DEF;
#define PARTC COMMON_BLOCK(PARTC,partc)
COMMON_BLOCK_DEF(CBPART_DEF,PARTC);
CBPART_DEF PARTC;

void fillCommonBlock();

int main(int argc, char** argv) {

  HLIMIT(PAWC_SIZE);

  int hid=1,istat=0,icycle=0;
  int record_size=1024;
  int i,i1,j;
  int nvar;
  float r[3];
  char chtag_in[3][6]={"X","Y","Z"};
  char chtag_out[5][8],chtitl[80];
  char commonPART[500];
  float rmin[5],rmax[5];
  int   ntout = 10;
  
  int   n311[500];// = 0;

  HROPEN(1,"example","ntuple-example.hbook","N",record_size,istat);
  HBNT(ntout,"hout"," ");
  HBNAME(ntout,"b311",PARTC,"n311[0,50]:I,pid311(n311):I,px311(n311):R,py311(n311):R,pz311(n311):R");


  for(int loop = 0; loop < 48000; loop++){
    fillCommonBlock();
    HFNT(ntout);
  }
  //  HBOOKN(hid," An Ntuple",3," ",5000,chtag_in);
  /*
   for (i=0;i<100000;i++){
    for(i1=0;i1<3;i1++)
      for (j=0,r[i1]=0.;j<10;r[i1] += rand()/32768. -0.5 ,j++);
    HFN(hid,r);
    }
    nvar=5;*/
   printf("done filling....\n");
/*HGIVEN(hid,chtitl,nvar,chtag_out,rmin[0],rmax[0]);
   printf(" title obtained:%s\n variables %d\ntags:>%s< >%s< >%s<\n",
            chtitl,nvar,chtag_out[0],chtag_out[1],chtag_out[2]);
   printf(" rmin: %e  %e  %e\n",rmin[0],rmin[1],rmin[2]);
   printf(" rmax: %e  %e  %e\n",rmax[0],rmax[1],rmax[2]);*/
  HROUT(0,icycle," ");
  HREND("example");
  KUCLOS(1," ",1);
}

void fillCommonBlock(){

  int   *ptr  = reinterpret_cast<int *>(&PARTC.CBPART[0]);
  float *ptrf = reinterpret_cast<float *>(&PARTC.CBPART[0]);

  int nrows = 1+rand()%10;
  ptr[0] = nrows;
  for(int i = 0; i < nrows; i++){
    int pid = 22;
    float ifloat = ((float) rand()) / (float) RAND_MAX;
    if(ifloat<0.1) pid = 211;
    if(ifloat>=0.1&&ifloat<0.4) pid = 2212;
    int index = 1 + i;
    ptr[index] = pid;
    float ipx = ((float) rand()) / (float) RAND_MAX;
    float ipy = ((float) rand()) / (float) RAND_MAX;
    float ipz = ((float) rand()) / (float) RAND_MAX;
    ptrf[1+50*1+i] = ipx;
    ptrf[1+50*2+i] = ipy;
    ptrf[1+50*3+i] = ipz;
  }

}
//### END OF GENERATED CODE