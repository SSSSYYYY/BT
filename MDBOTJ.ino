#include <SD.h>
#include <SPI.h>
#include <Ethernet.h>

// char data;
// String teadata;
//String data
//#include "JsonInit_.h"
//
//#include "AccelStepper.h"
//#include "Configuration.h"
//#include <Vector.h>
//#include <Servo.h>
///pump identification
File myFile;

long ttt;
String aaa;

const int smt = 1; // sweet milktea p1
const int usmt = 2; // unsweet milktea p2
const int gt = 3; // greentea p3
const int red = 4; // red p4
const int yellow = 5; // yellow p5
const int sugar = 6; // sugar p6
const int milk = 7; // milk p7
const int wpo = 8; //wpo p8

///velocity of liquid
const double v_smt = 0.07;
const double v_usmt = 0.065;
const double v_gt = 0.066;
const double v_red = 0.066;
const double v_yellow = 0.066;
const double v_sugar = 0.066;
const double v_milk = 0.066;
const double v_wpo = 0.066;

const int pump1 = 22; //smt
const int pump2 = 24; //usmt
const int pump3 = 26; //gt
const int pump4 = 28; //red
const int pump5 = 30; //yellow
const int pump6 = 32; //sugar
const int pump7 = 34; //milk
const int pump8 = 36; //wpo

//volum of teas
const int milk100 = 300;
const int milk75 = 350;
const int milk50 = 400;
const int milk25 = 450;
const int milk0 = 500;

const int gt100 = 230;
const int gt75 = 280;
const int gt50 = 330;
const int gt25 = 380;
const int gt0 = 430;

const int volum_yellow = 20;
const int volum_red = 20;

const int volum_gt_100 = 230;
const int volum_gt_75 = 250;
const int volum_gt_50 = 280;
const int volum_gt_25 = 310;
const int volum_gt_0 = 350;

const int volum_wpo_100 = 200;
const int volum_wpo_75 = 225;
const int volum_wpo_50 = 250;
const int volum_wpo_25 = 275;
const int volum_wpo_0 = 300;








