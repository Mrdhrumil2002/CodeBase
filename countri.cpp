#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct member
{
  int sankalp = 0, viprav = 0, dhrumil = 0, jinhal = 0, anjali = 0;
  int payment = 0;
};
void print(struct member m1)
{
  cout << m1.sankalp << " " << endl;
  cout << m1.viprav << " " << endl;
  cout << m1.dhrumil << " " << endl;
  cout << m1.jinhal << " " << endl;
  cout << m1.anjali << " " << endl;
};
void paymentS(struct member *m2, int n)
{
  m2->payment = n;
  m2->anjali = m2->anjali - m2->payment / 5;
  m2->dhrumil = m2->dhrumil - m2->payment / 5;
  m2->viprav = m2->viprav - m2->payment / 5;
  m2->jinhal = m2->jinhal - m2->payment / 5;
  m2->sankalp = m2->sankalp - m2->payment / 5;
}
void totalPayment(struct member m3)
{
  int payment =
}

int main()
{
  /*
   -> first total no. of players
      sankalp viprav dhrumil
   -> now one will pay some amount n;
       //one payer
       that amount will distribute in all other people
   -> we will store individual * individual account rupees

      all other participent are user

  for example  consider 5 people
  sankalp viprav dhrumil anjali jinhal

  now ther is payment accures and
  sankalp pays the bill
   500 sankalp

   dhrumil viprav anjali jinhal ---->> 100Rs to sankalp
   at individual  level

              viprav dhrumil anjali jinhal
   Sankalp  [   100   100     100     100 ]

             sankalp viprav anjali jinhal
   dhrumil [   -100      0     0       0 ]

   same goes with viprav anjali and jinhal

   every time some one will pay all the counter will change
   at lasttt


   every value will show
  */
  // int numberOfMembers;
  // cout << "Enter the number of members :";
  // cin >> numberOfMembers;

  // for (int i = 0; i < numberOfMembers; i++)
  // {
  //   int temp1;
  //   cout << "Enter the " << i << "th member's name" << endl;
  //   cin >> temp1;
  /*         V1       D1       J1      A1     S1
  sankalp  : viprav dhrumil jinhal anjali
  viprav   : sankalp dhrumil jinhal anjali
  dhrumil  : viprav sankalp jinhal anjali
  jinhal   : viprav sankalp dhrumil anjali
  anjali  :  viprav sankalp dhrumil jinhal



  transection 4


  sankalp pays 50 rs;
  dhrumil pays 300rs
  jinhal pays 1000rs
  viprav pays 100rs
  sankalp pays 80 rs

  // for sankalp


  /* // payment one ; sankalp pays 50 rs;
   // sankalp.payment = 50;
   // sankalp.anjali = -sankalp.payment / 5;
   // sankalp.dhrumil = -sankalp.payment / 5;
   // sankalp.viprav = -sankalp.payment / 5;
   // sankalp.jinhal = -sankalp.payment / 5;

   // // payment two ; dhrumil pays 300rs
   // dhrumil.payment = 300;
   // dhrumil.anjali = -dhrumil.payment / 5;
   // dhrumil.sankalp = -dhrumil.payment / 5;
   // dhrumil.viprav = -dhrumil.payment / 5;
   // dhrumil.jinhal = -dhrumil.payment / 5;

   // // paymwnt three ; jinhal pays 1000rs
   // jinhal.payment = 1000;
   // jinhal.anjali = -jinhal.payment / 5;
   // jinhal.sankalp = -jinhal.payment / 5;
   // jinhal.viprav = -jinhal.payment / 5;
   // jinhal.jinhal = -jinhal.payment / 5;

   // // viprav pays 100rs
   // viprav.payment = 100;
   // viprav.anjali = -viprav.payment / 5;
   // viprav.sankalp = -viprav.payment / 5;
   // viprav.viprav = -viprav.payment / 5;
   // viprav.jinhal = -viprav.payment / 5;

   // //  sankalp pays 80 rs
   // sankalp.payment = 80;
   // sankalp.anjali = sankalp.anjali - sankalp.payment / 5;
   // sankalp.dhrumil = sankalp.dhrumil - sankalp.payment / 5;
   // sankalp.viprav = sankalp.viprav - sankalp.payment / 5;
   // sankalp.jinhal = sankalp.jinhal - sankalp.payment / 5;*/

  struct member sankalp, viprav, dhrumil, anjali, jinhal;

  payment(&sankalp, 50);
  payment(&dhrumil, 300);
  payment(&jinhal, 1000);
  payment(&viprav, 100);
  payment(&sankalp, 80);

  int totalPayment()
  {
    cout << sankalp.payment + anjali.payment + dhrumil.payment + jinhal.payment + viprav.payment << endl;
  };
  print(sankalp);
  // print(dhrumil);
  // print(anjali);
  // print(jinhal);

  map<string, int> sankalp;
  sankalp[payment] = 0;
  sankalp[viprav] = 0;
  sankalp[dhrumil] = 0;
  sankalp[anjali] = 0;
  sankalp[jinhal] = 0;
  sankalp[sankalp] = 0;

  void payments(map<string, int> * mem1, int n)
  {
    mem1->payment.second = n;
    mem1->anjali.second = m2->anjali.second - m2->payment.second / 5;
  }

  return 0;
}