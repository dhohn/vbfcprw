#include "HLeptonsCPRW/WeightAndOptObsWrapper.h"
#include<iostream>

int main()
{
  std::pair<double,double> oo, weights;
  double pjet1[] = {60,25,25,25};     //E,px,py,pz of nth final state parton
  double pjet2[] = {76,44,12,24};
  double pjet3[] = {23,70,11,111};
  double phiggs[] = {123,12,44,123};  //E,px,py,pz of Higgs boson make sure that four-momentum conservation holds 
  double ecm = 13000;                 //proton-proton center-of mass energy in GeV
  double mH = 125;                    //mass of Higgs boson in Gev
  int npafin = 2;                     //number of partons in final state  either  2 or 3
  double x1 = 0.2;                    //Bjorken x of incoming partons, 1 in + z , 2 in -z direction
  double x2 = 0.3;
  int pdf1 = 1;                       //from -6 to 6: pdfs for 1st and 2nd parton
  int pdf2 = 1;
  int flavour1In = 1;                 //flavour of incoming/outgoing parton n
  int flavour2In = 1;                 //flavour assignment: t = 6  b = 5 c = 4, s = 3, u = 2, d = 1   
  int flavour1Out = 1;                //anti-qarks with negative sign
  int flavour2Out = 1;                //gluon = 0 
  int flavour3Out = 1;
  
  

  weights = HLeptonsCPRW::getWeightsDtilde(ecm, mH , npafin,flavour1In,flavour2In,flavour1Out,flavour2Out,flavour3Out,x1,x2,pjet1,pjet2,pjet3,phiggs);
  std::cout<<"Calling getWeightsDtilde(...)! Results are: "<<
  weights.first<<" , "<<weights.second<<std::endl;

  oo = HLeptonsCPRW::getOptObs(ecm, mH ,x1,x2,pdf1,pdf2,pjet1,pjet2,phiggs);
  std::cout<<"Calling getOptObs(...)! Results are: "<<
  oo.first<<" , "<<oo.second<<std::endl;

  std::cout<<"Calling getReweight(...)! Result is: "<<
  HLeptonsCPRW::getReweight(ecm, mH, 1 , 
  0.5, 0.5, 0.5, 0.5, 0.5, //rsmin,din,dbin,dtin,dtbin
  0.5, 0.5, 0.5,           //a1hwwin,a2hwwin,a3hwwin
  0.5, 0.5, 0.5,           //a1haain,a2haain,a3haain
  0.5, 0.5, 0.5,           //a1hazin,a2hazin,a3hazin
  0.5, 0.5, 0.5,           //a1hzzin,a2hzzin,a3hzzin
  0.5,                     //lambdahvvin for formfactor if set to positive value
  npafin,flavour1In,flavour2In,flavour1Out,flavour2Out,flavour3Out,
  x1,x2,pjet1,pjet2,pjet3,phiggs)
  <<std::endl;
  return 1;
}