void recipe(int buttonstate, long t)
{
//    Serial.println("Removing data.txt...");
//    SD.remove("data.txt");
//    
    switch (buttonstate)
    {
        case 0: //MT_I100_S100
            pump_control(smt, 400, t);
            break;
        
        case 1: //MT_I100_S75
            pump_control2(smt, 300, usmt, 100, t);
            break;
        
        case 2: //MT_I100_S50
            pump_control2(smt, 200, usmt, 200, t);
            break;
        
        case 3: //MT_I100_S25
            pump_control2(smt, 100, usmt, 300, t);
            break;
        
        case 4: //MT_I75_S100
            pump_control(smt, 450, t);
            break;

        case 5: //MT_I75_S75
            pump_control2(smt, 337.5, usmt, 112.5, t);
            break;

        case 6: //MT_I75_S50
            pump_control2(smt, 225, usmt, 225, t);
            break;
        
        case 7: //MT_I75_S25
            pump_control2(smt, 112.5, usmt, 337.5, t);
            break;
        
        case 8: //MT_I50_S100
            pump_control(smt, 500, t);
            break;

        case 9: //MT_I50_S75
            pump_control2(smt, 375, usmt, 125, t);
            break;

        case 10: //MT_I50_S50
            pump_control2(smt, 250, usmt, 250, t);
            break;
        
        case 11: //MT_I50_S25
            pump_control2(smt, 125, usmt, 375, t);
            break;
        
        case 12: //MT_I25_S100
            pump_control(smt, 550, t);
            break;

        case 13: //MT_I25_S75
            pump_control2(smt, 412.5, usmt, 137.5, t);
            break;

        case 14: //MT_I25_S50
            pump_control2(smt, 275, usmt, 275, t);
            break;
        
        case 15: //MT_I25_S25
            pump_control2(smt, 137.5, usmt, 412.5, t);
            break;

        case 16: //MT_I0_S100
            pump_control(smt, 600, t);
            break;

        case 17: //MT_I0_S75
            pump_control2(smt, 450, usmt, 150, t);
            break;

        case 18: //MT_I0_S50
            pump_control2(smt, 300, usmt, 300, t);
            break;
        
        case 19: //MT_I0_S25
            pump_control2(smt, 150, usmt, 450, t);
            break;
        
        case 20: //BSL_I100_S100
            pump_control(milk, milk100, t);
            break;

        case 21: //BSL_I100_S100
            pump_control(milk, milk100, t);
            break;

        case 22: //BSL_I100_S100
            pump_control(milk, milk100, t);
            break;

        case 23: //BSL_I100_S100
            pump_control(milk, milk100, t);
            break;

        case 24: //BSL_I75_S100
            pump_control(milk, milk75, t);
            break;

        case 25: //BSL_I75_S100
            pump_control(milk, milk75, t);
            break;

        case 26: //BSL_I75_S100
            pump_control(milk, milk75, t);
            break;

        case 27: //BSL_I75_S100
            pump_control(milk, milk75, t);
            break;

        case 28: //BSL_I50_S100
            pump_control(milk, milk50, t);
            break;

        case 29: //BSL_I50_S100
            pump_control(milk, milk50, t);
            break;

        case 30: //BSL_I50_S100
            pump_control(milk, milk50, t);
            break;

        case 31: //BSL_I50_S100
            pump_control(milk, milk50, t);
            break;

        case 32: //BSL_I25_S100
            pump_control(milk, milk25, t);
            break;

        case 33: //BSL_I25_S100
            pump_control(milk, milk25, t);
            break;

        case 34: //BSL_I25_S100
            pump_control(milk, milk25, t);
            break;

        case 35: //BSL_I25_S100
            pump_control(milk, milk25, t);
            break;

        case 36: //BSL_I0_S100
            pump_control(milk, milk0, t);
            break;

        case 37: //BSL_I0_S100
            pump_control(milk, milk0, t);
            break;

        case 38: //BSL_I0_S100
            pump_control(milk, milk0, t);
            break;

        case 39: //BSL_I0_S100
            pump_control(milk, milk0, t);
            break;

        case 40: //PG_I100_S100
            pump_control3( sugar, 50, gt, 290, red, volum_yellow, t);
            break;

        case 41: //PG_I100_S75
            pump_control3( red, volum_yellow, sugar, 38, gt, 290, t);
            break;

        case 42: //PG_I100_S50
            pump_control3(red, volum_yellow, sugar, 25, gt, 290, t);
            break;

        case 43: //PG_I100_S25
            pump_control3(red, volum_yellow, sugar, 15, gt, 290, t);
            break;
// below need to be updated
        case 44: //PG_I75_S100
            pump_control3(red, volum_yellow, sugar, 50, gt, 290, t);
            break;
        
        case 45: //PG_I75_S75
            pump_control3(red, volum_yellow, sugar, 38, gt, 290, t);
            break;

        case 46: //PG_I75_S50
            pump_control3(red, volum_yellow, sugar, 25, gt, 290, t);
            break;

        case 47: //PG_I75_S25
            pump_control3(red, volum_yellow, sugar, 15, gt, 290, t);
            break;

        case 48: //PG_I50_S100
            pump_control3(red, volum_yellow, sugar, 50, gt, 290, t);
            break;
        
        case 49: //PG_I50_S75
            pump_control3(red, volum_yellow, sugar, 38, gt, 290, t);
            break;

        case 50: //PG_I50_S50
            pump_control3(red, volum_yellow, sugar, 25, gt, 290, t);
            break;

        case 51: //PG_I50_S25
            pump_control3(red, volum_yellow, sugar, 15, gt, 290, t);
            break;

        case 52: //PG_I25_S100
            pump_control3(red, volum_yellow, sugar, 50, gt, 290, t);
            break;
        
        case 53: //PG_I25_S75
            pump_control3(red, volum_yellow, sugar, 38, gt, 290, t);
            break;

        case 54: //PG_I25_S50
            pump_control3(red, volum_yellow, sugar, 25, gt, 290, t);
            break;

        case 55: //PG_I25_S25
            pump_control3(red, volum_yellow, sugar, 15, gt, 290, t);
            break;

        case 56: //PG_I0_S100

            pump_control3(red, volum_yellow, sugar, 50, gt, 290, t);
            
            break;
        
        case 57: //PG_I0_S75
            pump_control3(red, volum_yellow, sugar, 38, gt, 290, t);
            break;

        case 58: //PG_I0_S50
            pump_control3(red, volum_yellow, sugar, 25, gt, 290, t);
            break;

        case 59: //PG_I0_S25
            pump_control3(red, volum_yellow, sugar, 15, gt, 290, t);
            break;

        case 60: //FTOF_I100_S100
            pump_control3(gt, volum_gt_100, yellow, volum_yellow, sugar, 40, t);
            break;

        case 61: //FTOF_I100_S75
            pump_control3(gt, volum_gt_100 + 10, yellow, volum_yellow, sugar, 30, t);
            break;

        case 62: //FTOF_I100_S50
            pump_control3(gt, volum_gt_100 + 20, yellow, volum_yellow, sugar, 20, t);
            break;

        case 63: //FTOF_I100_S25
            pump_control3(gt, volum_gt_100 + 30, yellow, volum_yellow, sugar, 10, t);
            break;

        case 64: //FTOF_I75_S100
            pump_control3(gt, volum_gt_75, yellow, volum_yellow, sugar, 44, t);
            break;

        case 65: //FTOF_I75_S75
            pump_control3(gt, volum_gt_75 + 11, yellow, volum_yellow, sugar, 33, t);
            break;

        case 66: //FTOF_I75_S50
            pump_control3(gt, volum_gt_75 + 22, yellow, volum_yellow, sugar, 22, t);
            break;

        case 67: //FTOF_I75_S25
            pump_control3(gt, volum_gt_75 + 33, yellow, volum_yellow, sugar, 11, t);
            break;

        case 68: //FTOF_I50_S100
            pump_control3(gt, volum_gt_50, yellow, volum_yellow, sugar, 48, t);
            break;

        case 69: //FTOF_I50_S75
            pump_control3(gt, volum_gt_50 + 12, yellow, volum_yellow, sugar, 36, t);
            break;

        case 70: //FTOF_I50_S50
            pump_control3(gt, volum_gt_50 + 24, yellow, volum_yellow, sugar, 24, t);
            break;

        case 71: //FTOF_I50_S25
            pump_control3(gt, volum_gt_50 + 36, yellow, volum_yellow, sugar, 12, t);
            break;

        case 72: //FTOF_I25_S100
            pump_control3(gt, volum_gt_25, yellow, volum_yellow, sugar, 52, t);
            break;

        case 73: //FTOF_I25_S75
            pump_control3(gt, volum_gt_25 + 13, yellow, volum_yellow, sugar, 39, t);
            break;

        case 74: //FTOF_I25_S50
            pump_control3(gt, volum_gt_25 + 26, yellow, volum_yellow, sugar, 26, t);
            break;

        case 75: //FTOF_I25_S25
            pump_control3(gt, volum_gt_25 + 39, yellow, volum_yellow, sugar, 13, t);
            break;

        case 76: //FTOF_I0_S100
            pump_control3(gt, volum_gt_0, yellow, volum_yellow, sugar, 56, t);
            break;

        case 77: //FTOF_I0_S75
            pump_control3(gt, volum_gt_0 + 14, yellow, volum_yellow, sugar, 42, t);
            break;

        case 78: //FTOF_I0_S50
            pump_control3(gt, volum_gt_0 + 28, yellow, volum_yellow, sugar, 28, t);
            break;

        case 79: //FTOF_I0_S25
            pump_control3(gt, volum_gt_0 + 42, yellow, volum_yellow, sugar, 14, t);
            break;

        case 80: //GF_I100_S100
            pump_control3(gt, volum_gt_100, red, volum_yellow, sugar, 48, t);
            break;

        case 81: //GF_I100_S75
            pump_control3(gt, volum_gt_100 + 12, red, volum_yellow, sugar, 36, t);
            break;

        case 82: //GF_I100_S50
            pump_control3(gt, volum_gt_100 + 24, red, volum_yellow, sugar, 24, t);
            break;

        case 83: //GF_I100_S50
            pump_control3(gt, volum_gt_100 + 36, red, volum_yellow, sugar, 12, t);
            break;

        case 84: //GF_I75_S100
            pump_control3(gt, volum_gt_75, red, volum_yellow, sugar, 44, t);
            break;

        case 85: //GF_I75_S75
            pump_control3(gt, volum_gt_75 + 11, red, volum_yellow, sugar, 33, t);
            break;

        case 86: //GF_I75_S50
            pump_control3(gt, volum_gt_75 + 22, red, volum_yellow, sugar, 22, t);
            break;

        case 87: //GF_I75_S25
            pump_control3(gt, volum_gt_75 + 33, red, volum_yellow, sugar, 11, t);
            break;

        case 88: //GF_I50_S100
            pump_control3(gt, volum_gt_50, red, volum_yellow, sugar, 48, t);
            break;

        case 89: //GF_I50_S75
            pump_control3(gt, volum_gt_50 + 12, red, volum_yellow, sugar, 36, t);
            break;

        case 90: //GF_I50_S50
            pump_control3(gt, volum_gt_50 + 24, red, volum_yellow, sugar, 24, t);
            break;

        case 91: //GF_I50_S25
            pump_control3(gt, volum_gt_50 + 36, red, volum_yellow, sugar, 12, t);
            break;

        case 92: //GF_I25_S100
            pump_control3(gt, volum_gt_25, red, volum_yellow, sugar, 52, t);
            break;

        case 93: //GF_I25_S75
            pump_control3(gt, volum_gt_25 + 13, red, volum_yellow, sugar, 39, t);
            break;

        case 94: //GF_I25_S50
            pump_control3(gt, volum_gt_25 + 26, red, volum_yellow, sugar, 26, t);
            break;

        case 95: //GF_I25_S25
            pump_control3(gt, volum_gt_25 + 39, red, volum_yellow, sugar, 13, t);
            break;

        case 96: //GF_I0_S100
            pump_control3(gt, volum_gt_0, red, volum_yellow, sugar, 56, t);
            break;

        case 97: //GF_I0_S75
            pump_control3(gt, volum_gt_0 + 14, red, volum_yellow, sugar, 42, t);
            break;

        case 98: //GF_I0_S50
            pump_control3(gt, volum_gt_0 + 28, red, volum_yellow, sugar, 28, t);
            break;

        case 99: //GF_I0_S25
            pump_control3(gt, volum_gt_0 + 42, red, volum_yellow, sugar, 14, t);
            break;

        case 100: //WPO_I100_S100
            pump_control2(wpo, volum_wpo_100, sugar, 40, t);
            break;
        
        case 101: //WPO_I100_S75
            pump_control2(wpo, volum_wpo_100 + 10, sugar, 30, t);
            break;

        case 102: //WPO_I100_S50
            pump_control2(wpo, volum_wpo_100 + 20, sugar, 20, t);
            break;
        
        case 103: //WPO_I100_S25
            pump_control2(wpo, volum_wpo_100 + 30 , sugar, 10, t);
            break;

        case 104: //WPO_I75_S100
            pump_control2(wpo, volum_wpo_75, sugar, 40, t);
            break;
        
        case 105: //WPO_I75_S75
            pump_control2(wpo, volum_wpo_75 + 10, sugar, 30, t);
            break;

        case 106: //WPO_I75_S50
            pump_control2(wpo, volum_wpo_75 + 20, sugar, 20, t);
            break;
        
        case 107: //WPO_I75_S25
            pump_control2(wpo, volum_wpo_75 + 30 , sugar, 10, t);
            break;
        case 108: //WPO_I50_S100
            pump_control2(wpo, volum_wpo_50, sugar, 40, t);
            break;
        
        case 109: //WPO_I50_S75
            pump_control2(wpo, volum_wpo_50 + 10, sugar, 30, t);
            break;

        case 110: //WPO_I50_S50
            pump_control2(wpo, volum_wpo_50 + 20, sugar, 20, t);
            break;
        
        case 111: //WPO_I50_S25
            pump_control2(wpo, volum_wpo_50 + 30 , sugar, 10, t);
            break;

        case 112: //WPO_I25_S100
            pump_control2(wpo, volum_wpo_25, sugar, 40, t);
            break;
        
        case 113: //WPO_I25_S75
            pump_control2(wpo, volum_wpo_25 + 10, sugar, 30, t);
            break;

        case 114: //WPO_I25_S50
            pump_control2(wpo, volum_wpo_25 + 20, sugar, 20, t);
            break;
        
        case 115: //WPO_I25_S25
            pump_control2(wpo, volum_wpo_25 + 30 , sugar, 10, t);
            break;

        case 116: //WPO_I0_S100
            pump_control2(wpo, volum_wpo_0, sugar, 40, t);
            break;
        
        case 117: //WPO_I0_S75
            pump_control2(wpo, volum_wpo_0 + 10, sugar, 30, t);
            break;

        case 118: //WPO_I0_S50
            pump_control2(wpo, volum_wpo_0 + 20, sugar, 20, t);
            break;
        
        case 119: //WPO_I0_S25
            pump_control2(wpo, volum_wpo_0 + 30 , sugar, 10, t);
            break;

        
        case 120: //gt_I100_S100
            pump_control2(gt, volum_wpo_100, sugar, 40, t);
            break;
        
        case 121: //gt_I100_S75
            pump_control2(gt, volum_wpo_100 + 10, sugar, 30, t);
            break;

        case 122: //gt_I100_S50
            pump_control2(gt, volum_wpo_100 + 20, sugar, 20, t);
            break;
        
        case 123: //gt_I100_S25
            pump_control2(gt, volum_wpo_100 + 30 , sugar, 10, t);
            break;

        case 124: //gt_I75_S100
            pump_control2(gt, volum_wpo_75, sugar, 40, t);
            break;
        
        case 125: //gt_I75_S75
            pump_control2(gt, volum_wpo_75 + 10, sugar, 30, t);
            break;

        case 126: //gt_I75_S50
            pump_control2(gt, volum_wpo_75 + 20, sugar, 20, t);
            break;
        
        case 127: //gt_I75_S25
            pump_control2(gt, volum_wpo_75 + 30 , sugar, 10, t);
            break;

        case 128: //gt_I50_S100
            pump_control2(gt, volum_wpo_50, sugar, 40, t);
            break;
        
        case 129: //gt_I50_S75
            pump_control2(gt, volum_wpo_50 + 10, sugar, 30, t);
            break;

        case 130: //gt_I50_S50
            pump_control2(gt, volum_wpo_50 + 20, sugar, 20, t);
            break;
        
        case 131: //gt_I50_S25
            pump_control2(gt, volum_wpo_50 + 30 , sugar, 10, t);
            break;

        case 132: //gt_I25_S100
            pump_control2(gt, volum_wpo_25, sugar, 40, t);
            break;
        
        case 133: //gt_I25_S75
            pump_control2(gt, volum_wpo_25 + 10, sugar, 30, t);
            break;

        case 134: //gt_I25_S50
            pump_control2(gt, volum_wpo_25 + 20, sugar, 20, t);
            break;
        
        case 135: //gt_I25_S25
            pump_control2(gt, volum_wpo_25 + 30 , sugar, 10, t);
            break;

        case 136: //gt_I0_S100
            pump_control2(gt, volum_wpo_0, sugar, 40, t);
            break;
        
        case 137: //gt_I0_S75
            pump_control2(gt, volum_wpo_0 + 10, sugar, 30, t);
            break;

        case 138: //gt_I0_S50
            pump_control2(gt, volum_wpo_0 + 20, sugar, 20, t);
            break;
        
        case 139: //gt_I0_S25
            pump_control2(gt, volum_wpo_0 + 30 , sugar, 10, t);
            break;
    }// end switch(buttonstate)
}//end recipe()

