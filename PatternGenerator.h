// File inclusions
#include <vector>
#include <string>
#include <sstream>
#include <opencv2/highgui.hpp>
#include <opencv2/core/core.hpp>

// Constants
#define Pi (22.0 / 7.0)



class PatternGenerator
{

	public:
		generatePatterns();


	private:
		unsigned int nFringePatterns;
		unsigned int nGrayCodedPatternsVertical;
		unsigned int nGrayCodedPatternsHorizontal;
		unsigned int nGrayCodesVertical;
		unsigned int nGrayCodesHorizontal;
		unsigned int fringeWidthVertical;
		unsigned int fringeWidthHorizontal;	
		vector<IplImage*> generatedFringePatternsVertical;
		vector<IplImage*> generatedFringePatternsHorizontal;
		vector<IplImage*> generatedGrayCodedPatternsVertical;	
		vector<IplImage*> generatedGrayCodedPatternsHorizontal;
		vector<IplImage*> generatedInverseGrayCodedPatternsVertical;
		vector<IplImage*> generatedInverseGrayCodedPatternsHorizontal;
		initialize();
};
