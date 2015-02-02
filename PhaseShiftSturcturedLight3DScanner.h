#include "ReadScannerConfiguration.h"
#include "SystemCalibration.h"
#include "GeneratePatterns.h"
#include "ProjectAndCapturePatterns.h"
#include "ComputeWrappedPhase.h"
#include "ComputeUnwrapPhase.h"
#include "ComputeCorrespondence.h"
#include "Triangulate.h"
#include "SavePointCloud.h"



#define PI (22.0/7.0)

using namespace std;

class PhaseShiftStructuredLight3DScanner
{
	public:
				
		void scanObject();

	private:
		
		unsigned int nFringePatterns;
		unsigned int nGrayCodedPatternsVertical;
		unsigned int nGrayCodedPatternsHorizontal;
		unsigned int nGrayCodesVertical;
		unsigned int nGrayCodesHorizontal;
		unsigned int fringeWidthVertical;
		unsigned int fringeWidthHorizontal;
		unsigned int triangulationMethod;
		unsigned int projectorImageWidth;
		unsigned int projectorImageHeight;
		unsigned int cameraImageWidth;
		unsigned int cameraImageHeight;
		
		float projectorGamma;
		float projectorBrightness;
		float cameraGamma;
		float cameraBrightness;
		float projectorFocus;
		float cameraFocus;

		CvMat *cameraIntrinsics;
		CvMat *cameraExtrinsics;
		CvMat *projectorIntrinsics;
		CvMat *projectorExtrinsics;
		
		IplImage *projectedFringePatternsVertical;
		IplImage *projectedFringePatternsHorizontal;

		IplImage *projectedGrayCodedPatternsVertical;
		IplImage *projectedGrayCodedPatternsHorizontal;

		IplImage *capturedFringePatternsVertical;
		IplImage *capturedFringePatternsHorizontal;

		IplImage *capturedGrayCodedPatternsVertical;
		IplImage *capturedGrayCodedPatternsHorizontal;			

		float **wrappedPhaseVertical;
		float **wrappedPhaseHorizontal;

		float **unwrappedPhaseVertical;
		float **unwrappedPhaseHorizontal;
		
		map<cameraPixel, projectorPixel>cameraProjectorMap;		

		float ***pointCloud;
	public:

		// member functions

		void readScannerConfiguration(); // reads required pattern design, point-cloud output location, calibration file locations 
		void systemCalibration();
		void generatePatterns();
		void projectAndCapturePatterns();
		void computeWrappedPhase();
		void computeUnwrappedPhase();
		void computeProjectorCameraCorrespondence();
		void triangulate();
		void savePointCloud();

		// member functions responsible for adapting 3D scanner configuration
		void estimateRadiometricParameters(); // sets projectorGamma, projectorBrightness, cameraBrightness, cameraGamma

};