void pump_control(int pump, double vol, long timer_start)
{


  //pump_select(pump);
  
  //Serial.println(v_select(pump));
  double time = vol/v_select(pump);
  Serial.print("time is: ");
  Serial.println(time);
  while (millis() - timer_start <= time)
  {
    pump_select(pump);

  }//end while
  pump_close(pump);

} //end pump_control1

void pump_control2(int p1, double vol1, int p2, double vol2, long timer_start)
{


  //pump_select(pump);
  
  //Serial.println(v_select(pump));
  double time1 = vol1/v_select(p1);
  Serial.print("time is: ");
  Serial.println(time1);
  while (millis() - timer_start <= time1)
  {
    pump_select(p1);

  }//end while
  pump_close(p1);

  double time2 = time1 + vol2/v_select(p2);
  Serial.print("time is: ");
  Serial.println(time2);
  while (millis() - timer_start <= time2)
  {
    pump_select(p2);

  }//end while
  pump_close(p2);
 
} //end pump_control2

void pump_control3(int p1, double vol1, int p2, double vol2, int p3, double vol3, long timer_start)
{


  //pump_select(pump);
  
  //Serial.println(v_select(pump));
  double time1 = vol1/v_select(p1);
  Serial.print("time is: ");
  Serial.println(time1);
  while (millis() - timer_start <= time1)
  {
    pump_select(p1);

  }//end while
  pump_close(p1);

  double time2 = time1 + vol2/v_select(p2);
  Serial.print("time is: ");
  Serial.println(time2);
  while (millis() - timer_start <= time2)
  {
    pump_select(p2);

  }//end while
  pump_close(p2);

  double time3 = time2 + vol3/v_select(p3);
  Serial.print("time is: ");
  Serial.println(time3);
  while (millis() - timer_start <= time3)
  {
    pump_select(p3);

  }//end while
  pump_close(p3);
 
} //end pump_control3







