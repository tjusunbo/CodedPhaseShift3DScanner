#include "PatternGenerator.h" 

using namespace cv;
using namespace std;

vector<IplImage*> projectedFringePatternsVertical;
vector<IplImage*> projectedFringePatternsHorizontal;

extern string configFileName;

void PatternGenenerator::initialize()
{
	FileStorage configFile(configFileName, FileStorage::READ);

	configFile["Fringe width(vertical)"] >> fringeWidthVertical;
	configFile["Fringe width(horizontal)"] >> fringeWidthHorizontal;
  	configFile["Number of fringe patterns"] >> nFringePatterns;

	configFile.release();

    	for (unsigned int fringePatternId = 0; fringePatternId < nFringePatterns; fringePatternId++)
    	{
        	projectedFringePatternsVertical.push_back(cvCreateImage(cvSize(projectorImageWidth, projectorImageHeight), IPL_DEPTH_8U, 1));
        	projectedFringePatternsHorizontal.push_back(cvCreateImage(cvSize(projectorImageWidth, projectorImageHeight), IPL_DEPTH_8U, 1));
    	}
   
   	nGrayCodesVertical = (int)ceil((float)projectorImageWidth / (float)fringeWidthVertical);
	nGrayCodedPatternsVertical = (int)ceil((logf((float)nGrayCodesVertical) / logf(2.0)));

    	nGrayCodesHorizontal = (int)ceil((float)projectorImageHeight / (float)fringeWidthHorizontal);
    	nGrayCodedPatternsHorizontal = (int)ceil((logf((float)nGrayCodesHorizontal) / logf(2.0)));

   	for (unsigned int verticalGrayCodedPatternId = 0; verticalGrayCodedPatternId < nGrayCodesVertical + 1; verticalGrayCodedPatternId++)
    	{ 
               	projectedGrayCodedPatternsVertical.push_back(cvCreateImage(cvSize(projectorImageWidth,projectorImageHeight),IPL_DEPTH_8U,1));
        	projectedInverseGrayCodedPatternsVertical.push_back(cvCreateImage(cvSize(projectorImageWidth,projectorImageHeight),IPL_DEPTH_8U,1));
    	}

    	for (unsigned int horizontalGrayCodedPatternId = 0; horizontalGrayCodedPatternId < nGrayCodesHorizontal + 1; horizontalGrayCodedPatternId++)
    	{
       	        projectedGrayCodedPatternsHorizontal.push_back(cvCreateImage(cvSize(projectorImageWidth,projectorImageHeight),IPL_DEPTH_8U,1));
        	projectedInverseGrayCodedPatternsHorizontal.push_back(cvCreateImage(cvSize(projectorImageWidth,projectorImageHeight),IPL_DEPTH_8U,1));
    	}

    	return;
}


//I1=Imod+Idc*(cos(phi-2pi/3))
//I2=Imod+Idc*(cos(phi))
//I3=Imod+Idc*(cos(phi+2pi/3))

void PatternGenenerator::generateFringePatterns()
{

	float t = 0.0;

	// vertical patterns	
	for (unsigned int patternId = 0; patternId < nFringePatterns; patternId++)
        	for (unsigned int row = 0; row < projectorImageHeight; row++)
            		for (unsigned int col = 0; col < projectorImageWidth; col++)
            		{
                		t = 127.0f + 128.0f * cosf(((float)col / (float)fringeWidthVertical) * 2.0 * Pi - Pi - ((Pi) / 2.0) + (Pi / 2.0) * (float)patternId);
                		projectedFringePatternsVertical[patternId]->imageData[row * projectedFringePatternsVertical[patternId]->widthStep + col] = (unsigned char)t;
            		}


	// horizontal patterns
    	for (unsigned int patternId = 0; patternId < nFringePatterns; patternId++)
        	for(unsigned int col = 0; col < projectorImageWidth; col++)
            		for(unsigned int row = 0; row < projectorImageHeight; row++)
            		{
                		t = 127.0f + 128.0f * cosf(((float)row / (float)fringeWidthHorizontal) * 2.0 * Pi - Pi - ((Pi) / 2.0) + (Pi / 2.0) * (float)patternId);
                		projectedFringePatternsHorizontal[patternId]->imageData[row * projectedFringePatternsHorizontal[patternId]->widthStep + col] = (unsigned char)t;
            		}

    return;
}



