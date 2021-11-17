#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

#define SCALE 0.2
#define NUM 19
#define BINS 8

int main(int argc, char ** argv)
{
   string imgNames[NUM] = {"can(0).jpg","can(1).jpg","can(2).jpg","can(3).jpg","can(4).jpg","can(5).jpg","can(6).jpg","can(7).jpg","no(0).jpg","no(1).jpg","return(0).jpg","return(1).jpg","returnc(0).jpg","yes(0).jpg","yes(1).jpg","yes(2).jpg","yes(3).jpg","yes(4).jpg","yes(5).jpg"};
   
   Mat imgs[NUM];
   Mat imgsHLS[NUM];
   for(int i =0; i <NUM;++i)
   {
      imgs[i] = imread(imgNames[i], IMREAD_COLOR);
      if(imgs[i].data ==0)
      {
         cout << "Unable to read" << imgNames[i] <<endl;
         return 0;
      }
      cvtColor(imgs[i],imgsHLS[i],COLOR_BGR2HLS);
   }
   
   Mat histogram[NUM];
   
   int channal_numbers[] = {0,1,2};
   for(int i=0; i<NUM;++i)
   {
      int *number_bins =new int[imgsHLS[i].channels()];
      for(int ch =0; ch<imgsHLS[i].channels();ch++)
      {
         number_bins[ch] = BINS;
      }
      float ch_range[] = {0.0,255.0};
      const float *channel_ranges[] ={ch_range,ch_range,ch_range};
      calcHist(&imgsHLS[i], 1, channal_numbers,Mat(),histogram[i],imgsHLS[i].channels(),number_bins,channel_ranges);
      normalize(histogram[i],histogram[i],1.0);
   }
   cout << "Image Comparison by HISRCMP_CORREL" << endl;
   for(int i=0; i<NUM;i++)
   {
      for(int j=i+1;j<NUM;j++)
      {
         double matching_score = compareHist(histogram[i],histogram[j],HISTCMP_CORREL);
         
         cout << imgNames[i] << "-" << imgNames[j] <<", "<<matching_score<<endl;
      }
   }
   


   
   return 0;
}