long timer_start()
{
  long t = millis();
  return t;
}

// MAC address from Ethernet shield sticker under board
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 50, 20); // IP address, may need to change depending on network
EthernetServer server(80);  // create a server at port 80

String HTTP_req;          // stores the HTTP request


int tea_select_web()
{
  if (aaa.indexOf("?tea=1") > 0) return 1;
  if (aaa.indexOf("?tea=2") > 0) return 2;
  if (aaa.indexOf("?tea=3")> 0) return 3;
  if (aaa.indexOf("?tea=4")> 0) return 4;
  if (aaa.indexOf("?tea=5")> 0) return 5;
  if (aaa.indexOf("?tea=6")> 0) return 6;
  if (aaa.indexOf("?tea=7")> 0) return 7;
  return 9999;

}//end tea_select_web

int sugar_select_web()
{
  if (aaa.indexOf("&sugar=100") > 0) return 100;
  if (aaa.indexOf("&sugar=75") > 0) return 75;
  if (aaa.indexOf("&sugar=50")> 0) return 50;
  if (aaa.indexOf("&sugar=25")> 0) return 25;
  return 9999;
}//end sugar_select_web

int ice_select_web()
{
  if (aaa.indexOf("ice=100") > -1) return 100;
  if (aaa.indexOf("ice=75") > -1) return 75;
  if (aaa.indexOf("ice=50") > -1) return 50;
  if (aaa.indexOf("ice=25") > -1) return 25;
  if (aaa.indexOf("ice=0") > -1) return 0;
  return 9999;
}//end ice_select_web


double v_select(int p)
{
  if (p = 1) return 0.07; //smt
  if (p = 2) return 0.065; //usmt
  if (p = 3) return 0.066; //gt
  if (p = 4) return 0.066; //red
  if (p = 5) return 0.066; //yellow
  if (p = 6) return 0.045; //sugar
  if (p = 7) return 0.066; //milk 
  if (p = 8) return 0.066; //wpo

      
} //end select


void pump_select(int p)
  {
    Serial.print("selecting pump: ");
    Serial.println(p);
    switch (p)
      {
        case 1:
          digitalWrite(pump1, LOW);
          break;
        
        case 2:
          digitalWrite(pump2, LOW);
          break;

        case 3:
          digitalWrite(pump3, LOW);
          break;

        case 4:
          digitalWrite(pump4, LOW);
          break;

        case 5:
          digitalWrite(pump5, LOW);
          break;

        case 6:
          digitalWrite(pump6,LOW);
          break;

        case 7:
          digitalWrite(pump7,LOW);
          break;

        case 8:
          digitalWrite(pump8,LOW);
          break;
          
      }
  }

// const int chipSelect = 4;

// JsonInit_ mJson(chipSelect);

// Vector<INGREDIENTS> v_i;
// Vector<RECIPES> v_re;

void serial_init(){
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("serial port inited");
}

void initAllbutton(){
  for ( int a = 23; a < 35;){
    digitalWrite(a, HIGH);
    a = a +2;
    }
}

void initAllpins(){
  for ( int a = 22; a < 38;){
    digitalWrite(a, HIGH);
    a = a +2;
    }
}
// /*****using web server
// void reset_but(){
//   for (int b = 22; b<31; b++){
//     digitalWrite(b,HIGH);
//     }
//   }

void button_init()
{
  pinMode(23, INPUT); //MT
  pinMode(25, INPUT); //usmt
  pinMode(27, INPUT); //GT
  pinMode(29, INPUT); //RED
  pinMode(31, INPUT); //yellow
  pinMode(33, INPUT); //SUGAR
}

  
  /*****using web server

  //pin24-26 is reserved for more teas
  pinMode(27, INPUT); //S100
  pinMode(28, INPUT); //S75
  pinMode(29, INPUT); //S50
  pinMode(30, INPUT); //S25

  //pin 29-30 is reserved for S50,S25
  pinMode(31, INPUT); //I100
  pinMode(32, INPUT); //I75
  pinMode(33, INPUT); //I50
  pinMode(34, INPUT); //I25
  pinMode(35, INPUT); //I0

  //more button pins are reserved for future extension
  }
**/
void pump_init(){
  pinMode(pump1, OUTPUT); //MTS
  pinMode(pump2, OUTPUT); //MTU
  pinMode(pump3, OUTPUT); //GT
  pinMode(pump4, OUTPUT); //RED
  pinMode(pump5, OUTPUT); //yellow
  pinMode(pump6, OUTPUT); //SUGAR
  pinMode(pump7, OUTPUT); //MILK
  pinMode(pump8, OUTPUT); //WHITE PEACH OOLONG
  }

