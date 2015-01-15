// executes 3D scanning pipeline
#include "PhaseShiftSturcturedLight3DScanner.h"
#include "ReadScannerConfiguration.h"
#include "SystemCalibration.h"
#include "GeneratePatterns.h"
#include "ProjectAndCapturePatterns.h"
#include "ComputeWrappedPhase.h"
#include "ComputeUnwrapPhase.h"
#include "ComputeCorrespondence.h"
#include "Triangulate.h"
#include "SavePointCloud.h"



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