void PatternGenenerator::generateGrayCodedPatterns()
{

	/// Convert binary to gray
    	bool **B[1];
    	bool **G[1];


    	for (unsigned int n = 0; n < 1; n++)
    	{
        	B[n] = new bool *[nGrayCodesVertical];
        	G[n] = new bool *[nGrayCodesVertical];

        	for (unsigned int k = 0; k < nGrayCodesVertical; k++)
        	{
            		B[n][k] = new bool[nGrayCodedPatternsVertical];
            		G[n][k] = new bool[nGrayCodedPatternsVertical];
        	}
    	}

    	for (unsigned int n = 0,temp = 0; n < nGrayCodesVertical; n++)
    	{
        	temp = n;
        	
		for (unsigned int i = nGrayCodedPatternsVertical - 1; i >= 0; i--)      
   		{
            		B[0][n][i] = (temp % 2) ? 1 : 0;
            		temp /= 2;
        	}
        	
		for (unsigned int i = 0; i < nGrayCodedPatternsVertical; i++)
        	{
            		if(i == 0)
                		G[0][n][i] = B[0][n][i];
            		else
                		G[0][n][i] = (B[0][n][i-1] != B[0][n][i]) ? 1 : 0;        	
		}
    	}

      	unsigned int codeNumber;

    	for (unsigned int n = 0; n < nGrayCodedPatternsVertical; n++)
    	{
        	for (unsigned int r = 0; r < projectorImageHeight; r++)
        	{
            		codeNumber = 0;
            		for (unsigned int c = 0; c < projectorImageWidth; c += fringeWidthVertical)
            		{
                		for (unsigned int offset = 0; (offset < fringeWidthVertical) && ((c + offset) < projectorImageWidth); offset++)
                			projectedGrayCodedPatternsVertical[n]->imageData[r * projectedGrayCodedPatternsVertical[n]->widthStep + (c + offset)] = G[0][codeNumber][n] * 255;
                
                	codeNumber++;
            		}
        	}
    	}



	/// Horizontal patterns
    	for (unsigned int n = 0; n < 1; n++)
    	{
        	B[n] = new bool *[nGrayCodesHorizontal];
        	G[n] = new bool *[nGrayCodesHorizontal];

        	for (unsigned int k = 0; k < nGrayCodesHorizontal; k++)
        	{
            		B[n][k] = new bool[nGrayCodedPatternsHorizontal];
            		G[n][k] = new bool[nGrayCodedPatternsHorizontal];
        	}
    	}

    	for (unsigned int n = 0, temp = 0; n < nGrayCodesHorizontal; n++)
    	{
        	temp = n;

        	for (unsigned int i=0; i < nGrayCodedPatternsHorizontal; i++) 
        	{
            		B[0][n][nGrayCodedPatternsHorizontal - 1 - i] = (temp % 2) ? 1 : 0;
            		temp /= 2;
        	}
                
		for (unsigned int i = 0; i < nGrayCodedPatternsHorizontal; i++)
        	{
            		if (i == 0)
                		G[0][n][i] = B[0][n][i];
            		else
                		G[0][n][i] = (B[0][n][i-1] != B[0][n][i]) ? 1 : 0;        	
		}
    	}



       	for (unsigned int n = 0; n <nGrayCodedPatternsHorizontal; n++)
    	{
        	for (unsigned int c = 0; c < projectorImageWidth; c++)
        	{
            		codeNumber=0;

		        for (unsigned int r = 0; r < projectorImageHeight; r += fringeWidthHorizontal)
            		{
                		for (unsigned int offset = 0; (offset < fringeWidthHorizontal) && ((r + offset) < projectorImageHeight); offset++)
                    			projectedGrayCodedPatternsHorizontal[n]->imageData[(r+offset) * projectedGrayCodedPatternsHorizontal[n]->widthStep+c] = G[0][codeNumber][n] * 255;

                		codeNumber++;
            		}
        	}

    	}

	return;
}