/****

  int tea_select(){
  if (digitalRead(22) == LOW){
    Serial.println("mt pressed");
    digitalWrite(22, LOW);    
    return 1; //1-mt
    }
    
//    if (sugar_select() != 8888 or ice_select() != 9999){
//      if (current_time - but_sugar_time > 50000){
//        digitalWrite(22, HIGH);
//        Serial.println("mt released");
//        but_tea_time = current_time;
//        return "7777";      
//        }
//      }
  
  
  if (digitalRead(23) == LOW){
    Serial.println("bsl pressed");
    digitalWrite(23, LOW);    
    return 2; //2-bsl
    }


  if (digitalRead(24) == LOW){
    Serial.println("P/G pressed");
    digitalWrite(24, LOW);    
    return 3; //3-P/G
    }


  if (digitalRead(25) == LOW){
    Serial.println("FT/OF pressed");
    digitalWrite(22, LOW);    
    return 4; //4-MT/OF
    }


  if (digitalRead(26) == LOW){
    Serial.println("GF pressed");
    digitalWrite(26, LOW);    
    return 5; //5-GF
    }


  if (digitalRead(36) == LOW){
    Serial.println("CWPO pressed");
    digitalWrite(36, LOW);    
    return 6; //6-CWPO
    }


  if (digitalRead(37) == LOW){
    Serial.println("CGT pressed");
    digitalWrite(37, LOW);    
    return 7; //7-CGT
    }
  return 7777; //NO INPUT RETURN 7777
  //more buttons are rese\rved
  }

int ice_select(){
  if (digitalRead(31) == LOW){
    Serial.println("ice 100 pressed");
    digitalWrite(31, LOW);
    return 100;
  }
//    if (sugar_select() != 8888 or tea_select() != "7777"){
//      if (current_time - but_ice_time > 50000){
//        digitalWrite(31, HIGH);
//        Serial.println("ice 100 released");
//        but_ice_time = current_time;      
//        return 9999;        
//        }
//      }
  
  
  if (digitalRead(32) == LOW){
    digitalWrite(32, LOW);
    Serial.println("ice 75 pressed");
    return 75;}


  if (digitalRead(33) == LOW){
    digitalWrite(33, LOW);
    Serial.println("ice 50 pressed");
    return 50;}

  if (digitalRead(34) == LOW){
    digitalWrite(34, LOW);
    Serial.println("ice 25 pressed");
    return 25;}

  if (digitalRead(35) == LOW){
    digitalWrite(35, LOW);
    Serial.println("ice 0 pressed");
    return 0;}




//    if (sugar_select() != 8888 or tea_select() != "7777"){
//      if (current_time - but_ice_time > 50000){
//        digitalWrite(32, HIGH);
//        Serial.println("ice 75 released");
//        but_ice_time = current_time;      
//        return 9999;
//        }
//      }
  
  
  return 9999;
  //more iceselects are recerved
  }

int sugar_select(){
  if (digitalRead(27) == LOW){
    Serial.println("sugar 100 pressed");
    return 100;
  }
//    if (ice_select() != 9999 or tea_select() != "7777"){
//      if (current_time - but_sugar_time > 50000){
//        digitalWrite(27, HIGH);
//        Serial.println("sugar 100 released");
//        but_sugar_time = current_time;    
//        return 8888;  
//        }
//      }
  
  if (digitalRead(28) == LOW){
    Serial.println("sugar 75 pressed");
    digitalWrite(28, LOW);
    return 75;}
//
//    if (ice_select() != 9999 or tea_select() != "7777"){
//      if (current_time - but_sugar_time > 50000){
//        digitalWrite(28, HIGH);
//        Serial.println("sugar 75 released");
//        but_sugar_time = current_time; 
//        return 8888;     
//        }
//      }
  
  
    if (digitalRead(29) == LOW){
    Serial.println("sugar 50 pressed");
    digitalWrite(29, LOW);
    return 50;}


    if (digitalRead(30) == LOW){
    Serial.println("sugar 25 pressed");
    digitalWrite(30, LOW);
    return 30;}
  
  return 8888;
  //more buttons are reserved
  }
  //end comment 
*****/



