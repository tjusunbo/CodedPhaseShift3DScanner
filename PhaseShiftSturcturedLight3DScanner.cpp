void scanObject()
{




readScannerConfiguration();
 
systemCalibration();
generatePatterns();
projectAndCapturePatterns();
computeWrappedPhase();
computeUnwrappedPhase();
computeProjectorCameraCorrespondence();
        23         3dscanner.triangulate();
	 24         3dScanner.savePointCloud();

