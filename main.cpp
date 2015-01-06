/*
 * Control application for 3D scanner
 */
#include "PhaseShiftSturcturedLight3DScanner.h"



int main()
{
	PhaseShiftStructuredLight3DScanner 3dScanner;

	// configure 3D scanner using parameters obtained 
		// either from XML file
		// or, using direct initialization via interactive GUI 
	3dScanner.readScannerConfiguration();

	3dScanner.systemCalibration();
	3dScanner.generatePatterns();
	3dScanner.projectAndCapturePatterns();
	3dScanner.computeWrappedPhase();
	3dScanner.computeUnwrappedPhase();
	3dScanner.computeProjectorCameraCorrespondence();
	3dscanner.triangulate();
	3dScanner.savePointCloud();


	3dScanner.scanObject();
	return 0;
}