int get_button_state(int t, int i, int s)
  {      
    if ((t == 1) && (i == 100) && (s == 100)) return 0;
    if ((t == 1) && (i == 100) && (s == 75)) return 1;
    if ((t == 1) && (i == 100) && (s == 50)) return 2;
    if ((t == 1) && (i == 100) && (s == 25)) return 3;
    
    if ((t == 1) && (i == 75) && (s == 100)) return 4;
    if ((t == 1) && (i == 75) && (s == 75)) return 5;
    if ((t == 1) && (i == 75) && (s == 50)) return 6;
    if ((t == 1) && (i == 75) && (s == 25)) return 7;
    
    if ((t == 1) && (i == 50) && (s == 100)) return 8;
    if ((t == 1) && (i == 50) && (s == 75)) return 9;
    if ((t == 1) && (i == 50) && (s == 50)) return 10;
    if ((t == 1) && (i == 50) && (s == 25)) return 11;
    
    if ((t == 1) && (i == 25) && (s == 100)) return 12;
    if ((t == 1) && (i == 25) && (s == 75)) return 13;
    if ((t == 1) && (i == 25) && (s == 50)) return 14;
    if ((t == 1) && (i == 25) && (s == 25)) return 15;
    
    if ((t == 1) && (i == 0) && (s == 100)) return 16;
    if ((t == 1) && (i == 0) && (s == 75)) return 17;
    if ((t == 1) && (i == 0) && (s == 50)) return 18;
    if ((t == 1) && (i == 0) && (s == 25)) return 19;
    
    if ((t == 2) && (i == 100) && (s == 100)) return 20;
    if ((t == 2) && (i == 100) && (s == 75)) return 21;
    if ((t == 2) && (i == 100) && (s == 50)) return 22;
    if ((t == 2) && (i == 100) && (s == 25)) return 23;
    
    if ((t == 2) && (i == 75) && (s == 100)) return 24;
    if ((t == 2) && (i == 75) && (s == 75)) return 25;
    if ((t == 2) && (i == 75) && (s == 50)) return 26;
    if ((t == 2) && (i == 75) && (s == 25)) return 27;
    
    if ((t == 2) && (i == 50) && (s == 100)) return 28;
    if ((t == 2) && (i == 50) && (s == 75)) return 29;
    if ((t == 2) && (i == 50) && (s == 50)) return 30;
    if ((t == 2) && (i == 50) && (s == 25)) return 31;
    
    if ((t == 2) && (i == 25) && (s == 100)) return 32;
    if ((t == 2) && (i == 25) && (s == 75)) return 33;
    if ((t == 2) && (i == 25) && (s == 50)) return 34;
    if ((t == 2) && (i == 25) && (s == 25)) return 35;
    
    if ((t == 2) && (i == 0) && (s == 100)) return 36;
    if ((t == 2) && (i == 0) && (s == 75)) return 37;
    if ((t == 2) && (i == 0) && (s == 50)) return 38;
    if ((t == 2) && (i == 0) && (s == 25)) return 39;

    if ((t == 3) && (i == 100) && (s == 100)) return 40;
    if ((t == 3) && (i == 100) && (s == 75)) return 41;
    if ((t == 3) && (i == 100) && (s == 50)) return 42;
    if ((t == 3) && (i == 100) && (s == 25)) return 43;

    if ((t == 3) && (i == 75) && (s == 100)) return 44;
    if ((t == 3) && (i == 75) && (s == 75)) return 45;
    if ((t == 3) && (i == 75) && (s == 50)) return 46;
    if ((t == 3) && (i == 75) && (s == 25)) return 47;

    if ((t == 3) && (i == 50) && (s == 100)) return 48;
    if ((t == 3) && (i == 50) && (s == 75)) return 49;
    if ((t == 3) && (i == 50) && (s == 50)) return 50;
    if ((t == 3) && (i == 50) && (s == 25)) return 51;

    if ((t == 3) && (i == 25) && (s == 100)) return 52;
    if ((t == 3) && (i == 25) && (s == 75)) return 53;
    if ((t == 3) && (i == 25) && (s == 50)) return 54;
    if ((t == 3) && (i == 25) && (s == 25)) return 55;

    if ((t == 3) && (i == 0) && (s == 100)) return 56;
    if ((t == 3) && (i == 0) && (s == 75)) return 57;
    if ((t == 3) && (i == 0) && (s == 50)) return 58;
    if ((t == 3) && (i == 0) && (s == 25)) return 59;

    if ((t == 4) && (i == 100) && (s == 100)) return 60;
    if ((t == 4) && (i == 100) && (s == 75)) return 61;
    if ((t == 4) && (i == 100) && (s == 50)) return 62;
    if ((t == 4) && (i == 100) && (s == 25)) return 63;

    if ((t == 4) && (i == 75) && (s == 100)) return 64;
    if ((t == 4) && (i == 75) && (s == 75)) return 65;
    if ((t == 4) && (i == 75) && (s == 50)) return 66;
    if ((t == 4) && (i == 75) && (s == 25)) return 67;

    if ((t == 4) && (i == 50) && (s == 100)) return 68;
    if ((t == 4) && (i == 50) && (s == 75)) return 69;
    if ((t == 4) && (i == 50) && (s == 50)) return 70;
    if ((t == 4) && (i == 50) && (s == 25)) return 71;

    if ((t == 4) && (i == 25) && (s == 100)) return 72;
    if ((t == 4) && (i == 25) && (s == 75)) return 73;
    if ((t == 4) && (i == 25) && (s == 50)) return 74;
    if ((t == 4) && (i == 25) && (s == 25)) return 75;

    if ((t == 4) && (i == 0) && (s == 100)) return 76;
    if ((t == 4) && (i == 0) && (s == 75)) return 77;
    if ((t == 4) && (i == 0) && (s == 50)) return 78;
    if ((t == 4) && (i == 0) && (s == 25)) return 79;

    if ((t == 5) && (i == 100) && (s == 100)) return 80;
    if ((t == 5) && (i == 100) && (s == 75)) return 81;
    if ((t == 5) && (i == 100) && (s == 50)) return 82;
    if ((t == 5) && (i == 100) && (s == 25)) return 83;

    if ((t == 5) && (i == 75) && (s == 100)) return 84;
    if ((t == 5) && (i == 75) && (s == 75)) return 85;
    if ((t == 5) && (i == 75) && (s == 50)) return 86;
    if ((t == 5) && (i == 75) && (s == 25)) return 87;

    if ((t == 5) && (i == 50) && (s == 100)) return 88;
    if ((t == 5) && (i == 50) && (s == 75)) return 89;
    if ((t == 5) && (i == 50) && (s == 50)) return 90;
    if ((t == 5) && (i == 50) && (s == 25)) return 91;

    if ((t == 5) && (i == 25) && (s == 100)) return 92;
    if ((t == 5) && (i == 25) && (s == 75)) return 93;
    if ((t == 5) && (i == 25) && (s == 50)) return 94;
    if ((t == 5) && (i == 25) && (s == 25)) return 95;

    if ((t == 5) && (i == 0) && (s == 100)) return 96;
    if ((t == 5) && (i == 0) && (s == 75)) return 97;
    if ((t == 5) && (i == 0) && (s == 50)) return 98;
    if ((t == 5) && (i == 0) && (s == 25)) return 99;

    if ((t == 6) && (i == 100) && (s == 100)) return 100;
    if ((t == 6) && (i == 100) && (s == 75)) return 101;
    if ((t == 6) && (i == 100) && (s == 50)) return 102;
    if ((t == 6) && (i == 100) && (s == 25)) return 103;

    if ((t == 6) && (i == 75) && (s == 100)) return 104;
    if ((t == 6) && (i == 75) && (s == 75)) return 105;
    if ((t == 6) && (i == 75) && (s == 50)) return 106;
    if ((t == 6) && (i == 75) && (s == 25)) return 107;
    

    if ((t == 6) && (i == 50) && (s == 100)) return 108;
    if ((t == 6) && (i == 50) && (s == 75)) return 109;
    if ((t == 6) && (i == 50) && (s == 50)) return 110;
    if ((t == 6) && (i == 50) && (s == 25)) return 111;

    if ((t == 6) && (i == 25) && (s == 100)) return 112;
    if ((t == 6) && (i == 25) && (s == 75)) return 113;
    if ((t == 6) && (i == 25) && (s == 50)) return 114;
    if ((t == 6) && (i == 25) && (s == 25)) return 115;

    if ((t == 6) && (i == 0) && (s == 100)) return 116;
    if ((t == 6) && (i == 0) && (s == 75)) return 117;
    if ((t == 6) && (i == 0) && (s == 50)) return 118;
    if ((t == 6) && (i == 0) && (s == 25)) return 119;

    if ((t == 7) && (i == 100) && (s == 100)) return 120;
    if ((t == 7) && (i == 100) && (s == 75)) return 121;
    if ((t == 7) && (i == 100) && (s == 50)) return 122;
    if ((t == 7) && (i == 100) && (s == 25)) return 123;

    if ((t == 7) && (i == 75) && (s == 100)) return 124;
    if ((t == 7) && (i == 75) && (s == 75)) return 125;
    if ((t == 7) && (i == 75) && (s == 50)) return 126;
    if ((t == 7) && (i == 75) && (s == 25)) return 127;

    if ((t == 7) && (i == 50) && (s == 100)) return 128;
    if ((t == 7) && (i == 50) && (s == 75)) return 129;
    if ((t == 7) && (i == 50) && (s == 50)) return 130;
    if ((t == 7) && (i == 50) && (s == 25)) return 131;

    if ((t == 7) && (i == 25) && (s == 100)) return 132;
    if ((t == 7) && (i == 25) && (s == 75)) return 133;
    if ((t == 7) && (i == 25) && (s == 50)) return 134;
    if ((t == 7) && (i == 25) && (s == 25)) return 135;

    if ((t == 7) && (i == 0) && (s == 100)) return 136;
    if ((t == 7) && (i == 0) && (s == 75)) return 137;
    if ((t == 7) && (i == 0) && (s == 50)) return 138;
    if ((t == 7) && (i == 0) && (s == 25)) return 139;

    

    

    return 9999;
    
    

    
  }

