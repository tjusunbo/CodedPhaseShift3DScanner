#include "GeneratePatterns.h"
#include "ProjectAndCapturePatterns.h"
#include "ComputeWrappedPhase.h"
#include "ComputeUnwrapPhase.h"
#include "SystemCalibration.h"
#include "ComputeCorrespondence.h"
#include "Triangulate.h"
#include "SavePointCloud.h"



#define PI (22.0/7.0)

using namespace std;

class PhaseShiftStructuredLight3DScanner
{
	public:
				
		size_t nFringePatterns;
		float fringeWidthVertical;
		float fringeWidthHorizontal;
		size_t nGrayCodesVertical;
		size_t nGrayCodesHorizontal;
		size_t nGrayCodePatternsVertical;
	        size_t nGrayCodePatternsHorizontal;

		float cameraImageWidth;
		float cameraImageHeight;
		float projectorImageWidth;
		float projectorImageHeight;

		

		void scanObject();
		PhaseShiftStructuredLight3DScanner() // default constructure
		{
			patternGenerator = NULL;
			patternProjectAndCapture = NULL;
			systemCalibrator = NULL;
			phaseWrapper = NULL;
			phaseUnwrapper = NULL;
			correspondenceEstimator = NULL;
			triangulator = NULL;
			pointCloudExporter = NULL;
		}
		void allocatePipelineMemory()
		{
			patternGenerator = new PatternGenerator;
			patternProjectAndCapture = new PatternProjectAndCapture;
			systemCalibrator = new SystemCalibrator;
			phaseWrapper = new phaseWrapper;
			phaseUnwrapper = new PhaseUnwrapper;
			correspondenceEstimator = new CorrespondenceEstimator;
			triangulator = new Triangulator;
			pointCloudExporter = new PointCloudExporter;
		}
		void initializeGlobalVariables()
		{
			configFile["outputDirectory"] >> outputDirectory;		
			configFile["nFringePatterns"] >> nFringePatterns;
			configFile["fringeWidthVertical"] >> fringeWidthVertical;
			configFile["fringeWidthHorizontal"] >> fringeWidthHorizontal;
			configFile["nGrayCodesVertical"] >> nGrayCodesVertical;
			configFile["nGrayCodesHorizontal"] >> nGrayCodesHorizontal;
			configFile["nGrayCodePatternsVertical"] >> nGrayCodePatternsVertical;
			configFile["nGrayCodePatternsHorizontal"] >> nGrayCodePatternsHorizontal;
			configFile["cameraImageWidth"] >> cameraImageWidth;
			configFile["cameraImageHeight"] >> cameraImageHeight;
			configFile["projectorImageWidth"] >> projectorImageWidth;
			configFile["projectorImageHeight"] >> projectorImageHeight;
		}

	private:

		PatternGenerator patternGenerator;
		PatternProjectAndCapture patternProjectAndCapture;
		SystemCalibrator systemCalibrator;
		PhaseWrapper phaseWrapper;
		PhaseUnwrapper phaseUnwrapper;
		CorrespondenceEstimator correspondenceEstimator;
		Triangulator triangulator;
		PointCloudExporter pointCloudExporter;
};