void PatternGenenerator::generateInverseGrayCodedPatterns()
{

	/// Vertical
    	for (unsigned int i = 0; i < nGrayCodedPatternsVertical; i++)
      		for (unsigned int r = 0; r < projectorImageHeight; r++)
		        for (unsigned int c = 0; c < projectorImageWidth; c++)
				projectedInverseGrayCodedPatternsVertical[i]->imageData[r * projectedInverseGrayCodedPatternsVertical[i]->widthStep + c] = 255 - (unsigned char)(projectedInverseGrayCodedPatternsVertical[i]->imageData[r * projectedInverseGrayCodedPatternsVertical[i]->widthStep + c]);

	/// Horizontal
   	for (unsigned int i = 0; i < nGrayCodedPatternsHorizontal; i++)
      		for (unsigned int r = 0; r < projectorImageHeight; r++)
        		for (unsigned c = 0; c < projectorImageWidth; c++)
           			projectedInverseGrayCodedPatternsHorizontal[i]->imageData[r * projectedInverseGrayCodedPatternsHorizontal[i]->widthStep + c] = 255 - (unsigned char)(projectedInverseGrayCodedPatternsHorizontal[i]->imageData[r * projectedInverseGrayCodedPatternsHorizontal[i]->widthStep + c]);


    return;
}



//Following function saves the generated patterns.
void PatternGenenerator::savePatternImages()
{
        ostringstream outputDir;
	string rootOutputDir;

	configFile["Output directory"] >> rootOutputDir;

	// Fringe patterns
	
    	for (unsigned int i = 0; i < nFringePatterns; i++)
    	{
		outputDir << rootOutputDir << "/FringePatterns/Vertical/Pattern" << i << ".bmp";
        	imwrite(outputDir, projectedFringePatternsVertical[i]);
		outputDir << rootOutputDir << "/Fringe_patterns/Horizontal/Pattern" << i << ".bmp";
        	imwrite(outputDir, projectedFringePatternsHorizontal[j]);
	}
    	
  	// Gray coded patterns
    
    	for (unsigned int j = 0; j < nGrayCodedPatternsVertical + 1; j++)
    	{
        	outputDir << rootOutputDir << "/CodedPatterns/GrayCoded/Vertical/Pattern" << j << ".bmp";
        	imwrite(outputDir, projectedGrayCodedPatternsVertical[j]);
       	
        	outputDir << rootOutputDir << "/CodedPatterns/GrayCoded/Vertical/InversePattern" << j << ".bmp";
        	imwrite(outputDir, projectedInverseGrayCodedPatternsVertical[j]);
    	}

    
    	for (unsigned int j = 0; j < nGrayCodedPatternsHorizontal + 1; j++)
    	{
       		outputDir << rootOutputDir << "/CodedPatterns/GrayCoded/Horizontal/Pattern" << j << ".bmp";
        	imwrite(outputDir, projectedGrayCodedPatternsHorizontal[j]);
       	
        	outputDir << rootOutputDir << "/CodedPatterns/GrayCoded/Horizontal/InversePattern" << j << ".bmp";
        	imwrite(outputDir, projectedInverseGrayCodedPatternsHorizontal[j]);
    	}

    	return;
}


void PatternGenenerator::generatePatterns()
{

	initialize();
	generateFringePatterns();
	generateGrayCodedPatterns();
	generateInverseGrayCodedPatterns();
	savePatternImages();

	return;
}