void pump_close(int p)
  {
    Serial.print("closing pump :");
    Serial.println(p);
    switch (p)
      {
        case 1:
          digitalWrite(22, HIGH);
          break;
        
        case 2:
          digitalWrite(24, HIGH);
          break;

        case 3:
          digitalWrite(26, HIGH);
          break;

        case 4:
          digitalWrite(28, HIGH);
          break;

        case 5:
          digitalWrite(30, HIGH);
          break;

        case 6:
          digitalWrite(32,HIGH);
          break;

        case 7:
          digitalWrite(34,HIGH);
          break;

        case 8:
          digitalWrite(36,HIGH);
          break;
          
      }
  }

// void liquid_v(int p , int volum)
// {
//   switch (p)
//       {
//         case 1:
//           delay(volum/0.07);
//           break;
        
//         case 2:
//           delay(volum/0.065);
//           break;

//         case 3:
//           delay(volum/0.065);
//           break;

//         case 4:
//           delay(volum/0.065);
//           break;

//         case 5:
//           delay(volum/0.065);
//           break;

//         case 6:
//           delay(volum/0.045);
//           break;

//         case 7:
//           delay(volum/0.065);
//           break;

//         case 8:
//           delay(volum/0.065);
//           break;
// }

//}
// void get_RecipeData(int butState)
// {
//   int bufIndex = butState;
//   for (int i = 0; i < v_re.size(); i++)
//   {
//     if(v_re[i].id == 0 && v_re[i].amount == 0) {bufIndex--; continue;} //searching the right one
//     if (bufIndex < 0) return;
//     if (bufIndex == 0)
//     { 
//       int pump = v_i[v_re[i].id - 1].coordinate;
//       pump_select(pump);
//       liquid_v(pump, v_re[i].amount);
//       //delay(v_re[i].amount/0.067); 
//       pump_close(pump);
       
//       //pourZ(v_re[i].amount/ 20,v_i[v_re[i].id - 1].hold, v_i[v_re[i].id - 1].wait);      
//     }
//   }
// }

void clean_sanitize()
{
  for (int repeat = 1; repeat <3; repeat ++) //repeating sanitizing cycle
  {
    
      pump_select(1);
      pump_select(2);
      pump_select(3);
      pump_select(4);
      pump_select(5);
      pump_select(7);
      
      delay(20000); //for cleaning 20s
      pump_close(1);
      pump_close(2);
      pump_close(3);
      pump_close(4);
      pump_close(5);
      pump_close(7);
      delay(1000); //take a rest
    
  }
}
  

void clean_rise()
{
  for (int repeat = 1; repeat <5; repeat ++) //repeating rising cycle
  {
    for (int i = 1; i < 9; i+4)
    {
      pump_select(i);
      pump_select(i+1);
      pump_select(i+2);
      pump_select(i+3);
      delay(30000); //for cleaning 30s
      pump_close(i);
      pump_close(i+1);
      pump_close(i+2);
      pump_close(i+3);
      delay(1000); //take a rest
    }
  }

}


void test_pump()
{
  for (int i = 1; i < 9; i++)
  {
    Serial.println(i);
    pump_select(i);
    delay(2000);
    pump_close(i);
    delay(2000);
  }
}

String read_data()
{

  char data;
  String s;
  File myFile;
  
  myFile = SD.open("data.txt");
  
  if (myFile) {
    
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      data = myFile.read();
      s += data;
      
      //Serial.write(data);
    }
    // close the file:
    myFile.close();
    return s;
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening data.txt");
  }
} //end read_data


void setup() {
  pump_init();
  //button_init();
  initAllpins();
  initAllbutton();
  serial_init();
  // mJson.Init_("INGRED~1.JSO","RECIPE~1.JSO");
  // v_re = mJson.listener_RECIPE.vi_recipe_item;
  // v_i  = mJson.listener_INGRED.vi;

  Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");

  Ethernet.begin(mac, ip);  // initialize Ethernet device
  pinMode(10, OUTPUT);

//  String abcd = "ajkls;dhglajshdglkhg;g";
//  myFile = SD.open("abcd.txt", FILE_WRITE);
//  
//  // if the file opened okay, write to it:
//  if (myFile) {
//    Serial.print("Writing to test.txt...");
//    myFile.println(abcd);
//  // close the file:
//    myFile.close();
//    Serial.println("done.");
//  } else {
//    // if the file didn't open, print an error:
//    Serial.println("error opening test.txt");
//  }


//clean_sanitize();
//test_pump();
//  pump_select(3);
//  delay(10000);
//  pump_close(3);

// pump_select(5);
// delay(30/v_yellow);
// pump_close(5);

        
      //get_RecipeData(16);


  
  
}

