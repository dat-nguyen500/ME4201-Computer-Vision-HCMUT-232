#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;
bool use_mask;
Mat img; Mat templ; Mat mask; Mat result;
const char* image_window = "Source Image";
const char* result_window = "Result window";
int match_method;
int max_Trackbar = 5;
void MatchingMethod( int, void* );
const char* keys =
"{ help  h| | Print help message. }"
"{ @input1 | Template_Matching_Original_Image.jpg | image_name }"
"{ @input2 | Template_Matching_Template_Image.jpg | template_name }"
"{ @input3 |  | mask_name }";
int main( int argc, char** argv )
{
  CommandLineParser parser( argc, argv, keys );
  samples::addSamplesDataSearchSubDirectory( "doc/tutorials/imgproc/histograms/template_matching/images" );
  img = imread( samples::findFile( parser.get<String>("@input1") ) );
  templ = imread( samples::findFile( parser.get<String>("@input2") ), IMREAD_COLOR );
  if(argc > 3) {
    use_mask = true;
    mask = imread(samples::findFile( parser.get<String>("@input3") ), IMREAD_COLOR );
  }
  if(img.empty() || templ.empty() || (use_mask && mask.empty()))
  {
    cout << "Can't read one of the images" << endl;
    return EXIT_FAILURE;
  }
  namedWindow( image_window, WINDOW_AUTOSIZE );
  namedWindow( result_window, WINDOW_AUTOSIZE );
  const char* trackbar_label = "Method: \n 0: SQDIFF \n 1: SQDIFF NORMED \n 2: TM CCORR \n 3: TM CCORR NORMED \n 4: TM COEFF \n 5: TM COEFF NORMED";
  createTrackbar( trackbar_label, image_window, &match_method, max_Trackbar, MatchingMethod );
  MatchingMethod( 0, 0 );
  waitKey(0);
  return EXIT_SUCCESS;
}
void MatchingMethod( int, void* )
{
  Mat img_display;
  img.copyTo( img_display );
  int result_cols = img.cols - templ.cols + 1;
  int result_rows = img.rows - templ.rows + 1;
  result.create( result_rows, result_cols, CV_32FC1 );
  bool method_accepts_mask = (TM_SQDIFF == match_method || match_method == TM_CCORR_NORMED);
  if (use_mask && method_accepts_mask)
    { matchTemplate( img, templ, result, match_method, mask); }
  else
    { matchTemplate( img, templ, result, match_method); }
  normalize( result, result, 0, 1, NORM_MINMAX, -1, Mat() );
  double minVal; double maxVal; Point minLoc; Point maxLoc;
  Point matchLoc;
  minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );
  if( match_method  == TM_SQDIFF || match_method == TM_SQDIFF_NORMED )
    { matchLoc = minLoc; }
  else
    { matchLoc = maxLoc; }
  rectangle( img_display, matchLoc, Point( matchLoc.x + templ.cols , matchLoc.y + templ.rows ), Scalar::all(0), 2, 8, 0 );
  rectangle( result, matchLoc, Point( matchLoc.x + templ.cols , matchLoc.y + templ.rows ), Scalar::all(0), 2, 8, 0 );
  imshow( image_window, img_display );
  imshow( result_window, result );
  return;
}