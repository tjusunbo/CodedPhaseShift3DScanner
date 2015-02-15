#include "PatternProjectAndCapture.h"


void initialize()
{

    projectedFringePatternsVertical = new IplImage * [nFringePatterns];

//Vertical.
    if(pattern_type==0)
    {
        projected_image_set_binary=new IplImage*[number_of_patterns_binary_vertical+1];
        projected_image_set_gray=new IplImage*[number_of_patterns_binary_vertical+1];
        projected_image_set_gray_inverse=new IplImage*[number_of_patterns_binary_vertical+1];

        // Vertical fringe patterns...
        for(int i=0; i<number_of_patterns_fringe; i++)
        {
            sprintf(filename,"Generated_patterns/Fringe_patterns/Vertical/Pattern_%d.bmp",i);
            projected_image_set_fringe[i]=cvLoadImage(filename,CV_LOAD_IMAGE_GRAYSCALE);
        }

        //Vertical binary coded patterns...
        for(int k=0; k<number_of_patterns_binary_vertical+1; k++)
        {

            sprintf(filename,"Generated_patterns/Coded_patterns/Binary_coded/Vertical/Pattern_%d.bmp",k);
            projected_image_set_binary[k]=cvLoadImage(filename,CV_LOAD_IMAGE_GRAYSCALE);
        }

        //Vertical gray coded patterns...
        for(int k=0; k<number_of_patterns_binary_vertical+1; k++)
        {

            sprintf(filename,"Generated_patterns/Coded_patterns/Gray_coded/Vertical/Pattern_%d.bmp",k);
            projected_image_set_gray[k]=cvLoadImage(filename,CV_LOAD_IMAGE_GRAYSCALE);

            sprintf(filename,"Generated_patterns/Coded_patterns/Gray_coded/Vertical/inverse_Pattern_%d.bmp",k);
            projected_image_set_gray_inverse[k]=cvLoadImage(filename,CV_LOAD_IMAGE_GRAYSCALE);



        }

    }


//Horizontal.
    if(pattern_type==1)
    {
        projected_image_set_binary=new IplImage*[number_of_patterns_binary_horizontal+1];
        projected_image_set_gray=new IplImage*[number_of_patterns_binary_horizontal+1];


        // Horizontal fringe patterns...
        for(int j=0; j<number_of_patterns_fringe; j++)
        {

            sprintf(filename,"Generated_patterns/Fringe_patterns/Horizontal/Pattern_%d.bmp",j);
            projected_image_set_fringe[j]=cvLoadImage(filename,CV_LOAD_IMAGE_GRAYSCALE);
        }

        // Horizontal binary coded patterns...
        for(int l=0; l<number_of_patterns_binary_horizontal+1; l++)
        {

            sprintf(filename,"Generated_patterns/Coded_patterns/Binary_coded/Horizontal/Pattern_%d.bmp",l);
            projected_image_set_binary[l]=cvLoadImage(filename,CV_LOAD_IMAGE_GRAYSCALE);

        }

        // Horizontal gray coded patterns...
        for(int l=0; l<number_of_patterns_binary_horizontal+1; l++)
        {
            sprintf(filename,"Generated_patterns/Coded_patterns/Gray_coded/Horizontal/Pattern_%d.bmp",l);
            projected_image_set_gray[l]=cvLoadImage(filename,CV_LOAD_IMAGE_GRAYSCALE);

            sprintf(filename,"Generated_patterns/Coded_patterns/Gray_coded/Horizontal/inverse_Pattern_%d.bmp",l);
            projected_image_set_gray_inverse[l]=cvLoadImage(filename,CV_LOAD_IMAGE_GRAYSCALE);
        }

    }


    return;
}