void loop() {
 EthernetClient client = server.available();  // try to get client

    if (client) 
    {  // got client?
        boolean currentLineIsBlank = true;
        while (client.connected()) {
            if (client.available()) {   // client data available to read
                char c = client.read();
                // read 1 byte (character) from client
                HTTP_req += c;
                //HTTP_req = HTTP_req.substring(0,40);// save the HTTP request 1 char at a time
                // last line of client request is blank and ends with \n
                // respond to client only after last line received
                if (c == '\n' && currentLineIsBlank) {
                    // send a standard http response header
                    client.println("HTTP/1.1 200 OK");
                    client.println("Content-Type: text/html");
                    client.println("Connection: close");
                    client.println();
                    // send web page
                    client.println("<!DOCTYPE html>");
                    client.println("<html>");
                    client.println("<body>");
                    client.println("");
                    client.println("<h1>Miss Dessert Drink Bot</h1>");
                    client.println("");
                    client.println("<form method=\"get\">");
                    client.println("  <p>Please select a drink:</p>");
                    client.println(" <input type=\"radio\" id=\"mt\" name=\"tea\" value=\"1\">");
                    client.println("  <label for=\"male\">MilkTea</label>");
                    client.println("  <input type=\"radio\" id=\"bsl\" name=\"tea\" value=\"2\">");
                    client.println("  <label for=\"bsl\">Brown sugar latte</label>");
                    client.println("  <input type=\"radio\" id=\"p/g\" name=\"tea\" value=\"3\">");
                    client.println("  <label for=\"p/g\">Peach/Grape</label>");
                    client.println("  <input type=\"radio\" id=\"ft/of\" name=\"tea\" value=\"4\">");
                    client.println("  <label for=\"ft/of\">Fruit Tea/Orange Fantacy</label>");
                    client.println("  <input type=\"radio\" id=\"gf\" name=\"tea\" value=\"5\">");
                    client.println("  <label for=\"gf\">Grape fruit fantacy</label>");
                    client.println("  <input type=\"radio\" id=\"cwpo\" name=\"tea\" value=\"6\">");
                    client.println("  <label for=\"cwpo\">Cheese White Peach Oolong</label>");
                    client.println("  <input type=\"radio\" id=\"cgt\" name=\"tea\" value=\"7\">");
                    client.println("  <label for=\"cgt\">Chesse Green Tea</label>");
                    client.println(" ");
                    client.println("");
                    client.println("  <br>  ");
                    client.println("");
                    client.println("  <p>Please select your sugar level:</p>");
                    client.println("  <input type=\"radio\" id=\"s100\" name=\"sugar\" value=\"100\">");
                    client.println("  <label for=\"s100\">100%</label>");
                    client.println("  <input type=\"radio\" id=\"s75\" name=\"sugar\" value=\"75\">");
                    client.println("  <label for=\"s75\">75%</label> ");
                    client.println("  <input type=\"radio\" id=\"s50\" name=\"sugar\" value=\"50\">");
                    client.println("  <label for=\"s50\">50%</label>");
                    client.println("  <input type=\"radio\" id=\"s25\" name=\"sugar\" value=\"25\">");
                    client.println("  <label for=\"s50\">25%</label>");
                    client.println("");
                    client.println("  <br>");
                    client.println("");
                    client.println("  <p>Please select your ice level:</p>");
                    client.println("  <input type=\"radio\" id=\"i100\" name=\"ice\" value=\"100\">");
                    client.println("  <label for=\"i100\">100%</label>");
                    client.println("  <input type=\"radio\" id=\"i75\" name=\"ice\" value=\"75\">");
                    client.println("  <label for=\"i75\">75%</label> ");
                    client.println("  <input type=\"radio\" id=\"i50\" name=\"ice\" value=\"50\">");
                    client.println("  <label for=\"i50\">50%</label>");
                    client.println("  <input type=\"radio\" id=\"i25\" name=\"ice\" value=\"25\">");
                    client.println("  <label for=\"i25\">25%</label>");
                    client.println("  <input type=\"radio\" id=\"i0\" name=\"ice\" value=\"0\">");
                    client.println("  <label for=\"i0\">0%</label>");
                    client.println("  ");
                    client.println("  <br>");
                    client.println("  <br>");
                    client.println("  <br>");
                    client.println("");
                    client.println("  <input type=\"submit\" value=\"Submit\">");
                    client.println("</form>");
                    client.println("");
                    client.println("</body>");
                    client.println("</html>");

 
                    Serial.println(HTTP_req);

                    Serial.println("Removing data.txt...");
                    SD.remove("data.txt");

                    int t = tea_select_web();
                    int s = sugar_select_web();
                    int i = ice_select_web();

                    Serial.print("which tea is selected = ");
                    Serial.println(t);
                    Serial.print("which sugar is select = ");
                    Serial.println(s);
                    Serial.print("which ice is select = ");
                    Serial.println(i);

                    //File myFile;
                      
//                      Serial.println("Removing data.txt...");
//                      SD.remove("data.txt");
                    
                      myFile = SD.open("data.txt", FILE_WRITE);
                      
                      // if the file opened okay, write to it:
                      if (myFile) {
                        Serial.print("Writing to test.txt...");
                        myFile.println(HTTP_req);
                      // close the file:
                        myFile.close();
                        Serial.println("done.");
                      } else {
                        // if the file didn't open, print an error:
                        Serial.println("error opening test.txt");
                      }
                    

                    

                    HTTP_req = "";    // finished with request, empty string
                    break;
                    
                }
                // every line of text received from the client ends with \r\n
                if (c == '\n') {
                    // last character on line of received text
                    // starting new line with next character read
                    currentLineIsBlank = true;
                } 
                else if (c != '\r') {
                    // a text character was received from client
                    currentLineIsBlank = false;
                }
            } // end if (client.available())
        } // end while (client.connected())
        delay(1);      // give the web browser time to receive the data
        client.stop(); // close the connection

        
    } // end if (client)

     aaa = read_data().substring(0,40);
    
    int t = tea_select_web();
    int s = sugar_select_web();
    int i = ice_select_web();
    int button_state = get_button_state(t, i, s);

    if (button_state != 9999)
    {
      Serial.print("button_state is :");
      Serial.println(button_state);
      ttt = timer_start();
      recipe(button_state, ttt);
      
      Serial.println("Removing data.txt...");
      SD.remove("data.txt");
      //Serial.println(timer_start());
    }
    

  if (digitalRead(23) == LOW)
  {
    pump_select(1);
  }
  if (digitalRead(23) == HIGH)
  {
    pump_close(1);
  }

  if (digitalRead(25) == LOW)
  {
    pump_select(2);
  }
  if (digitalRead(25) == HIGH)
  {
    pump_close(2);
  }

  if (digitalRead(27) == LOW)
  {
    pump_select(3);
  }
  if (digitalRead(27) == HIGH)
  {
    pump_close(3);
  }

  if (digitalRead(29) == LOW)
  {
    pump_select(4);
  }
  if (digitalRead(29) == HIGH)
  {
    pump_close(4);
  }

  if (digitalRead(31) == LOW)
  {
    pump_select(5);
  }
  if (digitalRead(31) == HIGH)
  {
    pump_close(5);
  }

  if (digitalRead(33) == LOW)
  {
    pump_select(6);
  }
  if (digitalRead(33) == HIGH)
  {
    pump_close(6);
  }

  

   //Serial.println(button_state);
//    recipe(button_state);
//    
//    Serial.println(t);

    
          
//  myFile = SD.open("buttonstate.txt");
// String  http; 
// http = myFile.read();
//  Serial.println(http);



   //dstring += data;
//   teadata = dstring.substring(0,40);
   //Serial.write(data);
   

  // last_row = dstring.substring(dstring.length()-41,dstring.length());
  // Serial.println(last_row);
}
