 # include <stdio.h>
 # include <math.h>
 # define STB_IMAGE_IMPLEMENTATION
 # include "C:\Users\Dang Trinh\Documents\!VGU\Year_2\Programming_1\Subtraction_image\Headers\stb_image.h.txt" 
 # define STB_IMAGE_WRITE_IMPLEMENTATION
 # include "C:\Users\Dang Trinh\Documents\!VGU\Year_2\Programming_1\Subtraction_image\Headers\stb_image_write.h.txt" 
 
 unsigned char subtraction_background( unsigned char * image1 , unsigned char * image2, unsigned char * image3, int width , int height , int channel) {
 for (int i = 0; i < height ; i ++) {
   for (int j = 0; j < width ; j ++)  {
      int dif = 0;
     for (int k = 0; k < channel ; k ++) {
       dif += abs(image1 [ i * width * channel + j * channel + k ] -  image2 [ i * width * channel + j * channel + k ]);
        // image2 [ i * width * channel + j * channel + k ] = image3 [ i * width * channel + j * channel + k ];
         }
         if(dif < 160) {
          for(int k = 0; k < channel ; k++) {
            image2 [ i * width * channel + j * channel + k ] = image3 [ i * width * channel + j * channel + k ];
          }
         }
       }
     }
   }
 


 int main () {
 // declare variables
 int width , height , channel ;
 char path_img1 [] = "./Images/background.png";
 char path_img2 [] = "./Images/foreground.png";
 char path_img3 [] = "./Images/weather_forecast.png";
 char save_path [] = "./Images/weather_forecast-New.png";

 // read image data
 unsigned char * image1 = stbi_load ( path_img1 , & width , & height , & channel , 0) ;
 if ( image1 == NULL )
 {
 printf ("\nError in loading the image \n") ;
 exit (1) ;
 }
 printf(" Width = %d\nHeight = %d\nChannel = %d\n", width , height , channel ) ;


unsigned char * image2 = stbi_load ( path_img2 , & width , & height , & channel , 0) ;
  if ( image1 == NULL )
 {
 printf ("\nError in loading the image \n") ;
 exit (1) ;
 }
 printf(" Width = %d\nHeight = %d\nChannel = %d\n", width , height , channel ) ;


unsigned char * image3 = stbi_load ( path_img3 , & width , & height , & channel , 0) ;
 if ( image1 == NULL )
 {
 printf ("\nError in loading the image \n") ;
 exit (1) ;
 }
 printf(" Width = %d\nHeight = %d\nChannel = %d\n", width , height , channel ) ;


 // fill image with black pixels
 subtraction_background ( image1 , image2, image3, width , height , channel ) ;

// save image
 //stbi_write_png ( save_path , width , height , channel , image1 , width * channel ) ;
 stbi_write_png ( save_path , width , height , channel , image2 , width * channel ) ;
 //stbi_write_png ( save_path , width , height , channel , image3 , width * channel ) ;
 printf (" New image saved to %s\n", save_path ) ;
 }