//This function will project the pattern using projector.
void project_pattern(int pattern_type)
{

    char pattern_name[15];

    //cap=cvQueryFrame(camera);//null frame.(CORRECT THIS FUNCTION:PENDING ASSIGNMENT!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!)


    //i want live preview & capture.
    bool capture_next=false;

    IplImage*temp_proj_pattern=cvCreateImage(cvSize(Projector_imagewidth,Projector_imageheight),8,1);

    IplImage*undist_cap=cvCreateImage(cvSize(Camera_imagewidth,Camera_imageheight),IPL_DEPTH_8U,3);

    if(pattern_type==0)
        sprintf(pattern_name,"vertical");

    else
        sprintf(pattern_name,"horizontal");






    printf("\nProjecting %s phase shifted fringe patterns...\n",pattern_name);


    /// Project & capture fringe patterns...
    for(int i=0; i<number_of_patterns_fringe; i++)
    {
        cvUndistort2(projected_image_set_fringe[i],temp_proj_pattern,proj_intrinsic_mat,proj_dist_vect);

        //while(capture_next!=true)
        // {
        cvScale(projected_image_set_fringe[i], projected_image_set_fringe[i], 2.*(proj_gain/100.), 0);
        cvShowImage("Projector_pattern",projected_image_set_fringe[i]);
        cvCopyImage(temp_proj_pattern,projected_image_set_fringe[i]);//for next iteration.

        //cap=cvQueryFrame(camera);
        //mainloop(cap);
        preview_and_capture();
        //cvScale(cap, cap, 2.*(cam_gain/100.), 0);

        //cvShowImage("Camera_view",cap);

        //if(cvWaitKey(30)=='c')
        //{
        // capture_next=true;

        if(pattern_type==0)//vertical.
        {
            sprintf(filename,"Captured_patterns/Fringe_patterns/Vertical/Original/Captured_image_%d.bmp",i);

            //cap=camera_capture(filename);
            //cap=cvQueryFrame(camera);
            //mainloop(cap);
            //cvWaitKey(30);

            cvUndistort2(cap,undist_cap,cam_intrinsic_mat,cam_dist_vect);
            sprintf(filename,"Captured_patterns/Fringe_patterns/Vertical/Undistorted/Captured_image_%d.bmp",i);
            cvSaveImage(filename,undist_cap);

        }

        else //horizontal
        {
            sprintf(filename,"Captured_patterns/Fringe_patterns/Horizontal/Original/Captured_image_%d.bmp",i);
            //cap=camera_capture(filename);
            //cap=cvQueryFrame(camera);
            // mainloop(cap);
            cvUndistort2(cap,undist_cap,cam_intrinsic_mat,cam_dist_vect);
            sprintf(filename,"Captured_patterns/Fringe_patterns/Horizontal/Undistorted/Captured_image_%d.bmp",i);
            cvSaveImage(filename,undist_cap);
        }
        //  }


        //else
        //   capture_next=false;//try again user still not satisfied.
        // }

        //capture_next=false;//for the next loop.
        printf("\nCaptured %d of %d frame!!\n",i+1,number_of_patterns_fringe);
        cvReleaseImage(&cap);
    }



    /// Project & capture gray coded patterns...
    if(pattern_type==0)
    {
        for(int j=0; j<number_of_patterns_binary_vertical+1; j++)
        {
            ///Gray coded
            cvUndistort2(projected_image_set_gray[j],temp_proj_pattern,proj_intrinsic_mat,proj_dist_vect);

            cvScale(projected_image_set_gray[j], projected_image_set_gray[j], 2.*(proj_gain/100.), 0);
            cvShowImage("Projector_pattern",projected_image_set_gray[j]);
            cvCopyImage(temp_proj_pattern,projected_image_set_gray[j]);

            preview_and_capture();

            cvUndistort2(cap,undist_cap,cam_intrinsic_mat,cam_dist_vect);
            sprintf(filename,"Captured_patterns/Coded_patterns/Gray_coded/Vertical/Undistorted/Captured_image_%d.bmp",j);
            cvSaveImage(filename,undist_cap);

            ///Inverse gray coded
            cvUndistort2(projected_image_set_gray_inverse[j],temp_proj_pattern,proj_intrinsic_mat,proj_dist_vect);
            cvScale(projected_image_set_gray_inverse[j], projected_image_set_gray_inverse[j], 2.*(proj_gain/100.), 0);
            cvShowImage("Projector_pattern",projected_image_set_gray_inverse[j]);
            cvCopyImage(temp_proj_pattern,projected_image_set_gray_inverse[j]);

            preview_and_capture();

            cvUndistort2(cap,undist_cap,cam_intrinsic_mat,cam_dist_vect);
            sprintf(filename,"Captured_patterns/Coded_patterns/Gray_coded/Vertical/Undistorted/inverse_Captured_image_%d.bmp",j);
            cvSaveImage(filename,undist_cap);


            printf("\nCaptured %d of %d frame!!\n",j+1,number_of_patterns_binary_vertical);
            cvReleaseImage(&cap);
        }

    }


    if(pattern_type==1)
    {

        for(int j=0; j<number_of_patterns_binary_horizontal+1; j++)
        {
            ///Gray coded
            cvUndistort2(projected_image_set_gray[j],temp_proj_pattern,proj_intrinsic_mat,proj_dist_vect);

            cvScale(projected_image_set_gray[j], projected_image_set_gray[j], 2.*(proj_gain/100.), 0);
            cvShowImage("Projector_pattern",projected_image_set_gray[j]);
            cvCopyImage(temp_proj_pattern,projected_image_set_gray[j]);

            preview_and_capture();

            sprintf(filename,"Captured_patterns/Coded_patterns/Gray_coded/Horizontal/Original/Captured_image_%d.bmp",j);

            cvUndistort2(cap,undist_cap,cam_intrinsic_mat,cam_dist_vect);
            sprintf(filename,"Captured_patterns/Coded_patterns/Gray_coded/Horizontal/Undistorted/Captured_image_%d.bmp",j);
            cvSaveImage(filename,undist_cap);



            ///Inverse gray coded
            cvUndistort2(projected_image_set_gray_inverse[j],temp_proj_pattern,proj_intrinsic_mat,proj_dist_vect);

            cvScale(projected_image_set_gray_inverse[j], projected_image_set_gray_inverse[j], 2.*(proj_gain/100.), 0);
            cvShowImage("Projector_pattern",projected_image_set_gray_inverse[j]);
            cvCopyImage(temp_proj_pattern,projected_image_set_gray_inverse[j]);

            preview_and_capture();

            cvUndistort2(cap,undist_cap,cam_intrinsic_mat,cam_dist_vect);
            sprintf(filename,"Captured_patterns/Coded_patterns/Gray_coded/Horizontal/Undistorted/inverse_Captured_image_%d.bmp",j);
            cvSaveImage(filename,undist_cap);

            printf("\nCaptured %d of %d frame!!\n",j+1,number_of_patterns_binary_horizontal);
            cvReleaseImage(&cap);


        }

    }

    return;
}




void projectAndCapturePatterns()
{
    initialize();	    
    projectPattern();

    return;
}




