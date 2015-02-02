// executes 3D scanning pipeline
#include "PhaseShiftSturcturedLight3DScanner.h"


void scanObject()
{
	readScannerConfiguration();
	systemCalibration();
	generatePatterns();
	projectAndCapturePatterns();
	computeWrappedPhase();
	computeUnwrappedPhase();
	computeProjectorCameraCorrespondence();
	triangulate();
	savePointCloud();

	return;
}
