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

		PatternGenerator patternGenerator;
		PatternProjectAndCapture patternProjectAndCapture;
		SystemCalibrator systemCalibrator;
		PhaseWrapper phaseWrapper;
		PhaseUnwrapper phaseUnwrapper;
		CorrespondenceEstimator correspondenceEstimator;
		Triangulator triangulator;
		PointCloudExporter pointCloudExporter;

};




